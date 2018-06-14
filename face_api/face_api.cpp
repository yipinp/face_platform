#include "face_api.h"


face_api::face_api()
{

    setup_face_model();
}


face_api::~face_api()
{

}

/****************************************
 *    PUBLIC APIs
 *
 ****************************************/
void face_api::set_input_source(string image_file)
{
    face_image = image_file;

}

void face_api::set_face_model(FACE_MODEL model)
{
    face_model = model;

}


void face_api::get_face_ids()
{

    switch(face_model){
        case DLIB_DNN:
            dlib_run_one_image();
            break;
        default:
            break;
    }

}


void face_api::compare_two_faces()
{





}

/*
 * PRIVATE Functions
 *
 */

void face_api::setup_face_model()
{
     //data source
    data_source_module = new data_source(&data_source_queue_out);
    //data preprocess
    data_preprocess_module = new data_preprocess(&data_source_queue_out,&data_preprocess_queue_out);
    //detection and alignment
    detector_module = new detection_alignment(&data_preprocess_queue_out,&data_alignment_queue_out);
     //recognization
    recognization_module = new recognization(&data_alignment_queue_out,&face_id_out);

}



void face_api::dlib_run_one_image() {
    char baseName[] = "/home/pyp/face_app/face_platform/dumps/dump";
    //data source
    data_source_module->set_image_file(face_image);
    data_source_module->get_next_batch_images();
    data_source_module->dump_images(baseName);

    //data preprocess
    Size2d t(0.5,0.5);
    data_preprocess_module->set_scale_ratio(t);
    data_preprocess_module->set_scale_mode(1);
    data_preprocess_module->get_next_batch_images();
    data_preprocess_module->dump_images(baseName);


    //detection and alignment
    char model_name[256] = "/home/pyp/face_app/face_platform/dnn_models/shape_predictor_68_face_landmarks.dat";
    detector_module->dlib_load_model(model_name);
    detector_module->dlib_set_detector(DLIB_FACE,150,0.25);
    detector_module->face_detection_alignment();
    detector_module->dump_images(baseName);

    //recognization
    char recognization_model_name[256]="/home/pyp/face_app/face_platform/dnn_models/dlib_face_recognition_resnet_model_v1.dat";
    recognization_module->dlib_load_model(recognization_model_name);
    recognization_module->create_recognization(DLIB_DNN_RECOGNIZATION);
    recognization_module->dlib_recognization();
    recognization_module->dump_face_features(baseName);

}


