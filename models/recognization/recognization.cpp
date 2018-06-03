#include <iostream>
#include "recognization.h"



recognization::recognization()
{


}

recognization::recognization(std::queue<Mat> *img_faces_in, std::vector<matrix<float,0,1>> *face_id_out)
                : img_faces(img_faces_in),
                  face_id(face_id_out)
{


}


recognization::~recognization()
{

}



void recognization::create_recognization(RECOGNIZATION_MODE  mode)
{
    switch(mode){
        case DLIB_DNN_RECOGNIZATION:
            deserialize("/home/pyp/face_app/face_platform/models/recognization/dlib_face_recognition_resnet_model_v1.dat") >> dlib_net;
            break;

        default:
            break;





    }



}


void recognization::dlib_recognization()
{
    //read the face chips from detection and alignment and covert to dlib matrix
    std::vector<matrix<rgb_pixel>> faces;
    matrix<dlib::rgb_pixel> img;
    for (int i = 0; i < img_faces->size(); i++){
        assign_image(img,cv_image<rgb_pixel>(img_faces[i]));
        faces.push_back(img);
    }

    std::vector<matrix<float,0,1>> face_descriptors = dlib_net(faces);
    for (int i = 0; i < face_descriptors.size(); i++){
        face_id->push_back(face_descriptors[i]);
    }

}



int main() {

// The first thing we are going to do is load all our models.  First, since we need to
    // find faces in the image we will need a face detector:
    frontal_face_detector detector = get_frontal_face_detector();
    // We will also use a face landmarking model to align faces to a standard pose:  (see face_landmark_detection_ex.cpp for an introduction)
    shape_predictor sp;
    deserialize("/home/pyp/face_app/face_platform/models/recognization/shape_predictor_5_face_landmarks.dat") >> sp;
    // And finally we load the DNN responsible for face recognition.
    anet_type net;
    deserialize("/home/pyp/face_app/face_platform/models/recognization/dlib_face_recognition_resnet_model_v1.dat") >> net;

    matrix<rgb_pixel> img;
    load_image(img, "/home/pyp/face_app/face_platform/models/recognization/multiple_faces.jpg");


    std::vector<matrix<rgb_pixel>> faces;
    for (auto face : detector(img))
    {
        auto shape = sp(img, face);
        matrix<rgb_pixel> face_chip;
        extract_image_chip(img, get_face_chip_details(shape,150,0.25), face_chip);
        faces.push_back(move(face_chip));
        // Also put some boxes on the faces so we can see that the detector is finding
        // them.

    }
    recognization dlib_reconization;

    cout << "face descriptor for one face: " << trans(face_descriptors[0]) << endl;
}