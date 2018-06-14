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
#include <dlib/image_transforms.h>

using namespace dlib;
using namespace std;
using namespace cv;

typedef enum {
    DLIB_FACE,


} FACE_DETECTOR_S;


class detection_alignment {

public:
    detection_alignment();
    ~detection_alignment();
    detection_alignment(std::queue<Mat> *img_queue_in,std::queue<Mat> *face_queue_out);


public:
    void dlib_load_model(char *name);
    void dlib_set_detector(FACE_DETECTOR_S detector,unsigned long size_i = 0, double padding_i = 0);
    void face_detection_alignment();
    void dump_images(char *baseName);

private:
    bool dlib_face_detection_alignment(Mat image);
    void reset();

private:
    char dlib_model_name[256];
    std::queue<Mat> *img_queue_in;
    std::queue<Mat> *face_queue_out;
    FACE_DETECTOR_S face_detector;
    unsigned long size;
    double padding;
};



#endif
