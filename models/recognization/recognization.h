#ifndef _RECOGNIZATION_H_
#define _RECOGNIZATION_H_

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
#include <dlib/image_transforms.h>

using namespace dlib;
using namespace std;
using namespace cv;



class recognization {

public:
    recognization();
    ~recognization();
    recognization(std::queue<Mat> *img_faces_in);


public:

private:
    std::queue<Mat> *img_faces;

};
#endif