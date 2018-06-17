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

#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>

typedef enum {
    DLIB_DNN,

} FACE_MODEL;




class face_api {
public:
    face_api();
    ~face_api();



public:
    void set_input_source(string image_file);
    void set_face_model(FACE_MODEL model);
    void set_high_quality();

    void get_face_ids();
    void compare_two_faces();

private:
    void setup_face_model();
    void dlib_run_one_image();
    void dlib_face_model();

private:
    string face_image;
    std::queue<Mat> data_source_queue_out; //data source out to next pipeline
    std::queue<Mat> data_preprocess_queue_out; // data preprocess output
    std::queue<Mat> data_alignment_queue_out; // data alignment output

     //data source
    data_source  *data_source_module;
    //data preprocess
    data_preprocess  *data_preprocess_module;
    //detection and alignment
    detection_alignment *detector_module;
     //recognization
    recognization *recognization_module;

    FACE_MODEL face_model;

    bool high_quality;
public:
    std::vector<matrix<float,0,1>> face_id_out; // face id output
};




#endif
