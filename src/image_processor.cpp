/*
 * COPYRIGHT AND PERMISSION NOTICE
 * Penn Software MSCKF_VIO
 * Copyright (C) 2017 The Trustees of the University of Pennsylvania
 * All rights reserved.
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <Eigen/Dense>

#include <sensor_msgs/image_encodings.h>
#include <random_numbers/random_numbers.h>

#include <msckf_vio/CameraMeasurement.h>
#include <msckf_vio/TrackingInfo.h>
#include <msckf_vio/image_processor.h>
#include <msckf_vio/utils.h>
#include "../act_fast/airborne/modules/computer_vision/lib/vision/act_fast.hpp"
#include "../act_fast/airborne/modules/computer_vision/lib/vision/fast_9.hpp"
#include "../LK20_ImageAlignment/src/LK20.hpp"
#include "../LK20_ImageAlignment/src/LK20_stereo.hpp"
#include "../LK20_ImageAlignment/src/LK20_stereoxy.hpp"

using namespace std;
using namespace cv;
using namespace Eigen;

#define do_logging

namespace msckf_vio {
ImageProcessor::ImageProcessor(ros::NodeHandle& n) :
  nh(n),
  is_first_img(true),
  //img_transport(n),
  stereo_sub(10),
  prev_features_ptr(new GridFeatures()),
  curr_features_ptr(new GridFeatures()) {
  return;
}

ImageProcessor::~ImageProcessor() {
  destroyAllWindows();
  //ROS_INFO("Feature lifetime statistics:");
  //featureLifetimeStatistics();
  return;
}

bool ImageProcessor::loadParameters() {
  // Camera calibration parameters
  nh.param<string>("cam0/distortion_model",
      cam0_distortion_model, string("radtan"));
  nh.param<string>("cam1/distortion_model",
      cam1_distortion_model, string("radtan"));

  vector<int> cam0_resolution_temp(2);
  nh.getParam("cam0/resolution", cam0_resolution_temp);
  cam0_resolution[0] = cam0_resolution_temp[0];
  cam0_resolution[1] = cam0_resolution_temp[1];

  vector<int> cam1_resolution_temp(2);
  nh.getParam("cam1/resolution", cam1_resolution_temp);
  cam1_resolution[0] = cam1_resolution_temp[0];
  cam1_resolution[1] = cam1_resolution_temp[1];

  vector<double> cam0_intrinsics_temp(4);
  nh.getParam("cam0/intrinsics", cam0_intrinsics_temp);
  cam0_intrinsics[0] = cam0_intrinsics_temp[0];
  cam0_intrinsics[1] = cam0_intrinsics_temp[1];
  cam0_intrinsics[2] = cam0_intrinsics_temp[2];
  cam0_intrinsics[3] = cam0_intrinsics_temp[3];

  vector<double> cam1_intrinsics_temp(4);
  nh.getParam("cam1/intrinsics", cam1_intrinsics_temp);
  cam1_intrinsics[0] = cam1_intrinsics_temp[0];
  cam1_intrinsics[1] = cam1_intrinsics_temp[1];
  cam1_intrinsics[2] = cam1_intrinsics_temp[2];
  cam1_intrinsics[3] = cam1_intrinsics_temp[3];

  vector<double> cam0_distortion_coeffs_temp(4);
  nh.getParam("cam0/distortion_coeffs",
      cam0_distortion_coeffs_temp);
  cam0_distortion_coeffs[0] = cam0_distortion_coeffs_temp[0];
  cam0_distortion_coeffs[1] = cam0_distortion_coeffs_temp[1];
  cam0_distortion_coeffs[2] = cam0_distortion_coeffs_temp[2];
  cam0_distortion_coeffs[3] = cam0_distortion_coeffs_temp[3];

  vector<double> cam1_distortion_coeffs_temp(4);
  nh.getParam("cam1/distortion_coeffs",
      cam1_distortion_coeffs_temp);
  cam1_distortion_coeffs[0] = cam1_distortion_coeffs_temp[0];
  cam1_distortion_coeffs[1] = cam1_distortion_coeffs_temp[1];
  cam1_distortion_coeffs[2] = cam1_distortion_coeffs_temp[2];
  cam1_distortion_coeffs[3] = cam1_distortion_coeffs_temp[3];

  cv::Mat     T_imu_cam0 = utils::getTransformCV(nh, "cam0/T_cam_imu");
  cv::Matx33d R_imu_cam0(T_imu_cam0(cv::Rect(0,0,3,3)));
  cv::Vec3d   t_imu_cam0 = T_imu_cam0(cv::Rect(3,0,1,3));
  R_cam0_imu = R_imu_cam0.t();
  t_cam0_imu = -R_imu_cam0.t() * t_imu_cam0;

  cv::Mat T_cam0_cam1 = utils::getTransformCV(nh, "cam1/T_cn_cnm1");
  cv::Mat T_imu_cam1 = T_cam0_cam1 * T_imu_cam0;
  cv::Matx33d R_imu_cam1(T_imu_cam1(cv::Rect(0,0,3,3)));
  cv::Vec3d   t_imu_cam1 = T_imu_cam1(cv::Rect(3,0,1,3));
  R_cam1_imu = R_imu_cam1.t();
  t_cam1_imu = -R_imu_cam1.t() * t_imu_cam1;

  // Processor parameters
  nh.param<int>("grid_row", processor_config.grid_row, 4);
  nh.param<int>("grid_col", processor_config.grid_col, 4);
  nh.param<int>("border_height_margin", processor_config.border_height_margin, 10);
  nh.param<int>("border_width_margin", processor_config.border_width_margin, 10);
  nh.param<int>("free_features",
      processor_config.free_features, 0);
  nh.param<int>("grid_min_feature_num",
      processor_config.grid_min_feature_num, 2);
  nh.param<int>("grid_max_feature_num",
      processor_config.grid_max_feature_num, 4);
  nh.param<int>("pyramid_levels",
      processor_config.pyramid_levels, 3);
  nh.param<int>("pyramid_scale",
      processor_config.pyramid_scale, 2);
  nh.param<int>("patch_size",
      processor_config.patch_size, 31);
  nh.param<int>("fast_threshold",
      processor_config.fast_threshold, 20);
  nh.param<bool>("detection_per_grid",
      processor_config.detection_per_grid, false);
  nh.param<bool>("use_ActFAST",
      processor_config.use_ActFAST, false);
  nh.param<float>("longstep",
      processor_config.longstep, 6.f);
  nh.param<float>("shortstep",
      processor_config.shortstep, 2.f);
  nh.param<int>("gradientThreshold",
      processor_config.gradientThreshold, 30);
  nh.param<int>("gradientMethod",
      processor_config.gradientMethod, 0);
  nh.param<int>("n_agents",
      processor_config.n_agents, 512);
  nh.param<int>("n_time_steps",
      processor_config.n_time_steps, 30);
  nh.param<bool>("use_local_stereo",
      processor_config.use_local_stereo, false);
  nh.param<int>("local_stereo_width",
      processor_config.local_stereo_width, 40);
  nh.param<int>("local_stereo_height",
      processor_config.local_stereo_height, 25);
  nh.param<int>("local_stereo_pyramid",
      processor_config.local_stereo_pyramid, 2);
  nh.param<int>("local_stereo_winsize",
      processor_config.local_stereo_winsize, 5);
  nh.param<double>("local_stereo_threshold",
      processor_config.local_stereo_threshold, 1e-3);
  nh.param<bool>("use_local_tracker",
      processor_config.use_local_tracker, false);
  nh.param<int>("local_tracker_pyramid",
      processor_config.local_tracker_pyramid, 2);
  nh.param<int>("local_tracker_winsize",
      processor_config.local_tracker_winsize, 3);
  nh.param<int>("local_tracker_width",
      processor_config.local_tracker_width, 20);
  nh.param<int>("local_tracker_height",
      processor_config.local_tracker_height, 20);
  nh.param<bool>("use_bias_correction",
      processor_config.use_bias_correction, false);

  nh.param<bool>("use_LK_inv_tracker",
      processor_config.use_LK_inv_tracker, false);
  nh.param<float>("error_threshold_tracker",
      processor_config.error_threshold_tracker, 30.f);
  nh.param<int>("tracker_win_height",
      processor_config.tracker_win_height, 15);
  nh.param<int>("tracker_win_width",
      processor_config.tracker_win_width, 15);
  nh.param<float>("tracker_track_precision",
      processor_config.tracker_track_precision, 0.02f);
  nh.param<int>("tracker_max_iteration",
      processor_config.tracker_max_iteration, 20);
  nh.param<float>("tracker_max_distance",
      processor_config.tracker_max_distance, 300.f);

  nh.param<bool>("use_2pRANSAC",
      processor_config.use_2pRANSAC, true);    

  nh.param<bool>("use_LK_inv_stereoXY",
      processor_config.use_LK_inv_stereoXY, false);
  nh.param<bool>("use_LK_inv_stereoX",
      processor_config.use_LK_inv_stereoX, false);
  nh.param<float>("error_threshold_stereo",
      processor_config.error_threshold_stereo, 40.f);
  nh.param<int>("stereo_win_height",
      processor_config.stereo_win_height, 9);
  nh.param<int>("stereo_win_width",
      processor_config.stereo_win_width, 15);
  nh.param<float>("stereo_track_precision",
      processor_config.stereo_track_precision, 0.05f);
  nh.param<int>("stereo_max_iteration",
      processor_config.stereo_max_iteration, 20);
  nh.param<float>("stereo_dx_prediction",
      processor_config.stereo_dx_prediction, 0.f);

  nh.param<int>("max_iteration",
      processor_config.max_iteration, 30);
  nh.param<double>("track_precision",
      processor_config.track_precision, 0.01);
  nh.param<double>("ransac_threshold",
      processor_config.ransac_threshold, 3);
  nh.param<double>("stereo_threshold",
      processor_config.stereo_threshold, 3);

  ROS_INFO("===========================================");
  ROS_INFO("cam0_resolution: %d, %d",
      cam0_resolution[0], cam0_resolution[1]);
  ROS_INFO("cam0_intrinscs: %f, %f, %f, %f",
      cam0_intrinsics[0], cam0_intrinsics[1],
      cam0_intrinsics[2], cam0_intrinsics[3]);
  ROS_INFO("cam0_distortion_model: %s",
      cam0_distortion_model.c_str());
  ROS_INFO("cam0_distortion_coefficients: %f, %f, %f, %f",
      cam0_distortion_coeffs[0], cam0_distortion_coeffs[1],
      cam0_distortion_coeffs[2], cam0_distortion_coeffs[3]);

  ROS_INFO("cam1_resolution: %d, %d",
      cam1_resolution[0], cam1_resolution[1]);
  ROS_INFO("cam1_intrinscs: %f, %f, %f, %f",
      cam1_intrinsics[0], cam1_intrinsics[1],
      cam1_intrinsics[2], cam1_intrinsics[3]);
  ROS_INFO("cam1_distortion_model: %s",
      cam1_distortion_model.c_str());
  ROS_INFO("cam1_distortion_coefficients: %f, %f, %f, %f",
      cam1_distortion_coeffs[0], cam1_distortion_coeffs[1],
      cam1_distortion_coeffs[2], cam1_distortion_coeffs[3]);

  cout << R_imu_cam0 << endl;
  cout << t_imu_cam0.t() << endl;

  ROS_INFO("grid_row: %d",
      processor_config.grid_row);
  ROS_INFO("grid_col: %d",
      processor_config.grid_col);
  ROS_INFO("grid_min_feature_num: %d",
      processor_config.grid_min_feature_num);
  ROS_INFO("grid_max_feature_num: %d",
      processor_config.grid_max_feature_num);
  ROS_INFO("pyramid_levels: %d",
      processor_config.pyramid_levels);
  ROS_INFO("patch_size: %d",
      processor_config.patch_size);
  ROS_INFO("fast_threshold: %d",
      processor_config.fast_threshold);
  ROS_INFO("max_iteration: %d",
      processor_config.max_iteration);
  ROS_INFO("track_precision: %f",
      processor_config.track_precision);
  ROS_INFO("ransac_threshold: %f",
      processor_config.ransac_threshold);
  ROS_INFO("stereo_threshold: %f",
      processor_config.stereo_threshold);
  ROS_INFO("LK inv error thresold: %f",
      processor_config.error_threshold_tracker);
  ROS_INFO("===========================================");
  return true;
}

bool ImageProcessor::createRosIO() {
  feature_pub = nh.advertise<CameraMeasurement>(
      "features", 3);
  tracking_info_pub = nh.advertise<TrackingInfo>(
      "tracking_info", 1);
  image_transport::ImageTransport it(nh);
  debug_stereo_pub = it.advertise("debug_stereo_image", 1);

  cam0_img_sub.subscribe(nh, "cam0_image", 10);
  cam1_img_sub.subscribe(nh, "cam1_image", 10);
  stereo_sub.connectInput(cam0_img_sub, cam1_img_sub);
  stereo_sub.registerCallback(&ImageProcessor::stereoCallback, this);
  imu_sub = nh.subscribe("imu", 50,
      &ImageProcessor::imuCallback, this);
  bias_sub = nh.subscribe("/firefly_sbx/vio/bias", 1,
      &ImageProcessor::biasCallback, this);

  return true;
}

bool ImageProcessor::initialize() {
  ROS_INFO("initialize ImageProcessor ROS parameters...");
  if (!loadParameters()) return false;
  ROS_INFO("Finish loading ROS parameters...");

  // Create feature detector.
  detector_ptr = FastFeatureDetector::create(
      processor_config.fast_threshold);

  if (processor_config.use_LK_inv_stereoX || processor_config.use_LK_inv_stereoXY || processor_config.use_LK_inv_tracker)
    for (int level=0; level<processor_config.pyramid_levels; level++)
    {
      static int scale = 1; 
      // int scale = 1+level; 
      curr_cam1_pyramid_.push_back(cv::Mat::zeros(480/scale, 752/scale, CV_8U));
      curr_cam0_pyramid_.push_back(cv::Mat::zeros(480/scale, 752/scale, CV_8U));
      prev_cam0_pyramid_.push_back(cv::Mat::zeros(480/scale, 752/scale, CV_8U));
      scale *= processor_config.pyramid_scale;
    }

  if (!createRosIO()) return false;
  ROS_INFO("Finish creating ROS IO...");

  return true;
}

void ImageProcessor::stereoCallback(
    const sensor_msgs::ImageConstPtr& cam0_img,
    const sensor_msgs::ImageConstPtr& cam1_img) {

  //cout << "==================================" << endl;

  #ifdef do_logging
  double track_time;
  double prunefeatures_time;

  ros::Time start_time = ros::Time::now();
  #endif
  // Get the current image.
  cam0_curr_img_ptr = cv_bridge::toCvShare(cam0_img,
      sensor_msgs::image_encodings::MONO8);
  cam1_curr_img_ptr = cv_bridge::toCvShare(cam1_img,
      sensor_msgs::image_encodings::MONO8);
  #ifdef do_logging
  double cv_bridge_time = (ros::Time::now()-start_time).toSec();

  // Build the image pyramids once since they're used at multiple places
  // std::cout<<"pyr"<<std::endl;
  start_time = ros::Time::now();
  #endif

  createImagePyramids();
  #ifdef do_logging
  double image_pyramid_time = (ros::Time::now()-start_time).toSec();
  #endif

  // Detect features in the first frame.
  if (is_first_img) {
    // ros::Time start_time = ros::Time::now();
    initializeFirstFrame();
    //ROS_INFO("Detection time: %f",
    //    (ros::Time::now()-start_time).toSec());
    is_first_img = false;

    // Draw results.
    // start_time = ros::Time::now();
    drawFeaturesStereo();
    //ROS_INFO("Draw features: %f",
    //    (ros::Time::now()-start_time).toSec());
  } else {
    // Track the feature in the previous image.
    #ifdef do_logging
    ros::Time start_time = ros::Time::now();
    #endif
    // std::cout<<"tracking start now"<<std::endl;
    trackFeatures();
    #ifdef do_logging
    track_time = (ros::Time::now()-start_time).toSec();
    #endif
    //ROS_INFO("Tracking time: %f",
    //    (ros::Time::now()-start_time).toSec());

    // Add new features into the current image.
    // start_time = ros::Time::now();
    // std::cout<<"addNewFeatures start now"<<std::endl;
    addNewFeatures();
    // std::cout<<"after"<<std::endl;
    //ROS_INFO("Addition time: %f",
    //    (ros::Time::now()-start_time).toSec());

    // Add new features into the current image.
    #ifdef do_logging
    start_time = ros::Time::now();
    #endif
    pruneGridFeatures();
    #ifdef do_logging
    prunefeatures_time = (ros::Time::now()-start_time).toSec();
    #endif

    //ROS_INFO("Prune grid features: %f",
    //    (ros::Time::now()-start_time).toSec());

    // Draw results.
    // start_time = ros::Time::now();
    drawFeaturesStereo();
    //ROS_INFO("Draw features: %f",
    //    (ros::Time::now()-start_time).toSec());
  }

  //ros::Time start_time = ros::Time::now();
  //updateFeatureLifetime();
  //ROS_INFO("Statistics: %f",
  //    (ros::Time::now()-start_time).toSec());

  // Publish features in the current image.
  #ifdef do_logging
  ros::Time start_time0 = ros::Time::now();
  start_time = ros::Time::now();
  #endif
  publish();
  #ifdef do_logging
  double pub_time = (ros::Time::now()-start_time).toSec();
  start_time = ros::Time::now();
  #endif

  //ROS_INFO("Publishing: %f",
  //    (ros::Time::now()-start_time).toSec());

  // Update the previous image and previous features.
  cam0_prev_img_ptr = cam0_curr_img_ptr;
  prev_features_ptr = curr_features_ptr;
  std::swap(prev_cam0_pyramid_, curr_cam0_pyramid_);

  // Initialize the current features to empty vectors.
  curr_features_ptr.reset(new GridFeatures());
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code) {
    (*curr_features_ptr)[code] = vector<FeatureMetaData>(0);
  }
  #ifdef do_logging
  double update_time = (ros::Time::now()-start_time).toSec();

  double pub_update_time = (ros::Time::now()-start_time0).toSec();


  std::ofstream trackandprunetime;
  trackandprunetime.open ("trackandprune_time.txt", std::ios_base::app);
  trackandprunetime << track_time << ' ' << prunefeatures_time << ' ' << pub_update_time << ' ' << image_pyramid_time
  << ' ' << pub_time << ' ' << update_time << ' ' << cv_bridge_time << '\n';
  trackandprunetime.close();
  #endif

  return;
}

void ImageProcessor::imuCallback(
    const sensor_msgs::ImuConstPtr& msg) {
  // Wait for the first image to be set.
  if (is_first_img) return;
  imu_msg_buffer.push_back(*msg);
  return;
}

void ImageProcessor::biasCallback(
    const geometry_msgs::Twist& msg) {
  imu_angular_bias[0] = msg.linear.x;
  imu_angular_bias[1] = msg.linear.y;
  imu_angular_bias[2] = msg.linear.z;
  imu_gyro_bias[0] = msg.angular.x;
  imu_gyro_bias[1] = msg.angular.y;
  imu_gyro_bias[2] = msg.angular.z;
  return;
}

void ImageProcessor::createImagePyramids() {
  
  if (processor_config.use_LK_inv_tracker || processor_config.use_LK_inv_stereoXY || processor_config.use_LK_inv_stereoX)
  {
    const Mat& curr_cam0_img = cam0_curr_img_ptr->image;
    const Mat& curr_cam1_img = cam1_curr_img_ptr->image;
    GenerateImagePyramid(curr_cam0_img, curr_cam0_pyramid_);
    GenerateImagePyramid(curr_cam1_img, curr_cam1_pyramid_);
  }
  else
  {
    if (processor_config.use_local_stereo == false || processor_config.use_local_tracker == false)
    {
      const Mat& curr_cam0_img = cam0_curr_img_ptr->image;
      buildOpticalFlowPyramid(
          curr_cam0_img, curr_cam0_pyramid_,
          Size(processor_config.patch_size, processor_config.patch_size),
          processor_config.pyramid_levels, true, BORDER_REFLECT_101,
          BORDER_CONSTANT, false);
    }

    if (processor_config.use_local_stereo == false)
    {
      const Mat& curr_cam1_img = cam1_curr_img_ptr->image;
      buildOpticalFlowPyramid(
          curr_cam1_img, curr_cam1_pyramid_,
          Size(processor_config.patch_size, processor_config.patch_size),
          processor_config.pyramid_levels, true, BORDER_REFLECT_101,
          BORDER_CONSTANT, false);
    }
  }
}

void ImageProcessor::GenerateImagePyramid(const cv::Mat& m_src, std::vector<cv::Mat>& dst_pyramid) {
  // dst_pyramid.clear();
  if(m_src.channels() != 1) {
    std::cout<<"WARNING: A non grayscale image is given as input, grayscale is expected!"<<std::endl;
  }
  // cv::Mat m_down_sampled_image;
  // dst_pyramid.push_back(m_src.clone()); // 0th level (original image)
  dst_pyramid[0] = m_src;
  if (processor_config.pyramid_levels==1) return;
  ScaleDown(m_src, dst_pyramid[1]);

  for(int l = 2; l < processor_config.pyramid_levels; l++) {   
    ScaleDown(dst_pyramid[l-1], dst_pyramid[l]);
  }

  // static int frame = 0;
  // if (frame==0)
  // {
  //   cv:: imwrite("/home/stavrow/testscale/0.jpg", dst_pyramid[0]);
  //   cv:: imwrite("/home/stavrow/testscale/1.jpg", dst_pyramid[1]);
  //   // cv:: imwrite("/home/stavrow/testscale/2.jpg", dst_pyramid[2]);
  // }
  // if (frame==330)
  // {
  //   cv:: imwrite("/home/stavrow/testscale/f2_0.jpg", dst_pyramid[0]);
  //   cv:: imwrite("/home/stavrow/testscale/f2_1.jpg", dst_pyramid[1]);
  //   // cv:: imwrite("/home/stavrow/testscale/f2_2.jpg", dst_pyramid[2]);
  // }
  // frame++;

}

void ImageProcessor::ScaleDown(const cv::Mat& src, cv::Mat& dst) {
  // std::cout<<"hier"<<std::endl;
  // cv::Mat scaled_img(cv::Size(src.cols/2+1, src.rows/2+1), CV_8U);
  static int srcCols;
  srcCols = src.cols;

  static int i,j;
  // if(scaled_img.isContinuous())
  if(dst.isContinuous())
  {
    // std::cout<<src.isContinuous()<<std::endl;
    // std::cout<<"-"<<std::endl;
    static int k;
    k =0;
    uchar* p;
    const uchar* q;
    // p = scaled_img.ptr<uchar>(0);
    p = dst.ptr<uchar>(0);
    // std::cout<<"for loop"<<std::endl;
    if (processor_config.pyramid_scale == 2)
    {
      for( i = 0; i < dst.rows; ++i)
      {
        q = src.ptr<uchar>(i+i);
          for ( j = 0; j < dst.cols; ++j)
          {
            // std::cout<<i<<", "<<j<<", "<<k<<std::endl;
            p[k] = (q[j+j] + q[j+j + 1] +
              q[j+j + srcCols] +  q[j+j + 1 + srcCols])/4;
            k++;
          }
      }
    }
    else if (processor_config.pyramid_scale == 3)
    {
      for( i = 0; i < dst.rows; ++i)
      {
        q = src.ptr<uchar>(3*i);
          for ( j = 0; j < dst.cols; ++j)
          {
            // std::cout<<i<<", "<<j<<", "<<k<<std::endl;
            p[k] = (q[j*3] + q[j*3 + 1] + q[j*3 + 2] +
                    q[j*3 + srcCols] +  q[j*3 + 1 + srcCols] + q[j*3 + 2 + srcCols] +
                    q[j*3 + srcCols + srcCols] +  q[j*3 + 1 + srcCols + srcCols] + q[j*3 + 2 + srcCols + srcCols])/9;
            k++;
          }
      }
    }
    else if(processor_config.pyramid_scale == 4)
    {
      for( i = 0; i < dst.rows; ++i)
      {
        q = src.ptr<uchar>(4*i);
          for ( j = 0; j < dst.cols; ++j)
          {
            // std::cout<<i<<", "<<j<<", "<<k<<std::endl;
            p[k] = (q[j*4] + q[j*4 + 1] + q[j*4 + 2] + q[j*4 + 3] +
                    q[j*4 + srcCols] +  q[j*4 + 1 + srcCols] + q[j*4 + 2 + srcCols] +  q[j*4 + 3 + srcCols] +
                    q[j*4 + srcCols + srcCols] +  q[j*4 + 1 + srcCols + srcCols] + q[j*4 + 2 + srcCols + srcCols] +  q[j*4 + 3 + srcCols + srcCols] +
                    q[j*4 + srcCols*3] +  q[j*4 + 1 + srcCols*3] + q[j*4 + 2 + srcCols*3] +  q[j*4 + 3 + srcCols*3])/16;
            k++;
          }
      }
    }
  }
  else
  {
    std::cout<<"WARNING::ImageProcessor::ScaleDown cv mat not continuous, increasing computation time"<<std::endl;
    // for (i=0; i<scaled_img.rows; i++)
    for (i=0; i<dst.rows; i++)
    {
      // for (j=0; j<scaled_img.cols; j++)
      for (j=0; j<dst.cols; j++)
      {
        // scaled_img.at<uchar>(i,j) = (src.at<uchar>(2*i,2*j) +
        dst.at<uchar>(i,j) = (src.at<uchar>(2*i,2*j) +
                                      src.at<uchar>(2*i+1,2*j) +
                                      src.at<uchar>(2*i,2*j+1) +
                                      src.at<uchar>(2*i+1,2*j+1) ) / 4;
      }
    }
  }


  // return scaled_img;
  return;
}

void ImageProcessor::initializeFirstFrame() {
  #ifdef do_logging
  ros::Time start_time = ros::Time::now();
  #endif
  // Size of each grid.
  const Mat& img = cam0_curr_img_ptr->image;
  // std::cout<<processor_config.border_height_margin<<std::endl;
  static int grid_height = (img.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
  static int grid_width = (img.cols-2*processor_config.border_width_margin) / processor_config.grid_col;

  // Detect new features on the frist image.
  vector<KeyPoint> new_features(0);

  if (processor_config.use_ActFAST)
  {
    static uint16_t num_corners;
    static const float longstep = processor_config.longstep;
    static const float shortstep = processor_config.shortstep;
    static const int gradientThreshold = processor_config.gradientThreshold;
    static const int gradientMethod = processor_config.gradientMethod;
    static const uint16_t n_agents = processor_config.n_agents; // 512 is maximum agents defined in opticflow_calculator.hpp
    static struct point_t* ret_corners = (struct point_t*) calloc(n_agents, sizeof(struct point_t));

    static const uint8_t fast_threshold = processor_config.fast_threshold;
    static const uint16_t n_time_steps = processor_config.n_time_steps;

    act_fast(&img, fast_threshold, &num_corners, &ret_corners,
                n_agents, n_time_steps, longstep, shortstep, gradientThreshold, gradientMethod);
    
    new_features.resize(num_corners);
    for (int i=0; i< num_corners; i++)
    {
      new_features[i].pt = Point2f (ret_corners[i].x, ret_corners[i].y);
      new_features[i].response = fast9_corner_score(&img, fast_threshold, ret_corners[i].x, ret_corners[i].y);
    }
  }
  else detector_ptr->detect(img, new_features); //@todo: detect features inside detection margin which it should not

  #ifdef do_logging
  double detection_time = (ros::Time::now()-start_time).toSec();
  #endif

// for (int i = 0; i < new_features.size(); ++i)
// {
//   std::cout<<"Fast score: "<<new_features[i].response<<std::endl;
// }
  // Find the stereo matched points for the newly
  // detected features.
  #ifdef do_logging
  start_time = ros::Time::now();
  #endif
  vector<cv::Point2f> cam0_points(new_features.size());
  for (int i = 0; i < new_features.size(); ++i)
    cam0_points[i] = new_features[i].pt;

  vector<cv::Point2f> cam1_points(0);
  vector<unsigned char> inlier_markers(0);
  stereoMatch(cam0_points, cam1_points, inlier_markers);

  vector<cv::Point2f> cam0_inliers(0);
  vector<cv::Point2f> cam1_inliers(0);
  vector<float> response_inliers(0);
  for (int i = 0; i < inlier_markers.size(); ++i) {
    if (inlier_markers[i] == 0) continue;
    cam0_inliers.push_back(cam0_points[i]);
    cam1_inliers.push_back(cam1_points[i]);
    response_inliers.push_back(new_features[i].response);
  }
  #ifdef do_logging
  double stereo_time = (ros::Time::now()-start_time).toSec();
  #endif

  // Group the features into grids
  #ifdef do_logging
  start_time = ros::Time::now();
  #endif
  GridFeatures grid_new_features;
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code)
      grid_new_features[code] = vector<FeatureMetaData>(0);

  for (int i = 0; i < cam0_inliers.size(); ++i) {
    const cv::Point2f& cam0_point = cam0_inliers[i];
    const cv::Point2f& cam1_point = cam1_inliers[i];
    const float& response = response_inliers[i];

    int row = static_cast<int>((cam0_point.y-processor_config.border_height_margin) / grid_height);
    int col = static_cast<int>((cam0_point.x-processor_config.border_width_margin) / grid_width);
    int code = row*processor_config.grid_col + col;

    FeatureMetaData new_feature;
    new_feature.response = response;
    new_feature.cam0_point = cam0_point;
    new_feature.cam1_point = cam1_point;
    grid_new_features[code].push_back(new_feature);
  }

  // Sort the new features in each grid based on its response.
  for (auto& item : grid_new_features)
    std::sort(item.second.begin(), item.second.end(),
        &ImageProcessor::featureCompareByResponse);

  // Collect new features within each grid with high response.
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code) {
    vector<FeatureMetaData>& features_this_grid = (*curr_features_ptr)[code];
    vector<FeatureMetaData>& new_features_this_grid = grid_new_features[code];

    for (int k = 0; k < processor_config.grid_min_feature_num &&
        k < new_features_this_grid.size(); ++k) {
      features_this_grid.push_back(new_features_this_grid[k]);
      features_this_grid.back().id = next_feature_id++;
      features_this_grid.back().lifetime = 1;
    }
  }
  #ifdef do_logging
  double selectfeature_time2 = (ros::Time::now()-start_time).toSec();
  #endif

  #ifdef do_logging
  std::ofstream featuretimefile;
  featuretimefile.open ("features.txt", std::ios_base::app);
  featuretimefile << 0 << ' ' << 0 << ' ' << detection_time << ' ' << detection_time << ' ' << stereo_time << ' '
    << 0 << ' ' << selectfeature_time2 << '\n';
  featuretimefile.close();
  #endif

  return;
}

void ImageProcessor::predictFeatureTracking(
    const vector<cv::Point2f>& input_pts,
    const cv::Matx33f& R_p_c,
    const cv::Vec4d& intrinsics,
    vector<cv::Point2f>& compensated_pts) {

  // Return directly if there are no input features.
  if (input_pts.size() == 0) {
    compensated_pts.clear();
    return;
  }
  compensated_pts.resize(input_pts.size());

  // Intrinsic matrix.
  cv::Matx33f K(
      intrinsics[0], 0.0, intrinsics[2],
      0.0, intrinsics[1], intrinsics[3],
      0.0, 0.0, 1.0);
  cv::Matx33f H = K * R_p_c * K.inv();

  for (int i = 0; i < input_pts.size(); ++i) {
    cv::Vec3f p1(input_pts[i].x, input_pts[i].y, 1.0f);
    cv::Vec3f p2 = H * p1;
    compensated_pts[i].x = p2[0] / p2[2];
    compensated_pts[i].y = p2[1] / p2[2];
  }

  return;
}

void ImageProcessor::trackFeatures() {
  // Size of each grid.
  static int grid_height =
    (cam0_curr_img_ptr->image.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
  static int grid_width =
    (cam0_curr_img_ptr->image.cols-2*processor_config.border_width_margin) / processor_config.grid_col;

  #ifdef do_logging
  ros::Time start_time = ros::Time::now();
  #endif

  // Compute a rough relative rotation which takes a vector
  // from the previous frame to the current frame.
  Matx33f cam0_R_p_c;
  Matx33f cam1_R_p_c;
  integrateImuData(cam0_R_p_c, cam1_R_p_c);

  // Organize the features in the previous image.
  vector<FeatureIDType> prev_ids(0);
  vector<int> prev_lifetime(0);
  vector<Point2f> prev_cam0_points(0);
  vector<Point2f> prev_cam1_points(0);

  for (const auto& item : *prev_features_ptr) {
    for (const auto& prev_feature : item.second) {
      prev_ids.push_back(prev_feature.id);
      prev_lifetime.push_back(prev_feature.lifetime);
      prev_cam0_points.push_back(prev_feature.cam0_point);
      prev_cam1_points.push_back(prev_feature.cam1_point);
    }
  }

  // Number of the features before tracking.
  before_tracking = prev_cam0_points.size();

  // Abort tracking if there is no features in
  // the previous frame.
  if (prev_ids.size() == 0) return;

  // Track features using LK optical flow method.
  vector<Point2f> curr_cam0_points(0);
  vector<unsigned char> track_inliers(0);

  predictFeatureTracking(prev_cam0_points,
      cam0_R_p_c, cam0_intrinsics, curr_cam0_points);

  #ifdef do_logging
  double preptime = (ros::Time::now()-start_time).toSec();
  start_time = ros::Time::now();
  #endif

  if (processor_config.use_local_tracker)
  {
    static int search_height = processor_config.local_tracker_height;
    static int search_width = processor_config.local_tracker_width;
    for (int i=0; i<curr_cam0_points.size(); i++)
    {
      if (curr_cam0_points[i].y - search_height/2 < 0 ||
          curr_cam0_points[i].y + search_height/2 > cam0_curr_img_ptr->image.rows-1 ||
          curr_cam0_points[i].x - search_width/2 < 0 ||
          curr_cam0_points[i].x + search_width/2 > cam0_curr_img_ptr->image.cols-1 ||
          prev_cam0_points[i].y - search_height/2 < 0 ||
          prev_cam0_points[i].y + search_height/2 > cam0_curr_img_ptr->image.rows-1 ||
          prev_cam0_points[i].x - search_width/2 < 0 ||
          prev_cam0_points[i].x + search_width/2 > cam0_curr_img_ptr->image.cols-1)
      {
        track_inliers.push_back(0);
      }
      else
      {
        cv::Rect prevROI(prev_cam0_points[i].x - search_width/2, prev_cam0_points[i].y-search_height/2, search_width, search_height);
        cv::Rect currROI(curr_cam0_points[i].x - search_width/2, curr_cam0_points[i].y-search_height/2, search_width, search_height);
        cv::Mat prev_cam0_searchimg = cam0_prev_img_ptr->image(prevROI);
        cv::Mat curr_cam0_searchimg = cam0_curr_img_ptr->image(currROI);

        vector<cv::Point2f> prev_point(1);
        prev_point[0] = Point2f( float(search_width/2), float(search_height/2));

        vector<cv::Point2f> curr_point(1);
        curr_point[0] =  Point2f( float(search_width/2), float(search_height/2));
        vector<unsigned char> track_inlier(0);

        calcOpticalFlowPyrLK(prev_cam0_searchimg, curr_cam0_searchimg,
                      prev_point, curr_point,
                      track_inlier, noArray(),
                      Size(processor_config.local_tracker_winsize, processor_config.local_tracker_winsize),
                      processor_config.local_tracker_pyramid,
                      TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                      processor_config.max_iteration,
                      processor_config.track_precision),
                      cv::OPTFLOW_USE_INITIAL_FLOW);

        track_inliers.push_back(track_inlier[0]);
        curr_cam0_points[i] = Point2f( curr_cam0_points[i].x - search_width/2 + curr_point[0].x,
                              curr_cam0_points[i].y - search_height/2 + curr_point[0].y);
      }
    }
  }
  else if (processor_config.use_LK_inv_tracker)
  {
    TrackLKInv(prev_cam0_pyramid_, curr_cam0_pyramid_, // Pyramid images
          prev_cam0_points, curr_cam0_points, // Previous feature location & estimated new location
          track_inliers, processor_config.error_threshold_tracker,
          Size(processor_config.tracker_win_width, processor_config.tracker_win_height), // window compare size
          processor_config.tracker_max_iteration, processor_config.tracker_track_precision, // Stop criteria
          processor_config.tracker_max_distance); // max distance squared to be inlier

  }
  else if (processor_config.use_LK_inv_stereoX || processor_config.use_LK_inv_stereoXY)
  {
    const Mat& curr_cam0_img = cam0_curr_img_ptr->image;
    const Mat& prev_cam0_img = cam0_prev_img_ptr->image;
    calcOpticalFlowPyrLK(
        prev_cam0_img, curr_cam0_img,
        prev_cam0_points, curr_cam0_points,
        track_inliers, noArray(),
        Size(processor_config.patch_size, processor_config.patch_size),
        // processor_config.pyramid_levels,
        3,
        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
          processor_config.max_iteration,
          processor_config.track_precision),
        cv::OPTFLOW_USE_INITIAL_FLOW);
  }
  else 
  {
    calcOpticalFlowPyrLK(
        prev_cam0_pyramid_, curr_cam0_pyramid_,
        prev_cam0_points, curr_cam0_points,
        track_inliers, noArray(),
        Size(processor_config.patch_size, processor_config.patch_size),
        processor_config.pyramid_levels,
        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
          processor_config.max_iteration,
          processor_config.track_precision),
        cv::OPTFLOW_USE_INITIAL_FLOW);

    // Mark those tracked points out of the image region
    // as untracked.
    for (int i = 0; i < curr_cam0_points.size(); ++i) {
      if (track_inliers[i] == 0) continue;
      if (curr_cam0_points[i].y < 0 ||
          curr_cam0_points[i].y > cam0_curr_img_ptr->image.rows-1 ||
          curr_cam0_points[i].x < 0 ||
          curr_cam0_points[i].x > cam0_curr_img_ptr->image.cols-1)
        track_inliers[i] = 0;
    }
  }

  #ifdef do_logging
  double tracktime = (ros::Time::now()-start_time).toSec();
  start_time = ros::Time::now();
  #endif

  // Collect the tracked points.
  vector<FeatureIDType> prev_tracked_ids(0);
  vector<int> prev_tracked_lifetime(0);
  vector<Point2f> prev_tracked_cam0_points(0);
  vector<Point2f> prev_tracked_cam1_points(0);
  vector<Point2f> curr_tracked_cam0_points(0);
  // vector<Point2f> curr_cam0_points_predicted_inliers(0);

  removeUnmarkedElements(
      prev_ids, track_inliers, prev_tracked_ids);
  removeUnmarkedElements(
      prev_lifetime, track_inliers, prev_tracked_lifetime);
  removeUnmarkedElements(
      prev_cam0_points, track_inliers, prev_tracked_cam0_points);
  removeUnmarkedElements(
      prev_cam1_points, track_inliers, prev_tracked_cam1_points);
  removeUnmarkedElements(
      curr_cam0_points, track_inliers, curr_tracked_cam0_points);
  // removeUnmarkedElements(
  //     curr_cam0_points_predicted, track_inliers, curr_cam0_points_predicted_inliers);

  // Number of features left after tracking.
  after_tracking = curr_tracked_cam0_points.size();
  #ifdef do_logging
  double collecttime = (ros::Time::now()-start_time).toSec();
  #endif


  // Outlier removal involves three steps, which forms a close
  // loop between the previous and current frames of cam0 (left)
  // and cam1 (right). Assuming the stereo matching between the
  // previous cam0 and cam1 images are correct, the three steps are:
  //
  // prev frames cam0 ----------> cam1
  //              |                |
  //              |ransac          |ransac
  //              |   stereo match |
  // curr frames cam0 ----------> cam1
  //
  // 1) Stereo matching between current images of cam0 and cam1.
  // 2) RANSAC between previous and current images of cam0.
  // 3) RANSAC between previous and current images of cam1.
  //
  // For Step 3, tracking between the images is no longer needed.
  // The stereo matching results are directly used in the RANSAC.
  #ifdef do_logging
  start_time = ros::Time::now();
  #endif

  // Step 1: stereo matching.
  vector<Point2f> curr_cam1_points(0);
  vector<unsigned char> match_inliers(0);
  stereoMatch(curr_tracked_cam0_points, curr_cam1_points, match_inliers);
  #ifdef do_logging
  double stereotime = (ros::Time::now()-start_time).toSec();


  start_time = ros::Time::now();
  #endif
  if (processor_config.use_2pRANSAC)
  // if (true)
  {
    vector<FeatureIDType> prev_matched_ids(0);
    vector<int> prev_matched_lifetime(0);
    vector<Point2f> prev_matched_cam0_points(0);
    vector<Point2f> prev_matched_cam1_points(0);
    vector<Point2f> curr_matched_cam0_points(0);
    vector<Point2f> curr_matched_cam1_points(0);
    // vector<Point2f> curr_cam0_points_predicted_inliers2(0);

    removeUnmarkedElements(
        prev_tracked_ids, match_inliers, prev_matched_ids);
    removeUnmarkedElements(
        prev_tracked_lifetime, match_inliers, prev_matched_lifetime);
    removeUnmarkedElements(
        prev_tracked_cam0_points, match_inliers, prev_matched_cam0_points);
    removeUnmarkedElements(
        prev_tracked_cam1_points, match_inliers, prev_matched_cam1_points);
    removeUnmarkedElements(
        curr_tracked_cam0_points, match_inliers, curr_matched_cam0_points);
    removeUnmarkedElements(
        curr_cam1_points, match_inliers, curr_matched_cam1_points);
    // removeUnmarkedElements(
    //     curr_cam0_points_predicted_inliers, match_inliers, curr_cam0_points_predicted_inliers2);


    // Number of features left after stereo matching.
    after_matching = curr_matched_cam0_points.size();


    // Step 2 and 3: RANSAC on temporal image pairs of cam0 and cam1.
    vector<int> cam0_ransac_inliers(0);
    twoPointRansac(prev_matched_cam0_points, curr_matched_cam0_points,
        cam0_R_p_c, cam0_intrinsics, cam0_distortion_model,
        cam0_distortion_coeffs, processor_config.ransac_threshold,
        0.99, cam0_ransac_inliers);

    vector<int> cam1_ransac_inliers(0);
    twoPointRansac(prev_matched_cam1_points, curr_matched_cam1_points,
        cam1_R_p_c, cam1_intrinsics, cam1_distortion_model,
        cam1_distortion_coeffs, processor_config.ransac_threshold,
        0.99, cam1_ransac_inliers);

    // Number of features after ransac.
    after_ransac = 0;

    for (int i = 0; i < cam0_ransac_inliers.size(); ++i)
    {
      if (cam0_ransac_inliers[i] == 0 ||
          cam1_ransac_inliers[i] == 0) continue;
      int row = static_cast<int>(
          (curr_matched_cam0_points[i].y-processor_config.border_height_margin) / grid_height);
      if (row < 0) row = 0; //@todo: use max and min instead of if statements
      else if (row > processor_config.grid_row) row = processor_config.grid_row;
      int col = static_cast<int>(
          (curr_matched_cam0_points[i].x-processor_config.border_width_margin) / grid_width);
      if (col < 0) col = 0;
      else if (col > processor_config.grid_col) col = processor_config.grid_col;
      int code = row*processor_config.grid_col + col;
      (*curr_features_ptr)[code].push_back(FeatureMetaData());

      FeatureMetaData& grid_new_feature = (*curr_features_ptr)[code].back();
      grid_new_feature.id = prev_matched_ids[i];
      grid_new_feature.lifetime = ++prev_matched_lifetime[i];
      grid_new_feature.cam0_point = curr_matched_cam0_points[i];
      grid_new_feature.cam1_point = curr_matched_cam1_points[i];


      // std::cout<<"predicted: "<<curr_cam0_points_predicted_inliers2[i].x<<", "<<curr_cam0_points_predicted_inliers2[i].y<<
      //     "    tracked: "<<curr_matched_cam0_points[i].x<<", "<<curr_matched_cam0_points[i].y<<std::endl;

      ++after_ransac;
    }
  }
  else
  {
    for (int i = 0; i < curr_tracked_cam0_points.size(); ++i)
    {
      if (match_inliers[i] == 0) continue;
      int row = static_cast<int>(
          (curr_tracked_cam0_points[i].y-processor_config.border_height_margin) / grid_height);
      if (row < 0) row = 0; //@todo: use max and min instead of if statements
      else if (row > processor_config.grid_row) row = processor_config.grid_row;
      int col = static_cast<int>(
          (curr_tracked_cam0_points[i].x-processor_config.border_width_margin) / grid_width);
      if (col < 0) col = 0;
      else if (col > processor_config.grid_col) col = processor_config.grid_col;
      int code = row*processor_config.grid_col + col;
      (*curr_features_ptr)[code].push_back(FeatureMetaData());

      FeatureMetaData& grid_new_feature = (*curr_features_ptr)[code].back();
      grid_new_feature.id = prev_tracked_ids[i];
      grid_new_feature.lifetime = ++prev_tracked_lifetime[i];
      grid_new_feature.cam0_point = curr_tracked_cam0_points[i];
      grid_new_feature.cam1_point = curr_cam1_points[i];


      // std::cout<<"predicted: "<<curr_cam0_points_predicted_inliers2[i].x<<", "<<curr_cam0_points_predicted_inliers2[i].y<<
      //     "    tracked: "<<curr_matched_cam0_points[i].x<<", "<<curr_matched_cam0_points[i].y<<std::endl;

      ++after_ransac;
    }
  }
  #ifdef do_logging
  double ransactime = (ros::Time::now()-start_time).toSec();
  #endif


  // for (int i = 0; i < curr_matched_cam0_points.size(); ++i) //without ransac
  // {
  //   int row = static_cast<int>(
  //       (curr_matched_cam0_points[i].y-processor_config.border_height_margin) / grid_height);
  //   if (row < 0) row = 0; //@todo: use max and min instead of if statements
  //   else if (row > processor_config.grid_row) row = processor_config.grid_row;
  //   int col = static_cast<int>(
  //       (curr_matched_cam0_points[i].x-processor_config.border_width_margin) / grid_width);
  //   if (col < 0) col = 0;
  //   else if (col > processor_config.grid_col) col = processor_config.grid_col;
  //   int code = row*processor_config.grid_col + col;
  //   (*curr_features_ptr)[code].push_back(FeatureMetaData());

  //   FeatureMetaData& grid_new_feature = (*curr_features_ptr)[code].back();
  //   grid_new_feature.id = prev_matched_ids[i];
  //   grid_new_feature.lifetime = ++prev_matched_lifetime[i];
  //   grid_new_feature.cam0_point = curr_matched_cam0_points[i];
  //   grid_new_feature.cam1_point = curr_matched_cam1_points[i];
  // }

  #ifdef do_logging
  start_time = ros::Time::now();
  #endif

  // Compute the tracking rate.
  int prev_feature_num = 0;
  for (const auto& item : *prev_features_ptr)
    prev_feature_num += item.second.size();

  int curr_feature_num = 0;
  for (const auto& item : *curr_features_ptr)
    curr_feature_num += item.second.size();

  #ifdef do_logging
  ROS_INFO_THROTTLE(0.5,
      "\033[0;32m candidates: %d; track: %d; match: %d; ransac: %d/%d=%f\033[0m",
      before_tracking, after_tracking, after_matching,
      curr_feature_num, prev_feature_num,
      static_cast<double>(curr_feature_num)/
      (static_cast<double>(prev_feature_num)+1e-5));

  double printtime = (ros::Time::now()-start_time).toSec();
  // printf(
  //    "\033[0;32m candidates: %d; raw track: %d; stereo match: %d; ransac: %d/%d=%f\033[0m\n",
  //    before_tracking, after_tracking, after_matching,
  //    curr_feature_num, prev_feature_num,
  //    static_cast<double>(curr_feature_num)/
  //    (static_cast<double>(prev_feature_num)+1e-5));


  std::ofstream featuretimefile;
  featuretimefile.open ("tracking.txt", std::ios_base::app);
  featuretimefile << preptime << ' ' << tracktime << ' ' << collecttime  << ' ' 
    << stereotime << ' ' << ransactime << ' ' << printtime <<'\n';
  featuretimefile.close();
  #endif

  return;
}

void ImageProcessor::stereoMatch(
    const vector<cv::Point2f>& cam0_points,
    vector<cv::Point2f>& cam1_points,
    vector<unsigned char>& inlier_markers) {

  if (cam0_points.size() == 0) return;

  if(cam1_points.size() == 0) {
    // Initialize cam1_points by projecting cam0_points to cam1 using the
    // rotation from stereo extrinsics
    const cv::Matx33d R_cam0_cam1 = R_cam1_imu.t() * R_cam0_imu;
    vector<cv::Point2f> cam0_points_undistorted;
    undistortPoints(cam0_points, cam0_intrinsics, cam0_distortion_model,
                    cam0_distortion_coeffs, cam0_points_undistorted,
                    R_cam0_cam1);
    cam1_points = distortPoints(cam0_points_undistorted, cam1_intrinsics,
                                cam1_distortion_model, cam1_distortion_coeffs);
  }

  if (processor_config.use_local_stereo)
  {
    static int search_height = processor_config.local_stereo_height;
    static int search_width = processor_config.local_stereo_width;
    for (int i=0; i<cam0_points.size(); i++)
    {
      if (cam1_points[i].y - search_height/2 < 0 ||
          cam1_points[i].y + search_height/2 > cam1_curr_img_ptr->image.rows-1 ||
          cam1_points[i].x - search_width < 0 ||
          cam1_points[i].x > cam1_curr_img_ptr->image.cols-1 ||
          cam0_points[i].y - search_height/2 < 0 ||
          cam0_points[i].y + search_height/2 > cam0_curr_img_ptr->image.rows-1 ||
          cam0_points[i].x - search_width/2 < 0 ||
          cam0_points[i].x + search_width/2 > cam0_curr_img_ptr->image.cols-1)
      {
        inlier_markers.push_back(0);
      }
      else
      {
        const Mat& curr_cam0_img = cam0_curr_img_ptr->image;
        const Mat& curr_cam1_img = cam1_curr_img_ptr->image;
        cv::Rect cam0ROI(cam0_points[i].x- search_width/2, cam0_points[i].y-search_height/2, search_width, search_height);
        cv::Rect cam1ROI(cam1_points[i].x - search_width, cam1_points[i].y-search_height/2, search_width, search_height);
        cv::Mat curr_cam0_searchimg = curr_cam0_img(cam0ROI);
        cv::Mat curr_cam1_searchimg = curr_cam1_img(cam1ROI);

        vector<cv::Point2f> cam0_point(1);
        cam0_point[0] = Point2f( float(search_width/2), float(search_height/2));

        vector<cv::Point2f> cam1_point(1);
        cam1_point[0] =  Point2f( float(search_width/2), float(search_height/2));
        vector<unsigned char> inlier_marker(0);

        calcOpticalFlowPyrLK(curr_cam0_searchimg, curr_cam1_searchimg,
        cam0_point, cam1_point,
        inlier_marker, noArray(),
        Size(processor_config.local_stereo_winsize, processor_config.local_stereo_winsize),
        processor_config.local_stereo_pyramid,
        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                      processor_config.max_iteration,
                      processor_config.track_precision),
                      cv::OPTFLOW_USE_INITIAL_FLOW, processor_config.local_stereo_threshold);

        inlier_markers.push_back(inlier_marker[0]);
        cam1_points[i] = Point2f( cam1_points[i].x - search_width + cam1_point[0].x,
                              cam1_points[i].y-search_height/2 + cam1_point[0].y);
      }
    }
  }
  else if (processor_config.use_LK_inv_stereoXY)
  {
    TrackLKInv_stereoXY(curr_cam0_pyramid_, curr_cam1_pyramid_, // Pyramid images
          cam0_points, cam1_points, // Previous feature location & estimated new location
          inlier_markers, processor_config.error_threshold_stereo,
          Size(processor_config.stereo_win_width, processor_config.stereo_win_height), // window compare size
          processor_config.stereo_max_iteration, processor_config.stereo_track_precision, // Stop criteria
          processor_config.stereo_dx_prediction); 
  }
  else if (processor_config.use_LK_inv_stereoX)
    TrackLKInv_stereo(curr_cam0_pyramid_, curr_cam1_pyramid_, // Pyramid images
        cam0_points, cam1_points, // Previous feature location & estimated new location
        inlier_markers, processor_config.error_threshold_stereo,
        Size(processor_config.stereo_win_width, processor_config.stereo_win_height), // window compare size
        processor_config.stereo_max_iteration, processor_config.stereo_track_precision, // Stop criteria
        processor_config.stereo_dx_prediction); 
  else if (processor_config.use_LK_inv_tracker)
  {
    const Mat& curr_cam0_img = cam0_curr_img_ptr->image;
    const Mat& curr_cam1_img = cam1_curr_img_ptr->image;
    calcOpticalFlowPyrLK(curr_cam0_img, curr_cam1_img,
          cam0_points, cam1_points,
          inlier_markers, noArray(),
          Size(processor_config.patch_size, processor_config.patch_size),
          processor_config.pyramid_levels,
          TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                      processor_config.max_iteration,
                      processor_config.track_precision),
          cv::OPTFLOW_USE_INITIAL_FLOW);
  }
  else
  {
  // Track features using OpenCV LK optical flow method.
    calcOpticalFlowPyrLK(curr_cam0_pyramid_, curr_cam1_pyramid_,
        cam0_points, cam1_points,
        inlier_markers, noArray(),
        Size(processor_config.patch_size, processor_config.patch_size),
        processor_config.pyramid_levels,
        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                    processor_config.max_iteration,
                    processor_config.track_precision),
        cv::OPTFLOW_USE_INITIAL_FLOW);

    // Mark those tracked points out of the image region
    // as untracked.
    for (int i = 0; i < cam1_points.size(); ++i) {
      if (inlier_markers[i] == 0) continue;
      if (cam1_points[i].y < 0 ||
          cam1_points[i].y > cam1_curr_img_ptr->image.rows-1 ||
          cam1_points[i].x < 0 ||
          cam1_points[i].x > cam1_curr_img_ptr->image.cols-1)
        inlier_markers[i] = 0;
    }
  }

  // Compute the relative rotation between the cam0
  // frame and cam1 frame.
  const cv::Matx33d R_cam0_cam1 = R_cam1_imu.t() * R_cam0_imu;
  const cv::Vec3d t_cam0_cam1 = R_cam1_imu.t() * (t_cam0_imu-t_cam1_imu);
  // Compute the essential matrix.
  const cv::Matx33d t_cam0_cam1_hat(
      0.0, -t_cam0_cam1[2], t_cam0_cam1[1],
      t_cam0_cam1[2], 0.0, -t_cam0_cam1[0],
      -t_cam0_cam1[1], t_cam0_cam1[0], 0.0);
  const cv::Matx33d E = t_cam0_cam1_hat * R_cam0_cam1;

  // Further remove outliers based on the known
  // essential matrix.
  vector<cv::Point2f> cam0_points_undistorted(0);
  vector<cv::Point2f> cam1_points_undistorted(0);
  undistortPoints(
      cam0_points, cam0_intrinsics, cam0_distortion_model,
      cam0_distortion_coeffs, cam0_points_undistorted);
  undistortPoints(
      cam1_points, cam1_intrinsics, cam1_distortion_model,
      cam1_distortion_coeffs, cam1_points_undistorted);

  double norm_pixel_unit = 4.0 / (
      cam0_intrinsics[0]+cam0_intrinsics[1]+
      cam1_intrinsics[0]+cam1_intrinsics[1]);

  for (int i = 0; i < cam0_points_undistorted.size(); ++i) {
    if (inlier_markers[i] == 0) continue;
    cv::Vec3d pt0(cam0_points_undistorted[i].x,
        cam0_points_undistorted[i].y, 1.0);
    cv::Vec3d pt1(cam1_points_undistorted[i].x,
        cam1_points_undistorted[i].y, 1.0);
    cv::Vec3d epipolar_line = E * pt0;
    double error = fabs((pt1.t() * epipolar_line)[0]) / sqrt(
        epipolar_line[0]*epipolar_line[0]+
        epipolar_line[1]*epipolar_line[1]);
    if (error > processor_config.stereo_threshold*norm_pixel_unit)
      inlier_markers[i] = 0;
  }

  return;
}

void ImageProcessor::addNewFeatures() {
  #ifdef do_logging
  ros::Time start_time = ros::Time::now();
  #endif
  const Mat& curr_img = cam0_curr_img_ptr->image;

  // Size of each grid.
  static int grid_height =
    (cam0_curr_img_ptr->image.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
  static int grid_width =
    (cam0_curr_img_ptr->image.cols-2*processor_config.border_width_margin) / processor_config.grid_col;;

  // Create a mask to avoid redetecting existing features.
  Mat mask(curr_img.rows, curr_img.cols, CV_8U, Scalar(1)); //@todo: mask time can be reduced, by creating masks per grid
                                                            // because full and empty grids dont need to be created

  for (const auto& features : *curr_features_ptr) {
    for (const auto& feature : features.second) {
      const int y = static_cast<int>(feature.cam0_point.y);
      const int x = static_cast<int>(feature.cam0_point.x);

      int up_lim = y-2, bottom_lim = y+3,
          left_lim = x-2, right_lim = x+3;
      if (up_lim < 0) up_lim = 0;
      if (bottom_lim > curr_img.rows) bottom_lim = curr_img.rows;
      if (left_lim < 0) left_lim = 0;
      if (right_lim > curr_img.cols) right_lim = curr_img.cols;

      Range row_range(up_lim, bottom_lim);
      Range col_range(left_lim, right_lim);
      mask(row_range, col_range) = 0;
    }
  }
  #ifdef do_logging
  double mask_time = (ros::Time::now()-start_time).toSec();
  double grid_build_time = 0;
  double detection_time = 0;

  start_time = ros::Time::now();
  #endif
  // Detect new features.
  vector<KeyPoint> new_features(0);

  if (processor_config.detection_per_grid)
  {
    #ifdef do_logging
    ros::Time start_time = ros::Time::now();
    #endif
    int code = 0;
    static const int row_spacing = (curr_img.rows-processor_config.border_height_margin*2)/processor_config.grid_row;
    static const int col_spacing = (curr_img.cols-processor_config.border_width_margin*2)/processor_config.grid_col;
    //@todo: row_spacing equals grid width and col spacing grid heigt. remove unnecessary variable 
    #ifdef do_logging
    grid_build_time = (ros::Time::now()-start_time).toSec();
    #endif

    // int tot_vacancies = 0;
    for (int row=0; row<processor_config.grid_row; row++)
    {
      for (int col=0; col<processor_config.grid_col; col++)
      {
        #ifdef do_logging
        ros::Time start_time = ros::Time::now();
        #endif
        vector<FeatureMetaData>& features_this_grid = (*curr_features_ptr)[code];
        code++;
        int vacancy_num = processor_config.grid_min_feature_num - features_this_grid.size() - processor_config.free_features;
        // tot_vacancies += vacancy_num;
        // std::cout<<code<<", row:"<<row<<", col"<<col<<" vacancies: "<<vacancy_num<<std::endl;
        if (vacancy_num > 0)
        {
          #ifdef do_logging
          ros::Time start_time = ros::Time::now();
          #endif
          // std::cout<<row*row_spacing<< ", "<< col*col_spacing <<", " << row_spacing<<", "<< col_spacing<<std::endl;
          // std::cout<<curr_img.cols<< ", "<< curr_img.rows <<std::endl;
          cv::Rect myROI(col*col_spacing + processor_config.border_width_margin,
                          row*row_spacing + processor_config.border_height_margin,
                          col_spacing, row_spacing);
          cv::Mat grid_img = curr_img(myROI); // This is a reference to the image, so if I change image I don't need to recalculate this everytime?
          #ifdef do_logging
          grid_build_time += (ros::Time::now()-start_time).toSec();
          start_time = ros::Time::now();
          #endif
          if (processor_config.use_ActFAST)
          {
            static uint16_t num_corners;
            static const float longstep = processor_config.longstep;
            static const float shortstep = processor_config.shortstep;
            static const int gradientThreshold = processor_config.gradientThreshold;
            static const int gradientMethod = processor_config.gradientMethod;
            static const uint16_t n_agents = processor_config.n_agents; // 512 is maximum agents defined in opticflow_calculator.hpp
            static struct point_t* ret_corners = (struct point_t*) calloc(n_agents, sizeof(struct point_t));

            static const uint8_t fast_threshold = processor_config.fast_threshold;
            static const uint16_t n_time_steps = processor_config.n_time_steps;

            act_fast(&grid_img, fast_threshold, &num_corners, &ret_corners,
                        n_agents, n_time_steps, longstep, shortstep, gradientThreshold, gradientMethod);

            // std::cout<<"num corners: "<<num_corners<<std::endl;
            for (int i=0; i< num_corners; i++)
            {
              // std::cout<<i<<std::endl;
              if (mask.at<int>(ret_corners[i].y + row*row_spacing, ret_corners[i].x + col*col_spacing) != 0)
              {
                // std::cout<<"test: "<<std::endl;
                KeyPoint kp;
                kp.pt = Point2f (ret_corners[i].x + col*col_spacing, ret_corners[i].y + row*row_spacing);
                // std::cout<<ret_corners[i].x + col*col_spacing<<", "<< ret_corners[i].y + row*row_spacing<<std::endl;
                // std::cout<<ret_corners[i].x <<", "<< ret_corners[i].y<<std::endl;
                kp.response = float ( fast9_corner_score(&grid_img, fast_threshold, ret_corners[i].x, ret_corners[i].y) );
                // if (kp.response !=  fast9_corner_score(&curr_img, fast_threshold, kp.pt.x, kp.pt.y) )
                // {
                //   std::cout<<"SOMETHING WRONG!!"<<std::endl;
                // }
                // std::cout<<"response: "<<kp.response<<std::endl;
                new_features.push_back(kp);
              }
            }
          }
          else
          {
            vector<KeyPoint> new_features_grid(0);
            detector_ptr->detect(grid_img, new_features_grid, mask); // @todo: make masks per grid, else it might not even work
            KeyPoint kp;
            for (int i=0; i<new_features_grid.size(); i++)           // and it will decrease computation time
            {
                kp.pt = Point2f (new_features_grid[i].pt.x + col*col_spacing + processor_config.border_width_margin,
                                new_features_grid[i].pt.y + row*row_spacing + processor_config.border_height_margin);
                kp.response = new_features_grid[i].response;
                new_features.push_back(kp);
            }
          }
          #ifdef do_logging
          detection_time += (ros::Time::now()-start_time).toSec();
          #endif

        }
        // else
        // {
        //   std::cout<<features_this_grid[0].cam0_point.x <<", "<<features_this_grid[0].cam0_point.y<<std::endl;
        // }

      }
    }
    // std::cout<<"total vacancies: "<<tot_vacancies<<std::endl;
  }
  else
  {
    #ifdef do_logging
    ros::Time start_time = ros::Time::now();
    #endif
    if (processor_config.use_ActFAST)
    {
      static uint16_t num_corners;
      static const float longstep = processor_config.longstep;
      static const float shortstep = processor_config.shortstep;
      static const int gradientThreshold = processor_config.gradientThreshold;
      static const int gradientMethod = processor_config.gradientMethod;
      static const uint16_t n_agents = processor_config.n_agents; // 512 is maximum agents defined in opticflow_calculator.hpp
      static struct point_t* ret_corners = (struct point_t*) calloc(n_agents, sizeof(struct point_t));

      static const uint8_t fast_threshold = processor_config.fast_threshold;
      static const uint16_t n_time_steps = processor_config.n_time_steps;

      act_fast(&curr_img, fast_threshold, &num_corners, &ret_corners,
                  n_agents, n_time_steps, longstep, shortstep, gradientThreshold, gradientMethod);

      for (int i=0; i< num_corners; i++)
      {
        if (mask.at<int>(ret_corners[i].y, ret_corners[i].x) != 0)
        {
          KeyPoint kp;
          kp.pt = Point2f (ret_corners[i].x, ret_corners[i].y);
          kp.response = float ( fast9_corner_score(&curr_img, fast_threshold, ret_corners[i].x, ret_corners[i].y) );
          new_features.push_back(kp);
        }
      }
    }
    else detector_ptr->detect(curr_img, new_features, mask);

    #ifdef do_logging
    detection_time = (ros::Time::now()-start_time).toSec();
    #endif
  }
  #ifdef do_logging
  double detection_time_total = (ros::Time::now()-start_time).toSec();
  #endif

  // Collect the new detected features based on the grid.
  // Select the ones with top response within each grid afterwards.
  #ifdef do_logging
  start_time = ros::Time::now();
  #endif
  vector<vector<KeyPoint> > new_feature_sieve(
      processor_config.grid_row*processor_config.grid_col);
  for (const auto& feature : new_features) {
    int row = static_cast<int>((feature.pt.y-processor_config.border_height_margin) / grid_height);
    int col = static_cast<int>((feature.pt.x-processor_config.border_width_margin) / grid_width);
    new_feature_sieve[
      row*processor_config.grid_col+col].push_back(feature);
  }

  new_features.clear();
  for (auto& item : new_feature_sieve) {
    if (item.size() > processor_config.grid_max_feature_num) {
      std::sort(item.begin(), item.end(),
          &ImageProcessor::keyPointCompareByResponse);
      item.erase(
          item.begin()+processor_config.grid_max_feature_num, item.end());
    }
    new_features.insert(new_features.end(), item.begin(), item.end());
  }

  #ifdef do_logging
  int detected_new_features = new_features.size();
  double selectfeature_time1 = (ros::Time::now()-start_time).toSec();

  // Find the stereo matched points for the newly
  // detected features.
  start_time = ros::Time::now();
  #endif
  vector<cv::Point2f> cam0_points(new_features.size());
  for (int i = 0; i < new_features.size(); ++i)
    cam0_points[i] = new_features[i].pt;

  vector<cv::Point2f> cam1_points(0);
  vector<unsigned char> inlier_markers(0);
  stereoMatch(cam0_points, cam1_points, inlier_markers);

  vector<cv::Point2f> cam0_inliers(0);
  vector<cv::Point2f> cam1_inliers(0);
  vector<float> response_inliers(0);
  for (int i = 0; i < inlier_markers.size(); ++i) {
    if (inlier_markers[i] == 0) continue;
    cam0_inliers.push_back(cam0_points[i]);
    cam1_inliers.push_back(cam1_points[i]);
    response_inliers.push_back(new_features[i].response);
  }

  #ifdef do_logging
  int matched_new_features = cam0_inliers.size();

  // if (matched_new_features < 5 &&
  //     static_cast<double>(matched_new_features)/
  //     static_cast<double>(detected_new_features) < 0.1)
  //   ROS_WARN("Images at [%f] seems unsynced...",
  //       cam0_curr_img_ptr->header.stamp.toSec());
  double stereo_time = (ros::Time::now()-start_time).toSec();

  // Group the features into grids
  start_time = ros::Time::now();
  #endif
  GridFeatures grid_new_features;
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code)
      grid_new_features[code] = vector<FeatureMetaData>(0);

  for (int i = 0; i < cam0_inliers.size(); ++i) {
    const cv::Point2f& cam0_point = cam0_inliers[i];
    const cv::Point2f& cam1_point = cam1_inliers[i];
    const float& response = response_inliers[i];

    int row = static_cast<int>((cam0_point.y-processor_config.border_height_margin) / grid_height);
    int col = static_cast<int>((cam0_point.x-processor_config.border_width_margin) / grid_width);
    int code = row*processor_config.grid_col + col;

    FeatureMetaData new_feature;
    new_feature.response = response;
    new_feature.cam0_point = cam0_point;
    new_feature.cam1_point = cam1_point;
    grid_new_features[code].push_back(new_feature);
  }

  // Sort the new features in each grid based on its response.
  for (auto& item : grid_new_features)
    std::sort(item.second.begin(), item.second.end(),
        &ImageProcessor::featureCompareByResponse);

  int new_added_feature_num = 0;
  // std::cout<<"AddNewFeatures:"<<std::endl;
  // Collect new features within each grid with high response.
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code) {
    vector<FeatureMetaData>& features_this_grid = (*curr_features_ptr)[code];
    vector<FeatureMetaData>& new_features_this_grid = grid_new_features[code];

    // std::cout<<features_this_grid.size()<<", ";
    if (features_this_grid.size() >=
        processor_config.grid_min_feature_num) continue;

    int vacancy_num = processor_config.grid_min_feature_num -
      features_this_grid.size();


    if (new_features_this_grid.size() > 0 && vacancy_num ==0 )
    {
      std::cout<<"WARNING Je doet iets fout want dit zou niet mogen gebeuren!"<<std::endl;
    }
    
    for (int k = 0;
        k < vacancy_num && k < new_features_this_grid.size(); ++k) {
      features_this_grid.push_back(new_features_this_grid[k]);
      features_this_grid.back().id = next_feature_id++;
      features_this_grid.back().lifetime = 1;

      ++new_added_feature_num;
    }


  }
  #ifdef do_logging
  double selectfeature_time2 = (ros::Time::now()-start_time).toSec();
  
  std::ofstream featuretimefile;
  featuretimefile.open ("features.txt", std::ios_base::app);
  featuretimefile << mask_time << ' ' << grid_build_time << ' ' << detection_time << ' ' << detection_time_total << ' ' 
    << stereo_time << ' ' << selectfeature_time1 << ' ' << selectfeature_time2 << '\n';
  featuretimefile.close();
  #endif
  // std::cout<<std::endl;

  //printf("\033[0;33m detected: %d; matched: %d; new added feature: %d\033[0m\n",
  //    detected_new_features, matched_new_features, new_added_feature_num);

  return;
}

void ImageProcessor::pruneGridFeatures() {
  // std::cout<<"PruneGridFeatures:"<<std::endl;
  for (auto& item : *curr_features_ptr) {
    auto& grid_features = item.second;
    // Continue if the number of features in this grid does
    // not exceed the upper bound.
    // for (int i=0; i<grid_features.size(); i++)
    // {
    //   std::cout<<grid_features[i].lifetime<<std::endl;
    // }

    // std::cout<<grid_features.size()<<", ";

    if (grid_features.size() <=
        processor_config.grid_max_feature_num) continue;
    std::sort(grid_features.begin(), grid_features.end(),
        &ImageProcessor::featureCompareByLifetime);
      // std::cout<<"ja hoor test: "<<grid_features.size()<<std::endl;
      // for (int i=0; i<grid_features.size(); i++)
      // {
      //   std::cout<<grid_features[i].lifetime<<std::endl;
      // }
    grid_features.erase(grid_features.begin()+
        processor_config.grid_max_feature_num,
        grid_features.end());
  }
  // std::cout<<std::endl;

  return;
}

void ImageProcessor::undistortPoints(
    const vector<cv::Point2f>& pts_in,
    const cv::Vec4d& intrinsics,
    const string& distortion_model,
    const cv::Vec4d& distortion_coeffs,
    vector<cv::Point2f>& pts_out,
    const cv::Matx33d &rectification_matrix,
    const cv::Vec4d &new_intrinsics) {

  if (pts_in.size() == 0) return;

  const cv::Matx33d K(
      intrinsics[0], 0.0, intrinsics[2],
      0.0, intrinsics[1], intrinsics[3],
      0.0, 0.0, 1.0);

  const cv::Matx33d K_new(
      new_intrinsics[0], 0.0, new_intrinsics[2],
      0.0, new_intrinsics[1], new_intrinsics[3],
      0.0, 0.0, 1.0);

  if (distortion_model == "radtan") {
    cv::undistortPoints(pts_in, pts_out, K, distortion_coeffs,
                        rectification_matrix, K_new);
  } else if (distortion_model == "equidistant") {
    cv::fisheye::undistortPoints(pts_in, pts_out, K, distortion_coeffs,
                                 rectification_matrix, K_new);
  } else {
    ROS_WARN_ONCE("The model %s is unrecognized, use radtan instead...",
                  distortion_model.c_str());
    cv::undistortPoints(pts_in, pts_out, K, distortion_coeffs,
                        rectification_matrix, K_new);
  }

  return;
}

vector<cv::Point2f> ImageProcessor::distortPoints(
    const vector<cv::Point2f>& pts_in,
    const cv::Vec4d& intrinsics,
    const string& distortion_model,
    const cv::Vec4d& distortion_coeffs) {

  const cv::Matx33d K(intrinsics[0], 0.0, intrinsics[2],
                      0.0, intrinsics[1], intrinsics[3],
                      0.0, 0.0, 1.0);

  vector<cv::Point2f> pts_out;
  if (distortion_model == "radtan") {
    vector<cv::Point3f> homogenous_pts;
    cv::convertPointsToHomogeneous(pts_in, homogenous_pts);
    cv::projectPoints(homogenous_pts, cv::Vec3d::zeros(), cv::Vec3d::zeros(), K,
                      distortion_coeffs, pts_out);
  } else if (distortion_model == "equidistant") {
    cv::fisheye::distortPoints(pts_in, pts_out, K, distortion_coeffs);
  } else {
    ROS_WARN_ONCE("The model %s is unrecognized, using radtan instead...",
                  distortion_model.c_str());
    vector<cv::Point3f> homogenous_pts;
    cv::convertPointsToHomogeneous(pts_in, homogenous_pts);
    cv::projectPoints(homogenous_pts, cv::Vec3d::zeros(), cv::Vec3d::zeros(), K,
                      distortion_coeffs, pts_out);
  }

  return pts_out;
}

void ImageProcessor::integrateImuData(
    Matx33f& cam0_R_p_c, Matx33f& cam1_R_p_c) {
  // Find the start and the end limit within the imu msg buffer.
  auto begin_iter = imu_msg_buffer.begin();
  while (begin_iter != imu_msg_buffer.end()) {
    if ((begin_iter->header.stamp-
          cam0_prev_img_ptr->header.stamp).toSec() < -0.01)
      ++begin_iter;
    else
      break;
  }

  auto end_iter = begin_iter;
  while (end_iter != imu_msg_buffer.end()) {
    if ((end_iter->header.stamp-
          cam0_curr_img_ptr->header.stamp).toSec() < 0.005)
      ++end_iter;
    else
      break;
  }

  // Compute the mean angular velocity in the IMU frame.
  Vec3f mean_ang_vel(0.0, 0.0, 0.0);
  if (processor_config.use_bias_correction)
  {
    for (auto iter = begin_iter; iter < end_iter; ++iter)
      mean_ang_vel += Vec3f(iter->angular_velocity.x - imu_gyro_bias[0],
          iter->angular_velocity.y - imu_gyro_bias[1], iter->angular_velocity.z - imu_gyro_bias[2]);
  }
  else
  {
    for (auto iter = begin_iter; iter < end_iter; ++iter)
      mean_ang_vel += Vec3f(iter->angular_velocity.x, iter->angular_velocity.y,
          iter->angular_velocity.z);
  }


  if (end_iter-begin_iter > 0)
    mean_ang_vel *= 1.0f / (end_iter-begin_iter);

  // Transform the mean angular velocity from the IMU
  // frame to the cam0 and cam1 frames.
  Vec3f cam0_mean_ang_vel = R_cam0_imu.t() * mean_ang_vel;
  Vec3f cam1_mean_ang_vel = R_cam1_imu.t() * mean_ang_vel;

  // Compute the relative rotation.
  double dtime = (cam0_curr_img_ptr->header.stamp-
      cam0_prev_img_ptr->header.stamp).toSec();
  Rodrigues(cam0_mean_ang_vel*dtime, cam0_R_p_c);
  Rodrigues(cam1_mean_ang_vel*dtime, cam1_R_p_c);
  cam0_R_p_c = cam0_R_p_c.t();
  cam1_R_p_c = cam1_R_p_c.t();

  // Delete the useless and used imu messages.
  imu_msg_buffer.erase(imu_msg_buffer.begin(), end_iter);
  return;
}

void ImageProcessor::rescalePoints(
    vector<Point2f>& pts1, vector<Point2f>& pts2,
    float& scaling_factor) {

  scaling_factor = 0.0f;

  for (int i = 0; i < pts1.size(); ++i) {
    scaling_factor += sqrt(pts1[i].dot(pts1[i]));
    scaling_factor += sqrt(pts2[i].dot(pts2[i]));
  }

  scaling_factor = (pts1.size()+pts2.size()) /
    scaling_factor * sqrt(2.0f);

  for (int i = 0; i < pts1.size(); ++i) {
    pts1[i] *= scaling_factor;
    pts2[i] *= scaling_factor;
  }

  return;
}

void ImageProcessor::twoPointRansac(
    const vector<Point2f>& pts1, const vector<Point2f>& pts2,
    const cv::Matx33f& R_p_c, const cv::Vec4d& intrinsics,
    const std::string& distortion_model,
    const cv::Vec4d& distortion_coeffs,
    const double& inlier_error,
    const double& success_probability,
    vector<int>& inlier_markers) {

  // Check the size of input point size.
  if (pts1.size() != pts2.size())
    ROS_ERROR("Sets of different size (%lu and %lu) are used...",
        pts1.size(), pts2.size());

  double norm_pixel_unit = 2.0 / (intrinsics[0]+intrinsics[1]);
  int iter_num = static_cast<int>(
      ceil(log(1-success_probability) / log(1-0.7*0.7)));

  // Initially, mark all points as inliers.
  inlier_markers.clear();
  inlier_markers.resize(pts1.size(), 1);

  // Undistort all the points.
  vector<Point2f> pts1_undistorted(pts1.size());
  vector<Point2f> pts2_undistorted(pts2.size());
  undistortPoints(
      pts1, intrinsics, distortion_model,
      distortion_coeffs, pts1_undistorted);
  undistortPoints(
      pts2, intrinsics, distortion_model,
      distortion_coeffs, pts2_undistorted);

  // Compenstate the points in the previous image with
  // the relative rotation.
  for (auto& pt : pts1_undistorted) {
    Vec3f pt_h(pt.x, pt.y, 1.0f);
    //Vec3f pt_hc = dR * pt_h;
    Vec3f pt_hc = R_p_c * pt_h;
    pt.x = pt_hc[0];
    pt.y = pt_hc[1];
  }

  // Normalize the points to gain numerical stability.
  float scaling_factor = 0.0f;
  rescalePoints(pts1_undistorted, pts2_undistorted, scaling_factor);
  norm_pixel_unit *= scaling_factor;

  // Compute the difference between previous and current points,
  // which will be used frequently later.
  vector<Point2d> pts_diff(pts1_undistorted.size());
  for (int i = 0; i < pts1_undistorted.size(); ++i)
    pts_diff[i] = pts1_undistorted[i] - pts2_undistorted[i];

  // Mark the point pairs with large difference directly.
  // BTW, the mean distance of the rest of the point pairs
  // are computed.
  double mean_pt_distance = 0.0;
  int raw_inlier_cntr = 0;
  for (int i = 0; i < pts_diff.size(); ++i) {
    double distance = sqrt(pts_diff[i].dot(pts_diff[i]));
    // 25 pixel distance is a pretty large tolerance for normal motion.
    // However, to be used with aggressive motion, this tolerance should
    // be increased significantly to match the usage.
    if (distance > 50.0*norm_pixel_unit) {
      inlier_markers[i] = 0;
    } else {
      mean_pt_distance += distance;
      ++raw_inlier_cntr;
    }
  }
  mean_pt_distance /= raw_inlier_cntr;

  // If the current number of inliers is less than 3, just mark
  // all input as outliers. This case can happen with fast
  // rotation where very few features are tracked.
  if (raw_inlier_cntr < 3) {
    for (auto& marker : inlier_markers) marker = 0;
    return;
  }

  // Before doing 2-point RANSAC, we have to check if the motion
  // is degenerated, meaning that there is no translation between
  // the frames, in which case, the model of the RANSAC does not
  // work. If so, the distance between the matched points will
  // be almost 0.
  //if (mean_pt_distance < inlier_error*norm_pixel_unit) {
  if (mean_pt_distance < norm_pixel_unit) {
    //ROS_WARN_THROTTLE(1.0, "Degenerated motion...");
    for (int i = 0; i < pts_diff.size(); ++i) {
      if (inlier_markers[i] == 0) continue;
      if (sqrt(pts_diff[i].dot(pts_diff[i])) >
          inlier_error*norm_pixel_unit)
        inlier_markers[i] = 0;
    }
    return;
  }

  // In the case of general motion, the RANSAC model can be applied.
  // The three column corresponds to tx, ty, and tz respectively.
  MatrixXd coeff_t(pts_diff.size(), 3);
  for (int i = 0; i < pts_diff.size(); ++i) {
    coeff_t(i, 0) = pts_diff[i].y;
    coeff_t(i, 1) = -pts_diff[i].x;
    coeff_t(i, 2) = pts1_undistorted[i].x*pts2_undistorted[i].y -
      pts1_undistorted[i].y*pts2_undistorted[i].x;
  }

  vector<int> raw_inlier_idx;
  for (int i = 0; i < inlier_markers.size(); ++i) {
    if (inlier_markers[i] != 0)
      raw_inlier_idx.push_back(i);
  }

  vector<int> best_inlier_set;
  double best_error = 1e10;
  random_numbers::RandomNumberGenerator random_gen;

  for (int iter_idx = 0; iter_idx < iter_num; ++iter_idx) {
    // Randomly select two point pairs.
    // Although this is a weird way of selecting two pairs, but it
    // is able to efficiently avoid selecting repetitive pairs.
    int select_idx1 = random_gen.uniformInteger(
        0, raw_inlier_idx.size()-1);
    int select_idx_diff = random_gen.uniformInteger(
        1, raw_inlier_idx.size()-1);
    int select_idx2 = select_idx1+select_idx_diff<raw_inlier_idx.size() ?
      select_idx1+select_idx_diff :
      select_idx1+select_idx_diff-raw_inlier_idx.size();

    int pair_idx1 = raw_inlier_idx[select_idx1];
    int pair_idx2 = raw_inlier_idx[select_idx2];

    // Construct the model;
    Vector2d coeff_tx(coeff_t(pair_idx1, 0), coeff_t(pair_idx2, 0));
    Vector2d coeff_ty(coeff_t(pair_idx1, 1), coeff_t(pair_idx2, 1));
    Vector2d coeff_tz(coeff_t(pair_idx1, 2), coeff_t(pair_idx2, 2));
    vector<double> coeff_l1_norm(3);
    coeff_l1_norm[0] = coeff_tx.lpNorm<1>();
    coeff_l1_norm[1] = coeff_ty.lpNorm<1>();
    coeff_l1_norm[2] = coeff_tz.lpNorm<1>();
    int base_indicator = min_element(coeff_l1_norm.begin(),
        coeff_l1_norm.end())-coeff_l1_norm.begin();

    Vector3d model(0.0, 0.0, 0.0);
    if (base_indicator == 0) {
      Matrix2d A;
      A << coeff_ty, coeff_tz;
      Vector2d solution = A.inverse() * (-coeff_tx);
      model(0) = 1.0;
      model(1) = solution(0);
      model(2) = solution(1);
    } else if (base_indicator ==1) {
      Matrix2d A;
      A << coeff_tx, coeff_tz;
      Vector2d solution = A.inverse() * (-coeff_ty);
      model(0) = solution(0);
      model(1) = 1.0;
      model(2) = solution(1);
    } else {
      Matrix2d A;
      A << coeff_tx, coeff_ty;
      Vector2d solution = A.inverse() * (-coeff_tz);
      model(0) = solution(0);
      model(1) = solution(1);
      model(2) = 1.0;
    }

    // Find all the inliers among point pairs.
    VectorXd error = coeff_t * model;

    vector<int> inlier_set;
    for (int i = 0; i < error.rows(); ++i) {
      if (inlier_markers[i] == 0) continue;
      if (std::abs(error(i)) < inlier_error*norm_pixel_unit)
        inlier_set.push_back(i);
    }

    // If the number of inliers is small, the current
    // model is probably wrong.
    if (inlier_set.size() < 0.2*pts1_undistorted.size())
      continue;

    // Refit the model using all of the possible inliers.
    VectorXd coeff_tx_better(inlier_set.size());
    VectorXd coeff_ty_better(inlier_set.size());
    VectorXd coeff_tz_better(inlier_set.size());
    for (int i = 0; i < inlier_set.size(); ++i) {
      coeff_tx_better(i) = coeff_t(inlier_set[i], 0);
      coeff_ty_better(i) = coeff_t(inlier_set[i], 1);
      coeff_tz_better(i) = coeff_t(inlier_set[i], 2);
    }

    Vector3d model_better(0.0, 0.0, 0.0);
    if (base_indicator == 0) {
      MatrixXd A(inlier_set.size(), 2);
      A << coeff_ty_better, coeff_tz_better;
      Vector2d solution =
          (A.transpose() * A).inverse() * A.transpose() * (-coeff_tx_better);
      model_better(0) = 1.0;
      model_better(1) = solution(0);
      model_better(2) = solution(1);
    } else if (base_indicator ==1) {
      MatrixXd A(inlier_set.size(), 2);
      A << coeff_tx_better, coeff_tz_better;
      Vector2d solution =
          (A.transpose() * A).inverse() * A.transpose() * (-coeff_ty_better);
      model_better(0) = solution(0);
      model_better(1) = 1.0;
      model_better(2) = solution(1);
    } else {
      MatrixXd A(inlier_set.size(), 2);
      A << coeff_tx_better, coeff_ty_better;
      Vector2d solution =
          (A.transpose() * A).inverse() * A.transpose() * (-coeff_tz_better);
      model_better(0) = solution(0);
      model_better(1) = solution(1);
      model_better(2) = 1.0;
    }

    // Compute the error and upate the best model if possible.
    VectorXd new_error = coeff_t * model_better;

    double this_error = 0.0;
    for (const auto& inlier_idx : inlier_set)
      this_error += std::abs(new_error(inlier_idx));
    this_error /= inlier_set.size();

    if (inlier_set.size() > best_inlier_set.size()) {
      best_error = this_error;
      best_inlier_set = inlier_set;
    }
  }

  // Fill in the markers.
  inlier_markers.clear();
  inlier_markers.resize(pts1.size(), 0);
  for (const auto& inlier_idx : best_inlier_set)
    inlier_markers[inlier_idx] = 1;

  //printf("inlier ratio: %lu/%lu\n",
  //    best_inlier_set.size(), inlier_markers.size());

  return;
}

void ImageProcessor::publish() {

  // Publish features.
  CameraMeasurementPtr feature_msg_ptr(new CameraMeasurement);
  feature_msg_ptr->header.stamp = cam0_curr_img_ptr->header.stamp;

  vector<FeatureIDType> curr_ids(0);
  vector<Point2f> curr_cam0_points(0);
  vector<Point2f> curr_cam1_points(0);

  for (const auto& grid_features : (*curr_features_ptr)) {
    for (const auto& feature : grid_features.second) {
      curr_ids.push_back(feature.id);
      curr_cam0_points.push_back(feature.cam0_point);
      curr_cam1_points.push_back(feature.cam1_point);
    }
  }

  vector<Point2f> curr_cam0_points_undistorted(0);
  vector<Point2f> curr_cam1_points_undistorted(0);

  undistortPoints(
      curr_cam0_points, cam0_intrinsics, cam0_distortion_model,
      cam0_distortion_coeffs, curr_cam0_points_undistorted);
  undistortPoints(
      curr_cam1_points, cam1_intrinsics, cam1_distortion_model,
      cam1_distortion_coeffs, curr_cam1_points_undistorted);

  for (int i = 0; i < curr_ids.size(); ++i) {
    feature_msg_ptr->features.push_back(FeatureMeasurement());
    feature_msg_ptr->features[i].id = curr_ids[i];
    feature_msg_ptr->features[i].u0 = curr_cam0_points_undistorted[i].x;
    feature_msg_ptr->features[i].v0 = curr_cam0_points_undistorted[i].y;
    feature_msg_ptr->features[i].u1 = curr_cam1_points_undistorted[i].x;
    feature_msg_ptr->features[i].v1 = curr_cam1_points_undistorted[i].y;
  }

  feature_pub.publish(feature_msg_ptr);

  // Publish tracking info.
  TrackingInfoPtr tracking_info_msg_ptr(new TrackingInfo());
  tracking_info_msg_ptr->header.stamp = cam0_curr_img_ptr->header.stamp;
  tracking_info_msg_ptr->before_tracking = before_tracking;
  tracking_info_msg_ptr->after_tracking = after_tracking;
  tracking_info_msg_ptr->after_matching = after_matching;
  tracking_info_msg_ptr->after_ransac = after_ransac;
  tracking_info_pub.publish(tracking_info_msg_ptr);

  return;
}

void ImageProcessor::drawFeaturesMono() {
  // Colors for different features.
  Scalar tracked(0, 255, 0);
  Scalar new_feature(0, 255, 255);

  static int grid_height =
    (cam0_curr_img_ptr->image.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
  static int grid_width =
    (cam0_curr_img_ptr->image.cols-2*processor_config.border_width_margin) / processor_config.grid_col;;

  // Create an output image.
  int img_height = cam0_curr_img_ptr->image.rows;
  int img_width = cam0_curr_img_ptr->image.cols;
  Mat out_img(img_height, img_width, CV_8UC3);
  cvtColor(cam0_curr_img_ptr->image, out_img, CV_GRAY2RGB);

  // Draw grids on the image.
  for (int i = 1; i < processor_config.grid_row; ++i) {
    Point pt1(0, i*grid_height);
    Point pt2(img_width, i*grid_height);
    line(out_img, pt1, pt2, Scalar(255, 0, 0));
  }
  for (int i = 1; i < processor_config.grid_col; ++i) {
    Point pt1(i*grid_width, 0);
    Point pt2(i*grid_width, img_height);
    line(out_img, pt1, pt2, Scalar(255, 0, 0));
  }

  // Collect features ids in the previous frame.
  vector<FeatureIDType> prev_ids(0);
  for (const auto& grid_features : *prev_features_ptr)
    for (const auto& feature : grid_features.second)
      prev_ids.push_back(feature.id);

  // Collect feature points in the previous frame.
  map<FeatureIDType, Point2f> prev_points;
  for (const auto& grid_features : *prev_features_ptr)
    for (const auto& feature : grid_features.second)
      prev_points[feature.id] = feature.cam0_point;

  // Collect feature points in the current frame.
  map<FeatureIDType, Point2f> curr_points;
  for (const auto& grid_features : *curr_features_ptr)
    for (const auto& feature : grid_features.second)
      curr_points[feature.id] = feature.cam0_point;

  // Draw tracked features.
  for (const auto& id : prev_ids) {
    if (prev_points.find(id) != prev_points.end() &&
        curr_points.find(id) != curr_points.end()) {
      cv::Point2f prev_pt = prev_points[id];
      cv::Point2f curr_pt = curr_points[id];
      circle(out_img, curr_pt, 3, tracked);
      line(out_img, prev_pt, curr_pt, tracked, 1);

      prev_points.erase(id);
      curr_points.erase(id);
    }
  }

  // Draw new features.
  for (const auto& new_curr_point : curr_points) {
    cv::Point2f pt = new_curr_point.second;
    circle(out_img, pt, 3, new_feature, -1);
  }

  imshow("Feature", out_img);
  waitKey(5);
}

void ImageProcessor::drawFeaturesStereo() {

  if(debug_stereo_pub.getNumSubscribers() > 0)
  // if(true)
  {
    // Colors for different features.
    Scalar tracked(0, 255, 0);
    Scalar new_feature(0, 255, 255);

    static int grid_height =
      // (cam0_curr_img_ptr->image.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
      // (cam0_curr_img_ptr->image.rows-2*processor_config.border_height_margin) / processor_config.grid_row;
      cam0_curr_img_ptr->image.rows / processor_config.grid_row;

    static int grid_width =
      // (cam0_curr_img_ptr->image.cols-2*processor_config.border_width_margin) / processor_config.grid_col;;
      cam0_curr_img_ptr->image.cols / processor_config.grid_col;

    // Create an output image.
    int img_height = cam0_curr_img_ptr->image.rows;
    int img_width = cam0_curr_img_ptr->image.cols;
    Mat out_img(img_height, img_width*2, CV_8UC3);
    cvtColor(cam0_curr_img_ptr->image,
             out_img.colRange(0, img_width), CV_GRAY2RGB);
    cvtColor(cam1_curr_img_ptr->image,
             out_img.colRange(img_width, img_width*2), CV_GRAY2RGB);

    // Draw grids on the image.
    for (int i = 1; i < processor_config.grid_row; ++i) {
      Point pt1(0, i*grid_height);
      Point pt2(img_width*2, i*grid_height);
      line(out_img, pt1, pt2, Scalar(255, 0, 0));
    }
    for (int i = 1; i < processor_config.grid_col; ++i) {
      Point pt1(i*grid_width, 0);
      Point pt2(i*grid_width, img_height);
      line(out_img, pt1, pt2, Scalar(255, 0, 0));
    }
    for (int i = 1; i < processor_config.grid_col; ++i) {
      Point pt1(i*grid_width+img_width, 0);
      Point pt2(i*grid_width+img_width, img_height);
      line(out_img, pt1, pt2, Scalar(255, 0, 0));
    }

    // Collect features ids in the previous frame.
    vector<FeatureIDType> prev_ids(0);
    for (const auto& grid_features : *prev_features_ptr)
      for (const auto& feature : grid_features.second)
        prev_ids.push_back(feature.id);

    // Collect feature points in the previous frame.
    map<FeatureIDType, Point2f> prev_cam0_points;
    map<FeatureIDType, Point2f> prev_cam1_points;
    for (const auto& grid_features : *prev_features_ptr)
      for (const auto& feature : grid_features.second) {
        prev_cam0_points[feature.id] = feature.cam0_point;
        prev_cam1_points[feature.id] = feature.cam1_point;
      }

    // Collect feature points in the current frame.
    map<FeatureIDType, Point2f> curr_cam0_points;
    map<FeatureIDType, Point2f> curr_cam1_points;
    for (const auto& grid_features : *curr_features_ptr)
      for (const auto& feature : grid_features.second) {
        curr_cam0_points[feature.id] = feature.cam0_point;
        curr_cam1_points[feature.id] = feature.cam1_point;
      }

    // Draw tracked features.
    for (const auto& id : prev_ids) {
      if (prev_cam0_points.find(id) != prev_cam0_points.end() &&
          curr_cam0_points.find(id) != curr_cam0_points.end()) {
        cv::Point2f prev_pt0 = prev_cam0_points[id];
        cv::Point2f prev_pt1 = prev_cam1_points[id] + Point2f(img_width, 0.0);
        cv::Point2f curr_pt0 = curr_cam0_points[id];
        cv::Point2f curr_pt1 = curr_cam1_points[id] + Point2f(img_width, 0.0);

        circle(out_img, curr_pt0, 3, tracked, -1);
        circle(out_img, curr_pt1, 3, tracked, -1);
        line(out_img, prev_pt0, curr_pt0, tracked, 1);
        line(out_img, prev_pt1, curr_pt1, tracked, 1);

        prev_cam0_points.erase(id);
        prev_cam1_points.erase(id);
        curr_cam0_points.erase(id);
        curr_cam1_points.erase(id);
      }
    }

    // Draw new features.
    for (const auto& new_cam0_point : curr_cam0_points) {
      cv::Point2f pt0 = new_cam0_point.second;
      cv::Point2f pt1 = curr_cam1_points[new_cam0_point.first] +
        Point2f(img_width, 0.0);

      circle(out_img, pt0, 3, new_feature, -1);
      circle(out_img, pt1, 3, new_feature, -1);
    }

    cv_bridge::CvImage debug_image(cam0_curr_img_ptr->header, "bgr8", out_img);
    debug_stereo_pub.publish(debug_image.toImageMsg());
  }
  //imshow("Feature", out_img);
  //waitKey(5);

  return;
}

void ImageProcessor::updateFeatureLifetime() {
  for (int code = 0; code <
      processor_config.grid_row*processor_config.grid_col; ++code) {
    vector<FeatureMetaData>& features = (*curr_features_ptr)[code];
    for (const auto& feature : features) {
      if (feature_lifetime.find(feature.id) == feature_lifetime.end())
        feature_lifetime[feature.id] = 1;
      else
        ++feature_lifetime[feature.id];
    }
  }

  return;
}

void ImageProcessor::featureLifetimeStatistics() {

  map<int, int> lifetime_statistics;
  for (const auto& data : feature_lifetime) {
    if (lifetime_statistics.find(data.second) ==
        lifetime_statistics.end())
      lifetime_statistics[data.second] = 1;
    else
      ++lifetime_statistics[data.second];
  }

  for (const auto& data : lifetime_statistics)
    cout << data.first << " : " << data.second << endl;

  return;
}

} // end namespace msckf_vio
