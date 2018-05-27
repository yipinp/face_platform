#ifndef _DETECTION_ALIGNMENT_H_
#define _DETECTION_ALIGNMENT_H_

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

using namespace dlib;
using namespace std;
using namespace cv;

class detection_alignment {

public:
    detection_alignment();
    ~detection_alignment();
    detection_alignment(std::queue<Mat> *data_source_queue_in,std::queue<Mat> *data_preprocess_queue_out);


public:
     bool dlib_face_detection_alignment(Mat image);

private:
    cv::Rect convert_dlib2cv_rectangle(dlib::rectangle rect);


};



#endif
