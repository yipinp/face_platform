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
#include <dlib/dnn.h>
#include "common_recognization.h"

using namespace dlib;
using namespace std;
using namespace cv;

typedef enum {
    DLIB_DNN_RECOGNIZATION,

} RECOGNIZATION_MODE;


class recognization {


public:
    recognization();
    ~recognization();
    recognization(std::queue<Mat> *face_chips_in,std::vector<matrix<float,0,1>> *face_id_out);


public:
    void dlib_load_model(char *name);
    void create_recognization(RECOGNIZATION_MODE  mode);

private:
    void dlib_recognization();


private:
    std::queue<Mat> *img_faces;
    std::vector<matrix<float,0,1>> *face_id;
    anet_type dlib_net;
    char dlib_model_name[256];

};
#endif