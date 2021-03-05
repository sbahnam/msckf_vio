/*This is mechanically generated code*/
#include <stdlib.h>
#include "fast_9.hpp"

// typedef struct { int x, y; } xy; 
// typedef unsigned char byte;

// int fast9_corner_score(const byte* p, const int pixel[], int bstart)
int fast9_corner_score(const cv::Mat* img, uint8_t threshold, uint16_t x, uint16_t y)
{
    int bmin = threshold;
    int bmax = 255;
    int b = (bmax + bmin)/2;
    
    /*Compute the score using binary search*/
	for(;;)
    {
		int cb = img->at<uchar>(y,x) + b;
		int c_b= img->at<uchar>(y,x) - b;


        if( img->at<uchar>(y+3,x) > cb)
         if( img->at<uchar>(y+3,x+1) > cb)
          if( img->at<uchar>(y+2,x+2) > cb)
           if( img->at<uchar>(y+1,x+3) > cb)
            if( img->at<uchar>(y,x+3) > cb)
             if( img->at<uchar>(y-1,x+3) > cb)
              if( img->at<uchar>(y-2,x+2) > cb)
               if( img->at<uchar>(y-3,x+1) > cb)
                if( img->at<uchar>(y-3,x) > cb)
                 goto is_a_corner;
                else
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
               else if( img->at<uchar>(y-3,x+1) < c_b)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y-3,x) < c_b)
                  if( img->at<uchar>(y-3,x-1) < c_b)
                   if( img->at<uchar>(y-2,x-2) < c_b)
                    if( img->at<uchar>(y-1,x-3) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      if( img->at<uchar>(y+1,x-3) < c_b)
                       if( img->at<uchar>(y+3,x-1) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else if( img->at<uchar>(y-2,x+2) < c_b)
               if( img->at<uchar>(y+3,x-1) > cb)
                if( img->at<uchar>(y+1,x-3) > cb)
                 if( img->at<uchar>(y+2,x-2) > cb)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else if( img->at<uchar>(y+1,x-3) < c_b)
                 if( img->at<uchar>(y-3,x+1) < c_b)
                  if( img->at<uchar>(y-3,x) < c_b)
                   if( img->at<uchar>(y-3,x-1) < c_b)
                    if( img->at<uchar>(y-2,x-2) < c_b)
                     if( img->at<uchar>(y-1,x-3) < c_b)
                      if( img->at<uchar>(y,x-3) < c_b)
                       if( img->at<uchar>(y+2,x-2) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                if( img->at<uchar>(y-3,x+1) < c_b)
                 if( img->at<uchar>(y-3,x) < c_b)
                  if( img->at<uchar>(y-3,x-1) < c_b)
                   if( img->at<uchar>(y-2,x-2) < c_b)
                    if( img->at<uchar>(y-1,x-3) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      if( img->at<uchar>(y+1,x-3) < c_b)
                       if( img->at<uchar>(y+2,x-2) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y-3,x+1) < c_b)
                 if( img->at<uchar>(y-3,x) < c_b)
                  if( img->at<uchar>(y-3,x-1) < c_b)
                   if( img->at<uchar>(y-2,x-2) < c_b)
                    if( img->at<uchar>(y-1,x-3) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      if( img->at<uchar>(y+2,x-2) < c_b)
                       if( img->at<uchar>(y+3,x-1) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else if( img->at<uchar>(y-1,x+3) < c_b)
              if( img->at<uchar>(y+2,x-2) > cb)
               if( img->at<uchar>(y,x-3) > cb)
                if( img->at<uchar>(y+1,x-3) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       if( img->at<uchar>(y-1,x-3) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else if( img->at<uchar>(y,x-3) < c_b)
                if( img->at<uchar>(y-2,x+2) < c_b)
                 if( img->at<uchar>(y-3,x+1) < c_b)
                  if( img->at<uchar>(y-3,x) < c_b)
                   if( img->at<uchar>(y-3,x-1) < c_b)
                    if( img->at<uchar>(y-2,x-2) < c_b)
                     if( img->at<uchar>(y-1,x-3) < c_b)
                      if( img->at<uchar>(y+1,x-3) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y+2,x-2) < c_b)
               if( img->at<uchar>(y-3,x+1) < c_b)
                if( img->at<uchar>(y-3,x) < c_b)
                 if( img->at<uchar>(y-3,x-1) < c_b)
                  if( img->at<uchar>(y-2,x-2) < c_b)
                   if( img->at<uchar>(y-1,x-3) < c_b)
                    if( img->at<uchar>(y,x-3) < c_b)
                     if( img->at<uchar>(y+1,x-3) < c_b)
                      if( img->at<uchar>(y-2,x+2) < c_b)
                       goto is_a_corner;
                      else
                       if( img->at<uchar>(y+3,x-1) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x+2) < c_b)
                if( img->at<uchar>(y-3,x+1) < c_b)
                 if( img->at<uchar>(y-3,x) < c_b)
                  if( img->at<uchar>(y-3,x-1) < c_b)
                   if( img->at<uchar>(y-2,x-2) < c_b)
                    if( img->at<uchar>(y-1,x-3) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      if( img->at<uchar>(y+1,x-3) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       if( img->at<uchar>(y-1,x-3) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y-3,x+1) < c_b)
                if( img->at<uchar>(y-3,x) < c_b)
                 if( img->at<uchar>(y-3,x-1) < c_b)
                  if( img->at<uchar>(y-2,x-2) < c_b)
                   if( img->at<uchar>(y-1,x-3) < c_b)
                    if( img->at<uchar>(y+1,x-3) < c_b)
                     if( img->at<uchar>(y+2,x-2) < c_b)
                      if( img->at<uchar>(y-2,x+2) < c_b)
                       goto is_a_corner;
                      else
                       if( img->at<uchar>(y+3,x-1) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else if( img->at<uchar>(y,x+3) < c_b)
             if( img->at<uchar>(y+1,x-3) > cb)
              if( img->at<uchar>(y-1,x-3) > cb)
               if( img->at<uchar>(y,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y-1,x-3) < c_b)
               if( img->at<uchar>(y-1,x+3) < c_b)
                if( img->at<uchar>(y-2,x+2) < c_b)
                 if( img->at<uchar>(y-3,x+1) < c_b)
                  if( img->at<uchar>(y-3,x) < c_b)
                   if( img->at<uchar>(y-3,x-1) < c_b)
                    if( img->at<uchar>(y-2,x-2) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else if( img->at<uchar>(y+1,x-3) < c_b)
              if( img->at<uchar>(y-3,x+1) < c_b)
               if( img->at<uchar>(y-3,x) < c_b)
                if( img->at<uchar>(y-3,x-1) < c_b)
                 if( img->at<uchar>(y-2,x-2) < c_b)
                  if( img->at<uchar>(y-1,x-3) < c_b)
                   if( img->at<uchar>(y,x-3) < c_b)
                    if( img->at<uchar>(y-2,x+2) < c_b)
                     if( img->at<uchar>(y-1,x+3) < c_b)
                      goto is_a_corner;
                     else
                      if( img->at<uchar>(y+2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                    else
                     if( img->at<uchar>(y+2,x-2) < c_b)
                      if( img->at<uchar>(y+3,x-1) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              if( img->at<uchar>(y-1,x+3) < c_b)
               if( img->at<uchar>(y-2,x+2) < c_b)
                if( img->at<uchar>(y-3,x+1) < c_b)
                 if( img->at<uchar>(y-3,x) < c_b)
                  if( img->at<uchar>(y-3,x-1) < c_b)
                   if( img->at<uchar>(y-2,x-2) < c_b)
                    if( img->at<uchar>(y-1,x-3) < c_b)
                     if( img->at<uchar>(y,x-3) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      if( img->at<uchar>(y-2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y-3,x+1) < c_b)
               if( img->at<uchar>(y-3,x) < c_b)
                if( img->at<uchar>(y-3,x-1) < c_b)
                 if( img->at<uchar>(y-2,x-2) < c_b)
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    if( img->at<uchar>(y-2,x+2) < c_b)
                     if( img->at<uchar>(y-1,x+3) < c_b)
                      goto is_a_corner;
                     else
                      if( img->at<uchar>(y+2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                    else
                     if( img->at<uchar>(y+2,x-2) < c_b)
                      if( img->at<uchar>(y+3,x-1) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
           else if( img->at<uchar>(y+1,x+3) < c_b)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-3,x+1) < c_b)
              if( img->at<uchar>(y-3,x) < c_b)
               if( img->at<uchar>(y-3,x-1) < c_b)
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y-2,x+2) < c_b)
                  if( img->at<uchar>(y-1,x+3) < c_b)
                   if( img->at<uchar>(y,x+3) < c_b)
                    goto is_a_corner;
                   else
                    if( img->at<uchar>(y,x-3) < c_b)
                     if( img->at<uchar>(y+1,x-3) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y,x-3) < c_b)
                    if( img->at<uchar>(y+1,x-3) < c_b)
                     if( img->at<uchar>(y+2,x-2) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    if( img->at<uchar>(y+2,x-2) < c_b)
                     if( img->at<uchar>(y+3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     if( img->at<uchar>(y-3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-3,x+1) < c_b)
              if( img->at<uchar>(y-3,x) < c_b)
               if( img->at<uchar>(y-3,x-1) < c_b)
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-1,x+3) < c_b)
                    if( img->at<uchar>(y,x+3) < c_b)
                     goto is_a_corner;
                    else
                     if( img->at<uchar>(y+1,x-3) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    if( img->at<uchar>(y+1,x-3) < c_b)
                     if( img->at<uchar>(y+2,x-2) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    if( img->at<uchar>(y+2,x-2) < c_b)
                     if( img->at<uchar>(y+3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
          else if( img->at<uchar>(y+2,x+2) < c_b)
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-3,x+1) < c_b)
             if( img->at<uchar>(y-3,x) < c_b)
              if( img->at<uchar>(y-2,x-2) < c_b)
               if( img->at<uchar>(y-2,x+2) < c_b)
                if( img->at<uchar>(y-1,x+3) < c_b)
                 if( img->at<uchar>(y,x+3) < c_b)
                  if( img->at<uchar>(y+1,x+3) < c_b)
                   goto is_a_corner;
                  else
                   if( img->at<uchar>(y-1,x-3) < c_b)
                    if( img->at<uchar>(y,x-3) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y-1,x-3) < c_b)
                   if( img->at<uchar>(y,x-3) < c_b)
                    if( img->at<uchar>(y+1,x-3) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x-3) < c_b)
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    if( img->at<uchar>(y+2,x-2) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y+1,x-3) < c_b)
                   if( img->at<uchar>(y+2,x-2) < c_b)
                    if( img->at<uchar>(y+3,x-1) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    if( img->at<uchar>(y-3,x) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-3,x+1) < c_b)
             if( img->at<uchar>(y-3,x) < c_b)
              if( img->at<uchar>(y-2,x-2) < c_b)
               if( img->at<uchar>(y-1,x-3) < c_b)
                if( img->at<uchar>(y-2,x+2) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y,x+3) < c_b)
                   if( img->at<uchar>(y+1,x+3) < c_b)
                    goto is_a_corner;
                   else
                    if( img->at<uchar>(y,x-3) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y,x-3) < c_b)
                    if( img->at<uchar>(y+1,x-3) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    if( img->at<uchar>(y+2,x-2) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y+1,x-3) < c_b)
                   if( img->at<uchar>(y+2,x-2) < c_b)
                    if( img->at<uchar>(y+3,x-1) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
         else if( img->at<uchar>(y+3,x+1) < c_b)
          if( img->at<uchar>(y-3,x) > cb)
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y+2,x+2) > cb)
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else if( img->at<uchar>(y-3,x) < c_b)
           if( img->at<uchar>(y-3,x+1) < c_b)
            if( img->at<uchar>(y-3,x-1) < c_b)
             if( img->at<uchar>(y-2,x+2) < c_b)
              if( img->at<uchar>(y-1,x+3) < c_b)
               if( img->at<uchar>(y,x+3) < c_b)
                if( img->at<uchar>(y+1,x+3) < c_b)
                 if( img->at<uchar>(y+2,x+2) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x-2) < c_b)
                   if( img->at<uchar>(y-1,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-2,x-2) < c_b)
                  if( img->at<uchar>(y-1,x-3) < c_b)
                   if( img->at<uchar>(y,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-2,x-2) < c_b)
                 if( img->at<uchar>(y-1,x-3) < c_b)
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x-2) < c_b)
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y+1,x-3) < c_b)
                   if( img->at<uchar>(y+2,x-2) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y-2,x-2) < c_b)
               if( img->at<uchar>(y-1,x-3) < c_b)
                if( img->at<uchar>(y,x-3) < c_b)
                 if( img->at<uchar>(y+1,x-3) < c_b)
                  if( img->at<uchar>(y+2,x-2) < c_b)
                   if( img->at<uchar>(y+3,x-1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
         else
          if( img->at<uchar>(y-3,x) > cb)
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y+3,x-1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y+2,x+2) > cb)
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-3,x+1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else if( img->at<uchar>(y-3,x) < c_b)
           if( img->at<uchar>(y-3,x+1) < c_b)
            if( img->at<uchar>(y-3,x-1) < c_b)
             if( img->at<uchar>(y-2,x-2) < c_b)
              if( img->at<uchar>(y-2,x+2) < c_b)
               if( img->at<uchar>(y-1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y+1,x+3) < c_b)
                  if( img->at<uchar>(y+2,x+2) < c_b)
                   goto is_a_corner;
                  else
                   if( img->at<uchar>(y-1,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y-1,x-3) < c_b)
                   if( img->at<uchar>(y,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x-3) < c_b)
                  if( img->at<uchar>(y,x-3) < c_b)
                   if( img->at<uchar>(y+1,x-3) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y+1,x-3) < c_b)
                   if( img->at<uchar>(y+2,x-2) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-1,x-3) < c_b)
                if( img->at<uchar>(y,x-3) < c_b)
                 if( img->at<uchar>(y+1,x-3) < c_b)
                  if( img->at<uchar>(y+2,x-2) < c_b)
                   if( img->at<uchar>(y+3,x-1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
        else if( img->at<uchar>(y+3,x) < c_b)
         if( img->at<uchar>(y+3,x+1) > cb)
          if( img->at<uchar>(y-3,x) > cb)
           if( img->at<uchar>(y-3,x+1) > cb)
            if( img->at<uchar>(y-3,x-1) > cb)
             if( img->at<uchar>(y-2,x+2) > cb)
              if( img->at<uchar>(y-1,x+3) > cb)
               if( img->at<uchar>(y,x+3) > cb)
                if( img->at<uchar>(y+1,x+3) > cb)
                 if( img->at<uchar>(y+2,x+2) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x-2) > cb)
                   if( img->at<uchar>(y-1,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-2,x-2) > cb)
                  if( img->at<uchar>(y-1,x-3) > cb)
                   if( img->at<uchar>(y,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-2,x-2) > cb)
                 if( img->at<uchar>(y-1,x-3) > cb)
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x-2) > cb)
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y+1,x-3) > cb)
                   if( img->at<uchar>(y+2,x-2) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y-2,x-2) > cb)
               if( img->at<uchar>(y-1,x-3) > cb)
                if( img->at<uchar>(y,x-3) > cb)
                 if( img->at<uchar>(y+1,x-3) > cb)
                  if( img->at<uchar>(y+2,x-2) > cb)
                   if( img->at<uchar>(y+3,x-1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else if( img->at<uchar>(y-3,x) < c_b)
           if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y+2,x+2) < c_b)
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
         else if( img->at<uchar>(y+3,x+1) < c_b)
          if( img->at<uchar>(y+2,x+2) > cb)
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-3,x+1) > cb)
             if( img->at<uchar>(y-3,x) > cb)
              if( img->at<uchar>(y-2,x-2) > cb)
               if( img->at<uchar>(y-2,x+2) > cb)
                if( img->at<uchar>(y-1,x+3) > cb)
                 if( img->at<uchar>(y,x+3) > cb)
                  if( img->at<uchar>(y+1,x+3) > cb)
                   goto is_a_corner;
                  else
                   if( img->at<uchar>(y-1,x-3) > cb)
                    if( img->at<uchar>(y,x-3) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y-1,x-3) > cb)
                   if( img->at<uchar>(y,x-3) > cb)
                    if( img->at<uchar>(y+1,x-3) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x-3) > cb)
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    if( img->at<uchar>(y+2,x-2) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y+1,x-3) > cb)
                   if( img->at<uchar>(y+2,x-2) > cb)
                    if( img->at<uchar>(y+3,x-1) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else if( img->at<uchar>(y+2,x+2) < c_b)
           if( img->at<uchar>(y+1,x+3) > cb)
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-3,x+1) > cb)
              if( img->at<uchar>(y-3,x) > cb)
               if( img->at<uchar>(y-3,x-1) > cb)
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y-2,x+2) > cb)
                  if( img->at<uchar>(y-1,x+3) > cb)
                   if( img->at<uchar>(y,x+3) > cb)
                    goto is_a_corner;
                   else
                    if( img->at<uchar>(y,x-3) > cb)
                     if( img->at<uchar>(y+1,x-3) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y,x-3) > cb)
                    if( img->at<uchar>(y+1,x-3) > cb)
                     if( img->at<uchar>(y+2,x-2) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    if( img->at<uchar>(y+2,x-2) > cb)
                     if( img->at<uchar>(y+3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else if( img->at<uchar>(y+1,x+3) < c_b)
            if( img->at<uchar>(y,x+3) > cb)
             if( img->at<uchar>(y+1,x-3) > cb)
              if( img->at<uchar>(y-3,x+1) > cb)
               if( img->at<uchar>(y-3,x) > cb)
                if( img->at<uchar>(y-3,x-1) > cb)
                 if( img->at<uchar>(y-2,x-2) > cb)
                  if( img->at<uchar>(y-1,x-3) > cb)
                   if( img->at<uchar>(y,x-3) > cb)
                    if( img->at<uchar>(y-2,x+2) > cb)
                     if( img->at<uchar>(y-1,x+3) > cb)
                      goto is_a_corner;
                     else
                      if( img->at<uchar>(y+2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                    else
                     if( img->at<uchar>(y+2,x-2) > cb)
                      if( img->at<uchar>(y+3,x-1) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else if( img->at<uchar>(y+1,x-3) < c_b)
              if( img->at<uchar>(y-1,x-3) > cb)
               if( img->at<uchar>(y-1,x+3) > cb)
                if( img->at<uchar>(y-2,x+2) > cb)
                 if( img->at<uchar>(y-3,x+1) > cb)
                  if( img->at<uchar>(y-3,x) > cb)
                   if( img->at<uchar>(y-3,x-1) > cb)
                    if( img->at<uchar>(y-2,x-2) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y-1,x-3) < c_b)
               if( img->at<uchar>(y,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              if( img->at<uchar>(y-1,x+3) > cb)
               if( img->at<uchar>(y-2,x+2) > cb)
                if( img->at<uchar>(y-3,x+1) > cb)
                 if( img->at<uchar>(y-3,x) > cb)
                  if( img->at<uchar>(y-3,x-1) > cb)
                   if( img->at<uchar>(y-2,x-2) > cb)
                    if( img->at<uchar>(y-1,x-3) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else if( img->at<uchar>(y,x+3) < c_b)
             if( img->at<uchar>(y-1,x+3) > cb)
              if( img->at<uchar>(y+2,x-2) > cb)
               if( img->at<uchar>(y-3,x+1) > cb)
                if( img->at<uchar>(y-3,x) > cb)
                 if( img->at<uchar>(y-3,x-1) > cb)
                  if( img->at<uchar>(y-2,x-2) > cb)
                   if( img->at<uchar>(y-1,x-3) > cb)
                    if( img->at<uchar>(y,x-3) > cb)
                     if( img->at<uchar>(y+1,x-3) > cb)
                      if( img->at<uchar>(y-2,x+2) > cb)
                       goto is_a_corner;
                      else
                       if( img->at<uchar>(y+3,x-1) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y+2,x-2) < c_b)
               if( img->at<uchar>(y,x-3) > cb)
                if( img->at<uchar>(y-2,x+2) > cb)
                 if( img->at<uchar>(y-3,x+1) > cb)
                  if( img->at<uchar>(y-3,x) > cb)
                   if( img->at<uchar>(y-3,x-1) > cb)
                    if( img->at<uchar>(y-2,x-2) > cb)
                     if( img->at<uchar>(y-1,x-3) > cb)
                      if( img->at<uchar>(y+1,x-3) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else if( img->at<uchar>(y,x-3) < c_b)
                if( img->at<uchar>(y+1,x-3) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       if( img->at<uchar>(y-1,x-3) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x+2) > cb)
                if( img->at<uchar>(y-3,x+1) > cb)
                 if( img->at<uchar>(y-3,x) > cb)
                  if( img->at<uchar>(y-3,x-1) > cb)
                   if( img->at<uchar>(y-2,x-2) > cb)
                    if( img->at<uchar>(y-1,x-3) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      if( img->at<uchar>(y+1,x-3) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else if( img->at<uchar>(y-1,x+3) < c_b)
              if( img->at<uchar>(y-2,x+2) > cb)
               if( img->at<uchar>(y+3,x-1) < c_b)
                if( img->at<uchar>(y+1,x-3) > cb)
                 if( img->at<uchar>(y-3,x+1) > cb)
                  if( img->at<uchar>(y-3,x) > cb)
                   if( img->at<uchar>(y-3,x-1) > cb)
                    if( img->at<uchar>(y-2,x-2) > cb)
                     if( img->at<uchar>(y-1,x-3) > cb)
                      if( img->at<uchar>(y,x-3) > cb)
                       if( img->at<uchar>(y+2,x-2) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else if( img->at<uchar>(y+1,x-3) < c_b)
                 if( img->at<uchar>(y+2,x-2) < c_b)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                if( img->at<uchar>(y-3,x+1) > cb)
                 if( img->at<uchar>(y-3,x) > cb)
                  if( img->at<uchar>(y-3,x-1) > cb)
                   if( img->at<uchar>(y-2,x-2) > cb)
                    if( img->at<uchar>(y-1,x-3) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      if( img->at<uchar>(y+1,x-3) > cb)
                       if( img->at<uchar>(y+2,x-2) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else if( img->at<uchar>(y-2,x+2) < c_b)
               if( img->at<uchar>(y-3,x+1) > cb)
                if( img->at<uchar>(y+2,x-2) > cb)
                 if( img->at<uchar>(y-3,x) > cb)
                  if( img->at<uchar>(y-3,x-1) > cb)
                   if( img->at<uchar>(y-2,x-2) > cb)
                    if( img->at<uchar>(y-1,x-3) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      if( img->at<uchar>(y+1,x-3) > cb)
                       if( img->at<uchar>(y+3,x-1) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else if( img->at<uchar>(y-3,x+1) < c_b)
                if( img->at<uchar>(y-3,x) < c_b)
                 goto is_a_corner;
                else
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x-3) > cb)
                if( img->at<uchar>(y-3,x+1) > cb)
                 if( img->at<uchar>(y-3,x) > cb)
                  if( img->at<uchar>(y-3,x-1) > cb)
                   if( img->at<uchar>(y-2,x-2) > cb)
                    if( img->at<uchar>(y-1,x-3) > cb)
                     if( img->at<uchar>(y,x-3) > cb)
                      if( img->at<uchar>(y+2,x-2) > cb)
                       if( img->at<uchar>(y+3,x-1) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y,x-3) > cb)
               if( img->at<uchar>(y-3,x+1) > cb)
                if( img->at<uchar>(y-3,x) > cb)
                 if( img->at<uchar>(y-3,x-1) > cb)
                  if( img->at<uchar>(y-2,x-2) > cb)
                   if( img->at<uchar>(y-1,x-3) > cb)
                    if( img->at<uchar>(y+1,x-3) > cb)
                     if( img->at<uchar>(y+2,x-2) > cb)
                      if( img->at<uchar>(y-2,x+2) > cb)
                       goto is_a_corner;
                      else
                       if( img->at<uchar>(y+3,x-1) > cb)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       if( img->at<uchar>(y-1,x-3) < c_b)
                        goto is_a_corner;
                       else
                        goto is_not_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             if( img->at<uchar>(y-1,x-3) > cb)
              if( img->at<uchar>(y-3,x+1) > cb)
               if( img->at<uchar>(y-3,x) > cb)
                if( img->at<uchar>(y-3,x-1) > cb)
                 if( img->at<uchar>(y-2,x-2) > cb)
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    if( img->at<uchar>(y-2,x+2) > cb)
                     if( img->at<uchar>(y-1,x+3) > cb)
                      goto is_a_corner;
                     else
                      if( img->at<uchar>(y+2,x-2) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                    else
                     if( img->at<uchar>(y+2,x-2) > cb)
                      if( img->at<uchar>(y+3,x-1) > cb)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      if( img->at<uchar>(y-2,x-2) < c_b)
                       goto is_a_corner;
                      else
                       goto is_not_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
           else
            if( img->at<uchar>(y-2,x-2) > cb)
             if( img->at<uchar>(y-3,x+1) > cb)
              if( img->at<uchar>(y-3,x) > cb)
               if( img->at<uchar>(y-3,x-1) > cb)
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y-2,x+2) > cb)
                   if( img->at<uchar>(y-1,x+3) > cb)
                    if( img->at<uchar>(y,x+3) > cb)
                     goto is_a_corner;
                    else
                     if( img->at<uchar>(y+1,x-3) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                   else
                    if( img->at<uchar>(y+1,x-3) > cb)
                     if( img->at<uchar>(y+2,x-2) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y+1,x-3) > cb)
                    if( img->at<uchar>(y+2,x-2) > cb)
                     if( img->at<uchar>(y+3,x-1) > cb)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     if( img->at<uchar>(y-3,x-1) < c_b)
                      goto is_a_corner;
                     else
                      goto is_not_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
          else
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-3,x+1) > cb)
             if( img->at<uchar>(y-3,x) > cb)
              if( img->at<uchar>(y-2,x-2) > cb)
               if( img->at<uchar>(y-1,x-3) > cb)
                if( img->at<uchar>(y-2,x+2) > cb)
                 if( img->at<uchar>(y-1,x+3) > cb)
                  if( img->at<uchar>(y,x+3) > cb)
                   if( img->at<uchar>(y+1,x+3) > cb)
                    goto is_a_corner;
                   else
                    if( img->at<uchar>(y,x-3) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                  else
                   if( img->at<uchar>(y,x-3) > cb)
                    if( img->at<uchar>(y+1,x-3) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    if( img->at<uchar>(y+2,x-2) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y+1,x-3) > cb)
                   if( img->at<uchar>(y+2,x-2) > cb)
                    if( img->at<uchar>(y+3,x-1) > cb)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    if( img->at<uchar>(y-3,x) < c_b)
                     goto is_a_corner;
                    else
                     goto is_not_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
         else
          if( img->at<uchar>(y-3,x) > cb)
           if( img->at<uchar>(y-3,x+1) > cb)
            if( img->at<uchar>(y-3,x-1) > cb)
             if( img->at<uchar>(y-2,x-2) > cb)
              if( img->at<uchar>(y-2,x+2) > cb)
               if( img->at<uchar>(y-1,x+3) > cb)
                if( img->at<uchar>(y,x+3) > cb)
                 if( img->at<uchar>(y+1,x+3) > cb)
                  if( img->at<uchar>(y+2,x+2) > cb)
                   goto is_a_corner;
                  else
                   if( img->at<uchar>(y-1,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                 else
                  if( img->at<uchar>(y-1,x-3) > cb)
                   if( img->at<uchar>(y,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x-3) > cb)
                  if( img->at<uchar>(y,x-3) > cb)
                   if( img->at<uchar>(y+1,x-3) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y+1,x-3) > cb)
                   if( img->at<uchar>(y+2,x-2) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-1,x-3) > cb)
                if( img->at<uchar>(y,x-3) > cb)
                 if( img->at<uchar>(y+1,x-3) > cb)
                  if( img->at<uchar>(y+2,x-2) > cb)
                   if( img->at<uchar>(y+3,x-1) > cb)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else if( img->at<uchar>(y-3,x) < c_b)
           if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-2,x-2) < c_b)
             if( img->at<uchar>(y-1,x-3) < c_b)
              if( img->at<uchar>(y,x-3) < c_b)
               if( img->at<uchar>(y+1,x-3) < c_b)
                if( img->at<uchar>(y+2,x-2) < c_b)
                 if( img->at<uchar>(y+3,x-1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y+2,x+2) < c_b)
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y,x+3) < c_b)
                 if( img->at<uchar>(y-1,x+3) < c_b)
                  if( img->at<uchar>(y-2,x+2) < c_b)
                   if( img->at<uchar>(y-3,x+1) < c_b)
                    goto is_a_corner;
                   else
                    goto is_not_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
        else
         if( img->at<uchar>(y-3,x+1) > cb)
          if( img->at<uchar>(y-3,x) > cb)
           if( img->at<uchar>(y-3,x-1) > cb)
            if( img->at<uchar>(y-2,x+2) > cb)
             if( img->at<uchar>(y-1,x+3) > cb)
              if( img->at<uchar>(y,x+3) > cb)
               if( img->at<uchar>(y+1,x+3) > cb)
                if( img->at<uchar>(y+2,x+2) > cb)
                 if( img->at<uchar>(y+3,x+1) > cb)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x-2) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-2,x-2) > cb)
                  if( img->at<uchar>(y-1,x-3) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-2,x-2) > cb)
                 if( img->at<uchar>(y-1,x-3) > cb)
                  if( img->at<uchar>(y,x-3) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x-2) > cb)
                if( img->at<uchar>(y-1,x-3) > cb)
                 if( img->at<uchar>(y,x-3) > cb)
                  if( img->at<uchar>(y+1,x-3) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y-2,x-2) > cb)
               if( img->at<uchar>(y-1,x-3) > cb)
                if( img->at<uchar>(y,x-3) > cb)
                 if( img->at<uchar>(y+1,x-3) > cb)
                  if( img->at<uchar>(y+2,x-2) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             if( img->at<uchar>(y-2,x-2) > cb)
              if( img->at<uchar>(y-1,x-3) > cb)
               if( img->at<uchar>(y,x-3) > cb)
                if( img->at<uchar>(y+1,x-3) > cb)
                 if( img->at<uchar>(y+2,x-2) > cb)
                  if( img->at<uchar>(y+3,x-1) > cb)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
         else if( img->at<uchar>(y-3,x+1) < c_b)
          if( img->at<uchar>(y-3,x) < c_b)
           if( img->at<uchar>(y-3,x-1) < c_b)
            if( img->at<uchar>(y-2,x+2) < c_b)
             if( img->at<uchar>(y-1,x+3) < c_b)
              if( img->at<uchar>(y,x+3) < c_b)
               if( img->at<uchar>(y+1,x+3) < c_b)
                if( img->at<uchar>(y+2,x+2) < c_b)
                 if( img->at<uchar>(y+3,x+1) < c_b)
                  goto is_a_corner;
                 else
                  if( img->at<uchar>(y-2,x-2) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                else
                 if( img->at<uchar>(y-2,x-2) < c_b)
                  if( img->at<uchar>(y-1,x-3) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
               else
                if( img->at<uchar>(y-2,x-2) < c_b)
                 if( img->at<uchar>(y-1,x-3) < c_b)
                  if( img->at<uchar>(y,x-3) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
              else
               if( img->at<uchar>(y-2,x-2) < c_b)
                if( img->at<uchar>(y-1,x-3) < c_b)
                 if( img->at<uchar>(y,x-3) < c_b)
                  if( img->at<uchar>(y+1,x-3) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
             else
              if( img->at<uchar>(y-2,x-2) < c_b)
               if( img->at<uchar>(y-1,x-3) < c_b)
                if( img->at<uchar>(y,x-3) < c_b)
                 if( img->at<uchar>(y+1,x-3) < c_b)
                  if( img->at<uchar>(y+2,x-2) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
            else
             if( img->at<uchar>(y-2,x-2) < c_b)
              if( img->at<uchar>(y-1,x-3) < c_b)
               if( img->at<uchar>(y,x-3) < c_b)
                if( img->at<uchar>(y+1,x-3) < c_b)
                 if( img->at<uchar>(y+2,x-2) < c_b)
                  if( img->at<uchar>(y+3,x-1) < c_b)
                   goto is_a_corner;
                  else
                   goto is_not_a_corner;
                 else
                  goto is_not_a_corner;
                else
                 goto is_not_a_corner;
               else
                goto is_not_a_corner;
              else
               goto is_not_a_corner;
             else
              goto is_not_a_corner;
           else
            goto is_not_a_corner;
          else
           goto is_not_a_corner;
         else
          goto is_not_a_corner;

		is_a_corner:
			bmin=b;
			goto end_if;

		is_not_a_corner:
			bmax=b;
			goto end_if;

		end_if:

		if(bmin == bmax - 1 || bmin == bmax)
			return bmin;
		b = (bmin + bmax) / 2;
    }
}

// static void make_offsets(int pixel[], int row_stride)
// {
//         pixel[0] = 0 + row_stride * 3;
//         pixel[1] = 1 + row_stride * 3;
//         pixel[2] = 2 + row_stride * 2;
//         pixel[3] = 3 + row_stride * 1;
//         pixel[4] = 3 + row_stride * 0;
//         pixel[5] = 3 + row_stride * -1;
//         pixel[6] = 2 + row_stride * -2;
//         pixel[7] = 1 + row_stride * -3;
//         pixel[8] = 0 + row_stride * -3;
//         pixel[9] = -1 + row_stride * -3;
//         pixel[10] = -2 + row_stride * -2;
//         pixel[11] = -3 + row_stride * -1;
//         pixel[12] = -3 + row_stride * 0;
//         pixel[13] = -3 + row_stride * 1;
//         pixel[14] = -2 + row_stride * 2;
//         pixel[15] = -1 + row_stride * 3;
// }



// int* fast9_score(const byte* i, int stride, xy* corners, int num_corners, int b)
// {	
// 	int* scores = (int*)malloc(sizeof(int)* num_corners);
// 	int n;

// 	int pixel[16];
// 	make_offsets(pixel, stride);

//     for(n=0; n < num_corners; n++)
//         scores[n] = fast9_corner_score(i + corners[n].y*stride + corners[n].x, pixel, b);

// 	return scores;
// }


// xy* fast9_detect(const byte* im, int xsize, int ysize, int stride, int b, int* ret_num_corners)
// {
// 	int num_corners=0;
// 	xy* ret_corners;
// 	int rsize=512;
// 	int pixel[16];
// 	int x, y;

// 	ret_corners = (xy*)malloc(sizeof(xy)*rsize);
// 	make_offsets(pixel, stride);

// 	for(y=3; y < ysize - 3; y++)
// 		for(x=3; x < xsize - 3; x++)
// 		{
// 			const byte* p = im + y*stride + x;
		
// 			int cb = *p + b;
// 			int c_b= *p - b;
//         if(img->at<uchar>(y+3,x) > cb)
//          if(img->at<uchar>(y+3,x+1) > cb)
//           if(img->at<uchar>(y+2,x+2) > cb)
//            if(img->at<uchar>(y+1,x+3) > cb)
//             if(img->at<uchar>(y,x+3) > cb)
//              if(img->at<uchar>(y-1,x+3) > cb)
//               if(img->at<uchar>(y-2,x+2) > cb)
//                if(img->at<uchar>(y-3,x+1) > cb)
//                 if(img->at<uchar>(y-3,x) > cb)
//                  {}
//                 else
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   continue;
//                else if(img->at<uchar>(y-3,x+1) < c_b)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   continue;
//                 else if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y-3,x) < c_b)
//                   if(img->at<uchar>(y-3,x-1) < c_b)
//                    if(img->at<uchar>(y-2,x-2) < c_b)
//                     if(img->at<uchar>(y-1,x-3) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       if(img->at<uchar>(y+1,x-3) < c_b)
//                        if(img->at<uchar>(y+3,x-1) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//               else if(img->at<uchar>(y-2,x+2) < c_b)
//                if(img->at<uchar>(y+3,x-1) > cb)
//                 if(img->at<uchar>(y+1,x-3) > cb)
//                  if(img->at<uchar>(y+2,x-2) > cb)
//                   {}
//                  else
//                   continue;
//                 else if(img->at<uchar>(y+1,x-3) < c_b)
//                  if(img->at<uchar>(y-3,x+1) < c_b)
//                   if(img->at<uchar>(y-3,x) < c_b)
//                    if(img->at<uchar>(y-3,x-1) < c_b)
//                     if(img->at<uchar>(y-2,x-2) < c_b)
//                      if(img->at<uchar>(y-1,x-3) < c_b)
//                       if(img->at<uchar>(y,x-3) < c_b)
//                        if(img->at<uchar>(y+2,x-2) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 if(img->at<uchar>(y-3,x+1) < c_b)
//                  if(img->at<uchar>(y-3,x) < c_b)
//                   if(img->at<uchar>(y-3,x-1) < c_b)
//                    if(img->at<uchar>(y-2,x-2) < c_b)
//                     if(img->at<uchar>(y-1,x-3) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       if(img->at<uchar>(y+1,x-3) < c_b)
//                        if(img->at<uchar>(y+2,x-2) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//                else if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y-3,x+1) < c_b)
//                  if(img->at<uchar>(y-3,x) < c_b)
//                   if(img->at<uchar>(y-3,x-1) < c_b)
//                    if(img->at<uchar>(y-2,x-2) < c_b)
//                     if(img->at<uchar>(y-1,x-3) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       if(img->at<uchar>(y+2,x-2) < c_b)
//                        if(img->at<uchar>(y+3,x-1) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else if(img->at<uchar>(y-1,x+3) < c_b)
//               if(img->at<uchar>(y+2,x-2) > cb)
//                if(img->at<uchar>(y,x-3) > cb)
//                 if(img->at<uchar>(y+1,x-3) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        if(img->at<uchar>(y-1,x-3) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else if(img->at<uchar>(y,x-3) < c_b)
//                 if(img->at<uchar>(y-2,x+2) < c_b)
//                  if(img->at<uchar>(y-3,x+1) < c_b)
//                   if(img->at<uchar>(y-3,x) < c_b)
//                    if(img->at<uchar>(y-3,x-1) < c_b)
//                     if(img->at<uchar>(y-2,x-2) < c_b)
//                      if(img->at<uchar>(y-1,x-3) < c_b)
//                       if(img->at<uchar>(y+1,x-3) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y+2,x-2) < c_b)
//                if(img->at<uchar>(y-3,x+1) < c_b)
//                 if(img->at<uchar>(y-3,x) < c_b)
//                  if(img->at<uchar>(y-3,x-1) < c_b)
//                   if(img->at<uchar>(y-2,x-2) < c_b)
//                    if(img->at<uchar>(y-1,x-3) < c_b)
//                     if(img->at<uchar>(y,x-3) < c_b)
//                      if(img->at<uchar>(y+1,x-3) < c_b)
//                       if(img->at<uchar>(y-2,x+2) < c_b)
//                        {}
//                       else
//                        if(img->at<uchar>(y+3,x-1) < c_b)
//                         {}
//                        else
//                         continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                if(img->at<uchar>(y-2,x+2) < c_b)
//                 if(img->at<uchar>(y-3,x+1) < c_b)
//                  if(img->at<uchar>(y-3,x) < c_b)
//                   if(img->at<uchar>(y-3,x-1) < c_b)
//                    if(img->at<uchar>(y-2,x-2) < c_b)
//                     if(img->at<uchar>(y-1,x-3) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       if(img->at<uchar>(y+1,x-3) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        if(img->at<uchar>(y-1,x-3) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y-3,x+1) < c_b)
//                 if(img->at<uchar>(y-3,x) < c_b)
//                  if(img->at<uchar>(y-3,x-1) < c_b)
//                   if(img->at<uchar>(y-2,x-2) < c_b)
//                    if(img->at<uchar>(y-1,x-3) < c_b)
//                     if(img->at<uchar>(y+1,x-3) < c_b)
//                      if(img->at<uchar>(y+2,x-2) < c_b)
//                       if(img->at<uchar>(y-2,x+2) < c_b)
//                        {}
//                       else
//                        if(img->at<uchar>(y+3,x-1) < c_b)
//                         {}
//                        else
//                         continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else if(img->at<uchar>(y,x+3) < c_b)
//              if(img->at<uchar>(y+1,x-3) > cb)
//               if(img->at<uchar>(y-1,x-3) > cb)
//                if(img->at<uchar>(y,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y-1,x-3) < c_b)
//                if(img->at<uchar>(y-1,x+3) < c_b)
//                 if(img->at<uchar>(y-2,x+2) < c_b)
//                  if(img->at<uchar>(y-3,x+1) < c_b)
//                   if(img->at<uchar>(y-3,x) < c_b)
//                    if(img->at<uchar>(y-3,x-1) < c_b)
//                     if(img->at<uchar>(y-2,x-2) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else if(img->at<uchar>(y+1,x-3) < c_b)
//               if(img->at<uchar>(y-3,x+1) < c_b)
//                if(img->at<uchar>(y-3,x) < c_b)
//                 if(img->at<uchar>(y-3,x-1) < c_b)
//                  if(img->at<uchar>(y-2,x-2) < c_b)
//                   if(img->at<uchar>(y-1,x-3) < c_b)
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     if(img->at<uchar>(y-2,x+2) < c_b)
//                      if(img->at<uchar>(y-1,x+3) < c_b)
//                       {}
//                      else
//                       if(img->at<uchar>(y+2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                     else
//                      if(img->at<uchar>(y+2,x-2) < c_b)
//                       if(img->at<uchar>(y+3,x-1) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               if(img->at<uchar>(y-1,x+3) < c_b)
//                if(img->at<uchar>(y-2,x+2) < c_b)
//                 if(img->at<uchar>(y-3,x+1) < c_b)
//                  if(img->at<uchar>(y-3,x) < c_b)
//                   if(img->at<uchar>(y-3,x-1) < c_b)
//                    if(img->at<uchar>(y-2,x-2) < c_b)
//                     if(img->at<uchar>(y-1,x-3) < c_b)
//                      if(img->at<uchar>(y,x-3) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       if(img->at<uchar>(y-2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else
//                continue;
//              else if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y-3,x+1) < c_b)
//                if(img->at<uchar>(y-3,x) < c_b)
//                 if(img->at<uchar>(y-3,x-1) < c_b)
//                  if(img->at<uchar>(y-2,x-2) < c_b)
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     if(img->at<uchar>(y-2,x+2) < c_b)
//                      if(img->at<uchar>(y-1,x+3) < c_b)
//                       {}
//                      else
//                       if(img->at<uchar>(y+2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                     else
//                      if(img->at<uchar>(y+2,x-2) < c_b)
//                       if(img->at<uchar>(y+3,x-1) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//            else if(img->at<uchar>(y+1,x+3) < c_b)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-3,x+1) < c_b)
//               if(img->at<uchar>(y-3,x) < c_b)
//                if(img->at<uchar>(y-3,x-1) < c_b)
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y-2,x+2) < c_b)
//                   if(img->at<uchar>(y-1,x+3) < c_b)
//                    if(img->at<uchar>(y,x+3) < c_b)
//                     {}
//                    else
//                     if(img->at<uchar>(y,x-3) < c_b)
//                      if(img->at<uchar>(y+1,x-3) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     if(img->at<uchar>(y+1,x-3) < c_b)
//                      if(img->at<uchar>(y+2,x-2) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     if(img->at<uchar>(y+2,x-2) < c_b)
//                      if(img->at<uchar>(y+3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      if(img->at<uchar>(y-3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-3,x+1) < c_b)
//               if(img->at<uchar>(y-3,x) < c_b)
//                if(img->at<uchar>(y-3,x-1) < c_b)
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-1,x+3) < c_b)
//                     if(img->at<uchar>(y,x+3) < c_b)
//                      {}
//                     else
//                      if(img->at<uchar>(y+1,x-3) < c_b)
//                       {}
//                      else
//                       continue;
//                    else
//                     if(img->at<uchar>(y+1,x-3) < c_b)
//                      if(img->at<uchar>(y+2,x-2) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     if(img->at<uchar>(y+2,x-2) < c_b)
//                      if(img->at<uchar>(y+3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//           else if(img->at<uchar>(y+2,x+2) < c_b)
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-3,x+1) < c_b)
//              if(img->at<uchar>(y-3,x) < c_b)
//               if(img->at<uchar>(y-2,x-2) < c_b)
//                if(img->at<uchar>(y-2,x+2) < c_b)
//                 if(img->at<uchar>(y-1,x+3) < c_b)
//                  if(img->at<uchar>(y,x+3) < c_b)
//                   if(img->at<uchar>(y+1,x+3) < c_b)
//                    {}
//                   else
//                    if(img->at<uchar>(y-1,x-3) < c_b)
//                     if(img->at<uchar>(y,x-3) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y-1,x-3) < c_b)
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     if(img->at<uchar>(y+1,x-3) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x-3) < c_b)
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     if(img->at<uchar>(y+2,x-2) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y+1,x-3) < c_b)
//                    if(img->at<uchar>(y+2,x-2) < c_b)
//                     if(img->at<uchar>(y+3,x-1) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//           else
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     if(img->at<uchar>(y-3,x) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-3,x+1) < c_b)
//              if(img->at<uchar>(y-3,x) < c_b)
//               if(img->at<uchar>(y-2,x-2) < c_b)
//                if(img->at<uchar>(y-1,x-3) < c_b)
//                 if(img->at<uchar>(y-2,x+2) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y,x+3) < c_b)
//                    if(img->at<uchar>(y+1,x+3) < c_b)
//                     {}
//                    else
//                     if(img->at<uchar>(y,x-3) < c_b)
//                      {}
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     if(img->at<uchar>(y+1,x-3) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     if(img->at<uchar>(y+2,x-2) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y+1,x-3) < c_b)
//                    if(img->at<uchar>(y+2,x-2) < c_b)
//                     if(img->at<uchar>(y+3,x-1) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//          else if(img->at<uchar>(y+3,x+1) < c_b)
//           if(img->at<uchar>(y-3,x) > cb)
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y+2,x+2) > cb)
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else if(img->at<uchar>(y-3,x) < c_b)
//            if(img->at<uchar>(y-3,x+1) < c_b)
//             if(img->at<uchar>(y-3,x-1) < c_b)
//              if(img->at<uchar>(y-2,x+2) < c_b)
//               if(img->at<uchar>(y-1,x+3) < c_b)
//                if(img->at<uchar>(y,x+3) < c_b)
//                 if(img->at<uchar>(y+1,x+3) < c_b)
//                  if(img->at<uchar>(y+2,x+2) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x-2) < c_b)
//                    if(img->at<uchar>(y-1,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-2,x-2) < c_b)
//                   if(img->at<uchar>(y-1,x-3) < c_b)
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-2,x-2) < c_b)
//                  if(img->at<uchar>(y-1,x-3) < c_b)
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-2,x-2) < c_b)
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y+1,x-3) < c_b)
//                    if(img->at<uchar>(y+2,x-2) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y-2,x-2) < c_b)
//                if(img->at<uchar>(y-1,x-3) < c_b)
//                 if(img->at<uchar>(y,x-3) < c_b)
//                  if(img->at<uchar>(y+1,x-3) < c_b)
//                   if(img->at<uchar>(y+2,x-2) < c_b)
//                    if(img->at<uchar>(y+3,x-1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else
//            continue;
//          else
//           if(img->at<uchar>(y-3,x) > cb)
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y+3,x-1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y+2,x+2) > cb)
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-3,x+1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else if(img->at<uchar>(y-3,x) < c_b)
//            if(img->at<uchar>(y-3,x+1) < c_b)
//             if(img->at<uchar>(y-3,x-1) < c_b)
//              if(img->at<uchar>(y-2,x-2) < c_b)
//               if(img->at<uchar>(y-2,x+2) < c_b)
//                if(img->at<uchar>(y-1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y+1,x+3) < c_b)
//                   if(img->at<uchar>(y+2,x+2) < c_b)
//                    {}
//                   else
//                    if(img->at<uchar>(y-1,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y-1,x-3) < c_b)
//                    if(img->at<uchar>(y,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x-3) < c_b)
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    if(img->at<uchar>(y+1,x-3) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y+1,x-3) < c_b)
//                    if(img->at<uchar>(y+2,x-2) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-1,x-3) < c_b)
//                 if(img->at<uchar>(y,x-3) < c_b)
//                  if(img->at<uchar>(y+1,x-3) < c_b)
//                   if(img->at<uchar>(y+2,x-2) < c_b)
//                    if(img->at<uchar>(y+3,x-1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//           else
//            continue;
//         else if(img->at<uchar>(y+3,x) < c_b)
//          if(img->at<uchar>(y+3,x+1) > cb)
//           if(img->at<uchar>(y-3,x) > cb)
//            if(img->at<uchar>(y-3,x+1) > cb)
//             if(img->at<uchar>(y-3,x-1) > cb)
//              if(img->at<uchar>(y-2,x+2) > cb)
//               if(img->at<uchar>(y-1,x+3) > cb)
//                if(img->at<uchar>(y,x+3) > cb)
//                 if(img->at<uchar>(y+1,x+3) > cb)
//                  if(img->at<uchar>(y+2,x+2) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x-2) > cb)
//                    if(img->at<uchar>(y-1,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-2,x-2) > cb)
//                   if(img->at<uchar>(y-1,x-3) > cb)
//                    if(img->at<uchar>(y,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-2,x-2) > cb)
//                  if(img->at<uchar>(y-1,x-3) > cb)
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-2,x-2) > cb)
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y+1,x-3) > cb)
//                    if(img->at<uchar>(y+2,x-2) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y-2,x-2) > cb)
//                if(img->at<uchar>(y-1,x-3) > cb)
//                 if(img->at<uchar>(y,x-3) > cb)
//                  if(img->at<uchar>(y+1,x-3) > cb)
//                   if(img->at<uchar>(y+2,x-2) > cb)
//                    if(img->at<uchar>(y+3,x-1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else if(img->at<uchar>(y-3,x) < c_b)
//            if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y+2,x+2) < c_b)
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else
//            continue;
//          else if(img->at<uchar>(y+3,x+1) < c_b)
//           if(img->at<uchar>(y+2,x+2) > cb)
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-3,x+1) > cb)
//              if(img->at<uchar>(y-3,x) > cb)
//               if(img->at<uchar>(y-2,x-2) > cb)
//                if(img->at<uchar>(y-2,x+2) > cb)
//                 if(img->at<uchar>(y-1,x+3) > cb)
//                  if(img->at<uchar>(y,x+3) > cb)
//                   if(img->at<uchar>(y+1,x+3) > cb)
//                    {}
//                   else
//                    if(img->at<uchar>(y-1,x-3) > cb)
//                     if(img->at<uchar>(y,x-3) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y-1,x-3) > cb)
//                    if(img->at<uchar>(y,x-3) > cb)
//                     if(img->at<uchar>(y+1,x-3) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x-3) > cb)
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     if(img->at<uchar>(y+2,x-2) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y+1,x-3) > cb)
//                    if(img->at<uchar>(y+2,x-2) > cb)
//                     if(img->at<uchar>(y+3,x-1) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//           else if(img->at<uchar>(y+2,x+2) < c_b)
//            if(img->at<uchar>(y+1,x+3) > cb)
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-3,x+1) > cb)
//               if(img->at<uchar>(y-3,x) > cb)
//                if(img->at<uchar>(y-3,x-1) > cb)
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y-2,x+2) > cb)
//                   if(img->at<uchar>(y-1,x+3) > cb)
//                    if(img->at<uchar>(y,x+3) > cb)
//                     {}
//                    else
//                     if(img->at<uchar>(y,x-3) > cb)
//                      if(img->at<uchar>(y+1,x-3) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y,x-3) > cb)
//                     if(img->at<uchar>(y+1,x-3) > cb)
//                      if(img->at<uchar>(y+2,x-2) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     if(img->at<uchar>(y+2,x-2) > cb)
//                      if(img->at<uchar>(y+3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else if(img->at<uchar>(y+1,x+3) < c_b)
//             if(img->at<uchar>(y,x+3) > cb)
//              if(img->at<uchar>(y+1,x-3) > cb)
//               if(img->at<uchar>(y-3,x+1) > cb)
//                if(img->at<uchar>(y-3,x) > cb)
//                 if(img->at<uchar>(y-3,x-1) > cb)
//                  if(img->at<uchar>(y-2,x-2) > cb)
//                   if(img->at<uchar>(y-1,x-3) > cb)
//                    if(img->at<uchar>(y,x-3) > cb)
//                     if(img->at<uchar>(y-2,x+2) > cb)
//                      if(img->at<uchar>(y-1,x+3) > cb)
//                       {}
//                      else
//                       if(img->at<uchar>(y+2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                     else
//                      if(img->at<uchar>(y+2,x-2) > cb)
//                       if(img->at<uchar>(y+3,x-1) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else if(img->at<uchar>(y+1,x-3) < c_b)
//               if(img->at<uchar>(y-1,x-3) > cb)
//                if(img->at<uchar>(y-1,x+3) > cb)
//                 if(img->at<uchar>(y-2,x+2) > cb)
//                  if(img->at<uchar>(y-3,x+1) > cb)
//                   if(img->at<uchar>(y-3,x) > cb)
//                    if(img->at<uchar>(y-3,x-1) > cb)
//                     if(img->at<uchar>(y-2,x-2) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y-1,x-3) < c_b)
//                if(img->at<uchar>(y,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               if(img->at<uchar>(y-1,x+3) > cb)
//                if(img->at<uchar>(y-2,x+2) > cb)
//                 if(img->at<uchar>(y-3,x+1) > cb)
//                  if(img->at<uchar>(y-3,x) > cb)
//                   if(img->at<uchar>(y-3,x-1) > cb)
//                    if(img->at<uchar>(y-2,x-2) > cb)
//                     if(img->at<uchar>(y-1,x-3) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else if(img->at<uchar>(y,x+3) < c_b)
//              if(img->at<uchar>(y-1,x+3) > cb)
//               if(img->at<uchar>(y+2,x-2) > cb)
//                if(img->at<uchar>(y-3,x+1) > cb)
//                 if(img->at<uchar>(y-3,x) > cb)
//                  if(img->at<uchar>(y-3,x-1) > cb)
//                   if(img->at<uchar>(y-2,x-2) > cb)
//                    if(img->at<uchar>(y-1,x-3) > cb)
//                     if(img->at<uchar>(y,x-3) > cb)
//                      if(img->at<uchar>(y+1,x-3) > cb)
//                       if(img->at<uchar>(y-2,x+2) > cb)
//                        {}
//                       else
//                        if(img->at<uchar>(y+3,x-1) > cb)
//                         {}
//                        else
//                         continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y+2,x-2) < c_b)
//                if(img->at<uchar>(y,x-3) > cb)
//                 if(img->at<uchar>(y-2,x+2) > cb)
//                  if(img->at<uchar>(y-3,x+1) > cb)
//                   if(img->at<uchar>(y-3,x) > cb)
//                    if(img->at<uchar>(y-3,x-1) > cb)
//                     if(img->at<uchar>(y-2,x-2) > cb)
//                      if(img->at<uchar>(y-1,x-3) > cb)
//                       if(img->at<uchar>(y+1,x-3) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else if(img->at<uchar>(y,x-3) < c_b)
//                 if(img->at<uchar>(y+1,x-3) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        if(img->at<uchar>(y-1,x-3) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                if(img->at<uchar>(y-2,x+2) > cb)
//                 if(img->at<uchar>(y-3,x+1) > cb)
//                  if(img->at<uchar>(y-3,x) > cb)
//                   if(img->at<uchar>(y-3,x-1) > cb)
//                    if(img->at<uchar>(y-2,x-2) > cb)
//                     if(img->at<uchar>(y-1,x-3) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       if(img->at<uchar>(y+1,x-3) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else if(img->at<uchar>(y-1,x+3) < c_b)
//               if(img->at<uchar>(y-2,x+2) > cb)
//                if(img->at<uchar>(y+3,x-1) < c_b)
//                 if(img->at<uchar>(y+1,x-3) > cb)
//                  if(img->at<uchar>(y-3,x+1) > cb)
//                   if(img->at<uchar>(y-3,x) > cb)
//                    if(img->at<uchar>(y-3,x-1) > cb)
//                     if(img->at<uchar>(y-2,x-2) > cb)
//                      if(img->at<uchar>(y-1,x-3) > cb)
//                       if(img->at<uchar>(y,x-3) > cb)
//                        if(img->at<uchar>(y+2,x-2) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else if(img->at<uchar>(y+1,x-3) < c_b)
//                  if(img->at<uchar>(y+2,x-2) < c_b)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 if(img->at<uchar>(y-3,x+1) > cb)
//                  if(img->at<uchar>(y-3,x) > cb)
//                   if(img->at<uchar>(y-3,x-1) > cb)
//                    if(img->at<uchar>(y-2,x-2) > cb)
//                     if(img->at<uchar>(y-1,x-3) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       if(img->at<uchar>(y+1,x-3) > cb)
//                        if(img->at<uchar>(y+2,x-2) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else if(img->at<uchar>(y-2,x+2) < c_b)
//                if(img->at<uchar>(y-3,x+1) > cb)
//                 if(img->at<uchar>(y+2,x-2) > cb)
//                  if(img->at<uchar>(y-3,x) > cb)
//                   if(img->at<uchar>(y-3,x-1) > cb)
//                    if(img->at<uchar>(y-2,x-2) > cb)
//                     if(img->at<uchar>(y-1,x-3) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       if(img->at<uchar>(y+1,x-3) > cb)
//                        if(img->at<uchar>(y+3,x-1) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//                else if(img->at<uchar>(y-3,x+1) < c_b)
//                 if(img->at<uchar>(y-3,x) < c_b)
//                  {}
//                 else
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x-3) > cb)
//                 if(img->at<uchar>(y-3,x+1) > cb)
//                  if(img->at<uchar>(y-3,x) > cb)
//                   if(img->at<uchar>(y-3,x-1) > cb)
//                    if(img->at<uchar>(y-2,x-2) > cb)
//                     if(img->at<uchar>(y-1,x-3) > cb)
//                      if(img->at<uchar>(y,x-3) > cb)
//                       if(img->at<uchar>(y+2,x-2) > cb)
//                        if(img->at<uchar>(y+3,x-1) > cb)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y,x-3) > cb)
//                if(img->at<uchar>(y-3,x+1) > cb)
//                 if(img->at<uchar>(y-3,x) > cb)
//                  if(img->at<uchar>(y-3,x-1) > cb)
//                   if(img->at<uchar>(y-2,x-2) > cb)
//                    if(img->at<uchar>(y-1,x-3) > cb)
//                     if(img->at<uchar>(y+1,x-3) > cb)
//                      if(img->at<uchar>(y+2,x-2) > cb)
//                       if(img->at<uchar>(y-2,x+2) > cb)
//                        {}
//                       else
//                        if(img->at<uchar>(y+3,x-1) > cb)
//                         {}
//                        else
//                         continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        if(img->at<uchar>(y-1,x-3) < c_b)
//                         {}
//                        else
//                         continue;
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              if(img->at<uchar>(y-1,x-3) > cb)
//               if(img->at<uchar>(y-3,x+1) > cb)
//                if(img->at<uchar>(y-3,x) > cb)
//                 if(img->at<uchar>(y-3,x-1) > cb)
//                  if(img->at<uchar>(y-2,x-2) > cb)
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     if(img->at<uchar>(y-2,x+2) > cb)
//                      if(img->at<uchar>(y-1,x+3) > cb)
//                       {}
//                      else
//                       if(img->at<uchar>(y+2,x-2) > cb)
//                        {}
//                       else
//                        continue;
//                     else
//                      if(img->at<uchar>(y+2,x-2) > cb)
//                       if(img->at<uchar>(y+3,x-1) > cb)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       if(img->at<uchar>(y-2,x-2) < c_b)
//                        {}
//                       else
//                        continue;
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//            else
//             if(img->at<uchar>(y-2,x-2) > cb)
//              if(img->at<uchar>(y-3,x+1) > cb)
//               if(img->at<uchar>(y-3,x) > cb)
//                if(img->at<uchar>(y-3,x-1) > cb)
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y-2,x+2) > cb)
//                    if(img->at<uchar>(y-1,x+3) > cb)
//                     if(img->at<uchar>(y,x+3) > cb)
//                      {}
//                     else
//                      if(img->at<uchar>(y+1,x-3) > cb)
//                       {}
//                      else
//                       continue;
//                    else
//                     if(img->at<uchar>(y+1,x-3) > cb)
//                      if(img->at<uchar>(y+2,x-2) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     if(img->at<uchar>(y+2,x-2) > cb)
//                      if(img->at<uchar>(y+3,x-1) > cb)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      if(img->at<uchar>(y-3,x-1) < c_b)
//                       {}
//                      else
//                       continue;
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//           else
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-3,x+1) > cb)
//              if(img->at<uchar>(y-3,x) > cb)
//               if(img->at<uchar>(y-2,x-2) > cb)
//                if(img->at<uchar>(y-1,x-3) > cb)
//                 if(img->at<uchar>(y-2,x+2) > cb)
//                  if(img->at<uchar>(y-1,x+3) > cb)
//                   if(img->at<uchar>(y,x+3) > cb)
//                    if(img->at<uchar>(y+1,x+3) > cb)
//                     {}
//                    else
//                     if(img->at<uchar>(y,x-3) > cb)
//                      {}
//                     else
//                      continue;
//                   else
//                    if(img->at<uchar>(y,x-3) > cb)
//                     if(img->at<uchar>(y+1,x-3) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     if(img->at<uchar>(y+2,x-2) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y+1,x-3) > cb)
//                    if(img->at<uchar>(y+2,x-2) > cb)
//                     if(img->at<uchar>(y+3,x-1) > cb)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//             else
//              continue;
//            else if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     if(img->at<uchar>(y-3,x) < c_b)
//                      {}
//                     else
//                      continue;
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//          else
//           if(img->at<uchar>(y-3,x) > cb)
//            if(img->at<uchar>(y-3,x+1) > cb)
//             if(img->at<uchar>(y-3,x-1) > cb)
//              if(img->at<uchar>(y-2,x-2) > cb)
//               if(img->at<uchar>(y-2,x+2) > cb)
//                if(img->at<uchar>(y-1,x+3) > cb)
//                 if(img->at<uchar>(y,x+3) > cb)
//                  if(img->at<uchar>(y+1,x+3) > cb)
//                   if(img->at<uchar>(y+2,x+2) > cb)
//                    {}
//                   else
//                    if(img->at<uchar>(y-1,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                  else
//                   if(img->at<uchar>(y-1,x-3) > cb)
//                    if(img->at<uchar>(y,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x-3) > cb)
//                   if(img->at<uchar>(y,x-3) > cb)
//                    if(img->at<uchar>(y+1,x-3) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y+1,x-3) > cb)
//                    if(img->at<uchar>(y+2,x-2) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-1,x-3) > cb)
//                 if(img->at<uchar>(y,x-3) > cb)
//                  if(img->at<uchar>(y+1,x-3) > cb)
//                   if(img->at<uchar>(y+2,x-2) > cb)
//                    if(img->at<uchar>(y+3,x-1) > cb)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               continue;
//             else
//              continue;
//            else
//             continue;
//           else if(img->at<uchar>(y-3,x) < c_b)
//            if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-2,x-2) < c_b)
//              if(img->at<uchar>(y-1,x-3) < c_b)
//               if(img->at<uchar>(y,x-3) < c_b)
//                if(img->at<uchar>(y+1,x-3) < c_b)
//                 if(img->at<uchar>(y+2,x-2) < c_b)
//                  if(img->at<uchar>(y+3,x-1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y+2,x+2) < c_b)
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y,x+3) < c_b)
//                  if(img->at<uchar>(y-1,x+3) < c_b)
//                   if(img->at<uchar>(y-2,x+2) < c_b)
//                    if(img->at<uchar>(y-3,x+1) < c_b)
//                     {}
//                    else
//                     continue;
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              continue;
//            else
//             continue;
//           else
//            continue;
//         else
//          if(img->at<uchar>(y-3,x+1) > cb)
//           if(img->at<uchar>(y-3,x) > cb)
//            if(img->at<uchar>(y-3,x-1) > cb)
//             if(img->at<uchar>(y-2,x+2) > cb)
//              if(img->at<uchar>(y-1,x+3) > cb)
//               if(img->at<uchar>(y,x+3) > cb)
//                if(img->at<uchar>(y+1,x+3) > cb)
//                 if(img->at<uchar>(y+2,x+2) > cb)
//                  if(img->at<uchar>(y+3,x+1) > cb)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x-2) > cb)
//                    {}
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-2,x-2) > cb)
//                   if(img->at<uchar>(y-1,x-3) > cb)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-2,x-2) > cb)
//                  if(img->at<uchar>(y-1,x-3) > cb)
//                   if(img->at<uchar>(y,x-3) > cb)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-2,x-2) > cb)
//                 if(img->at<uchar>(y-1,x-3) > cb)
//                  if(img->at<uchar>(y,x-3) > cb)
//                   if(img->at<uchar>(y+1,x-3) > cb)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y-2,x-2) > cb)
//                if(img->at<uchar>(y-1,x-3) > cb)
//                 if(img->at<uchar>(y,x-3) > cb)
//                  if(img->at<uchar>(y+1,x-3) > cb)
//                   if(img->at<uchar>(y+2,x-2) > cb)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              if(img->at<uchar>(y-2,x-2) > cb)
//               if(img->at<uchar>(y-1,x-3) > cb)
//                if(img->at<uchar>(y,x-3) > cb)
//                 if(img->at<uchar>(y+1,x-3) > cb)
//                  if(img->at<uchar>(y+2,x-2) > cb)
//                   if(img->at<uchar>(y+3,x-1) > cb)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//            else
//             continue;
//           else
//            continue;
//          else if(img->at<uchar>(y-3,x+1) < c_b)
//           if(img->at<uchar>(y-3,x) < c_b)
//            if(img->at<uchar>(y-3,x-1) < c_b)
//             if(img->at<uchar>(y-2,x+2) < c_b)
//              if(img->at<uchar>(y-1,x+3) < c_b)
//               if(img->at<uchar>(y,x+3) < c_b)
//                if(img->at<uchar>(y+1,x+3) < c_b)
//                 if(img->at<uchar>(y+2,x+2) < c_b)
//                  if(img->at<uchar>(y+3,x+1) < c_b)
//                   {}
//                  else
//                   if(img->at<uchar>(y-2,x-2) < c_b)
//                    {}
//                   else
//                    continue;
//                 else
//                  if(img->at<uchar>(y-2,x-2) < c_b)
//                   if(img->at<uchar>(y-1,x-3) < c_b)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                else
//                 if(img->at<uchar>(y-2,x-2) < c_b)
//                  if(img->at<uchar>(y-1,x-3) < c_b)
//                   if(img->at<uchar>(y,x-3) < c_b)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//               else
//                if(img->at<uchar>(y-2,x-2) < c_b)
//                 if(img->at<uchar>(y-1,x-3) < c_b)
//                  if(img->at<uchar>(y,x-3) < c_b)
//                   if(img->at<uchar>(y+1,x-3) < c_b)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//              else
//               if(img->at<uchar>(y-2,x-2) < c_b)
//                if(img->at<uchar>(y-1,x-3) < c_b)
//                 if(img->at<uchar>(y,x-3) < c_b)
//                  if(img->at<uchar>(y+1,x-3) < c_b)
//                   if(img->at<uchar>(y+2,x-2) < c_b)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//             else
//              if(img->at<uchar>(y-2,x-2) < c_b)
//               if(img->at<uchar>(y-1,x-3) < c_b)
//                if(img->at<uchar>(y,x-3) < c_b)
//                 if(img->at<uchar>(y+1,x-3) < c_b)
//                  if(img->at<uchar>(y+2,x-2) < c_b)
//                   if(img->at<uchar>(y+3,x-1) < c_b)
//                    {}
//                   else
//                    continue;
//                  else
//                   continue;
//                 else
//                  continue;
//                else
//                 continue;
//               else
//                continue;
//              else
//               continue;
//            else
//             continue;
//           else
//            continue;
//          else
//           continue;
// 			if(num_corners == rsize)
// 			{
// 				rsize*=2;
// 				ret_corners = (xy*)realloc(ret_corners, sizeof(xy)*rsize);
// 			}
// 			ret_corners[num_corners].x = x;
// 			ret_corners[num_corners].y = y;
// 			num_corners++;
				
// 		}
	
// 	*ret_num_corners = num_corners;
// 	return ret_corners;

// }


