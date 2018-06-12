#ifndef _FACE_API_H_
#define _FACE_API_H_

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

#include "../models/data_source/data_source.h"
#include "../models/data_preprocess/data_preprocess.h"
#include "../models/detection_alignment/detection_alignment.h"
#include "../models/recognization/recognization.h"

typedef enum {
    DLIB_DNN,

} FACE_MODEL;




class face_api {
public:
    face_api(){};



public:
    void set_input_source(string image_file);
    void select_face_model(FACE_MODEL model);

    void get_face_ids();
    void compare_two_faces();

private:
    void dlib_dnn_face_model();

private:
    string face_image;
    std::queue<Mat> data_source_queue_out; //data source out to next pipeline
    std::queue<Mat> data_preprocess_queue_out; // data preprocess output
    std::queue<Mat> data_alignment_queue_out; // data alignment output

    FACE_MODEL face_model;
public:
    std::vector<matrix<float,0,1>> face_id_out; // face id output
};




#endif
