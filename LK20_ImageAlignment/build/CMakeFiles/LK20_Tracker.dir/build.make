# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stavrow/Git/LK20_ImageAlignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stavrow/Git/LK20_ImageAlignment/build

# Include any dependencies generated for this target.
include CMakeFiles/LK20_Tracker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LK20_Tracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LK20_Tracker.dir/flags.make

CMakeFiles/LK20_Tracker.dir/LK_example.cc.o: CMakeFiles/LK20_Tracker.dir/flags.make
CMakeFiles/LK20_Tracker.dir/LK_example.cc.o: ../LK_example.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stavrow/Git/LK20_ImageAlignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LK20_Tracker.dir/LK_example.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LK20_Tracker.dir/LK_example.cc.o -c /home/stavrow/Git/LK20_ImageAlignment/LK_example.cc

CMakeFiles/LK20_Tracker.dir/LK_example.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LK20_Tracker.dir/LK_example.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stavrow/Git/LK20_ImageAlignment/LK_example.cc > CMakeFiles/LK20_Tracker.dir/LK_example.cc.i

CMakeFiles/LK20_Tracker.dir/LK_example.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LK20_Tracker.dir/LK_example.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stavrow/Git/LK20_ImageAlignment/LK_example.cc -o CMakeFiles/LK20_Tracker.dir/LK_example.cc.s

CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.requires:

.PHONY : CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.requires

CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.provides: CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.requires
	$(MAKE) -f CMakeFiles/LK20_Tracker.dir/build.make CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.provides.build
.PHONY : CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.provides

CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.provides.build: CMakeFiles/LK20_Tracker.dir/LK_example.cc.o


CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o: CMakeFiles/LK20_Tracker.dir/flags.make
CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o: ../src/Simulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stavrow/Git/LK20_ImageAlignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o -c /home/stavrow/Git/LK20_ImageAlignment/src/Simulator.cpp

CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stavrow/Git/LK20_ImageAlignment/src/Simulator.cpp > CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.i

CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stavrow/Git/LK20_ImageAlignment/src/Simulator.cpp -o CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.s

CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.requires:

.PHONY : CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.requires

CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.provides: CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.requires
	$(MAKE) -f CMakeFiles/LK20_Tracker.dir/build.make CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.provides.build
.PHONY : CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.provides

CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.provides.build: CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o


CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o: CMakeFiles/LK20_Tracker.dir/flags.make
CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o: ../src/LK20.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stavrow/Git/LK20_ImageAlignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o -c /home/stavrow/Git/LK20_ImageAlignment/src/LK20.cpp

CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stavrow/Git/LK20_ImageAlignment/src/LK20.cpp > CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.i

CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stavrow/Git/LK20_ImageAlignment/src/LK20.cpp -o CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.s

CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.requires:

.PHONY : CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.requires

CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.provides: CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.requires
	$(MAKE) -f CMakeFiles/LK20_Tracker.dir/build.make CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.provides.build
.PHONY : CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.provides

CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.provides.build: CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o


# Object files for target LK20_Tracker
LK20_Tracker_OBJECTS = \
"CMakeFiles/LK20_Tracker.dir/LK_example.cc.o" \
"CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o" \
"CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o"

# External object files for target LK20_Tracker
LK20_Tracker_EXTERNAL_OBJECTS =

LK20_Tracker: CMakeFiles/LK20_Tracker.dir/LK_example.cc.o
LK20_Tracker: CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o
LK20_Tracker: CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o
LK20_Tracker: CMakeFiles/LK20_Tracker.dir/build.make
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
LK20_Tracker: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
LK20_Tracker: CMakeFiles/LK20_Tracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stavrow/Git/LK20_ImageAlignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LK20_Tracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LK20_Tracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LK20_Tracker.dir/build: LK20_Tracker

.PHONY : CMakeFiles/LK20_Tracker.dir/build

CMakeFiles/LK20_Tracker.dir/requires: CMakeFiles/LK20_Tracker.dir/LK_example.cc.o.requires
CMakeFiles/LK20_Tracker.dir/requires: CMakeFiles/LK20_Tracker.dir/src/Simulator.cpp.o.requires
CMakeFiles/LK20_Tracker.dir/requires: CMakeFiles/LK20_Tracker.dir/src/LK20.cpp.o.requires

.PHONY : CMakeFiles/LK20_Tracker.dir/requires

CMakeFiles/LK20_Tracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LK20_Tracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LK20_Tracker.dir/clean

CMakeFiles/LK20_Tracker.dir/depend:
	cd /home/stavrow/Git/LK20_ImageAlignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stavrow/Git/LK20_ImageAlignment /home/stavrow/Git/LK20_ImageAlignment /home/stavrow/Git/LK20_ImageAlignment/build /home/stavrow/Git/LK20_ImageAlignment/build /home/stavrow/Git/LK20_ImageAlignment/build/CMakeFiles/LK20_Tracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LK20_Tracker.dir/depend

