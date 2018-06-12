#include <iostream>
#include "face_api.h"

int main() {

    face_api face_app;

    string image_file("/home/pyp/face_app/face_platform/images/t2.jpeg");
    face_app.set_input_source(image_file);
    face_app.select_face_model(DLIB_DNN);
    face_app.get_face_ids();
}