#include <iostream>
#include "./models/data_source/data_source.h"
#include "./models/data_preprocess/data_preprocess.h"
#include "./models/detection_alignment/detection_alignment.h"
#include "./models/recognization/recognization.h"


int main() {

    std::queue<Mat> data_source_queue_out; //data source out to next pipeline
    std::queue<Mat> data_preprocess_queue_out; // data preprocess output
    std::queue<Mat> data_alignment_queue_out; // data alignment output
    std::vector<matrix<float,0,1>> face_id_out; // face id output

    //data source
    data_source  data_source(&data_source_queue_out);
    string image_file("/home/pyp/face_app/face_platform/images/t2.jpeg");
    data_source.set_image_file(image_file);
    data_source.set_camera_id(-1);
    data_source.set_batch_size(128);
    data_source.get_next_batch_images();

    //data preprocess
    data_preprocess  data_preprocess_module(&data_source_queue_out,&data_preprocess_queue_out);
    Size2d t(0.5,0.5);
    data_preprocess_module.set_scale_ratio(t);
    data_preprocess_module.set_scale_mode(1);
    data_preprocess_module.set_image_flip(0);
    data_preprocess_module.get_next_batch_images();


    //detection and alignment
    char model_name[256] = "/home/pyp/face_app/face_platform/dnn_models/shape_predictor_68_face_landmarks.dat";

    detection_alignment dlib_detector(&data_preprocess_queue_out,&data_alignment_queue_out);
    dlib_detector.dlib_load_model(model_name);
    dlib_detector.face_detection_alignment();

    //recognization
    char recognization_model_name[256]="/home/pyp/face_app/face_platform/dnn_models/dlib_face_recognition_resnet_model_v1.dat";
    recognization dlib_recognization(&data_alignment_queue_out,&face_id_out);
    dlib_recognization.dlib_load_model(recognization_model_name);


}