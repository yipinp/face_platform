#include "face_api.h"



/****************************************
 *    PUBLIC APIs
 *
 ****************************************/
void face_api::set_input_source(string image_file)
{
    face_image = image_file;

}


void face_api::select_face_model(FACE_MODEL model)
{
    face_model = model;

}


void face_api::get_face_ids()
{

    switch(face_model){
        case DLIB_DNN:
            dlib_dnn_face_model();

    }


}


void face_api::compare_two_faces()
{





}

/*
 * PRIVATE Functions
 *
 */

void face_api::dlib_dnn_face_model()
{
     //data source
    data_source  data_source(&data_source_queue_out);
    data_source.set_image_file(face_image);
    data_source.get_next_batch_images();
    data_source.dump_images();

    //data preprocess
    data_preprocess  data_preprocess_module(&data_source_queue_out,&data_preprocess_queue_out);
    Size2d t(0.5,0.5);
    data_preprocess_module.set_scale_ratio(t);
    data_preprocess_module.set_scale_mode(1);
    data_preprocess_module.get_next_batch_images();
    data_preprocess_module.dump_images();


    //detection and alignment
    char model_name[256] = "/home/pyp/face_app/face_platform/dnn_models/shape_predictor_68_face_landmarks.dat";

    detection_alignment dlib_detector(&data_preprocess_queue_out,&data_alignment_queue_out);
    dlib_detector.dlib_load_model(model_name);
    dlib_detector.dlib_set_detector(DLIB_FACE,150,0.25);
    dlib_detector.face_detection_alignment();
    dlib_detector.dump_images();

    //recognization
    char recognization_model_name[256]="/home/pyp/face_app/face_platform/dnn_models/dlib_face_recognition_resnet_model_v1.dat";
    recognization dlib_recognization(&data_alignment_queue_out,&face_id_out);
    dlib_recognization.dlib_load_model(recognization_model_name);
    dlib_recognization.create_recognization(DLIB_DNN_RECOGNIZATION);
    dlib_recognization.dlib_recognization();
    dlib_recognization.dump_face_features();

}


