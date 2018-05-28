#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <string>
#include <queue>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <opencv/cv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/opencv.h>
#include <dlib/image_io.h>


static cv::Rect convert_dlib2cv_rectangle(dlib::rectangle rect)
{
    cv::Rect cv_rect;
    cv_rect.x = rect.left();
    cv_rect.y = rect.top();
    cv_rect.width = rect.right() - rect.left();
    cv_rect.height = rect.bottom() - rect.top();
    return cv_rect;
}



#endif
