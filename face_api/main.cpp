#include <iostream>
#include "face_api.h"
#include <dlib/sqlite.h>

using namespace dlib;
using namespace std;

int main() {
    face_api face_app;
    string image_file("/home/pyp/face_app/face_platform/images/yanmi_1.jpeg");
    face_app.set_input_source(image_file);
    face_app.set_high_quality();
    face_app.set_face_model(DLIB_DNN);
    face_app.get_face_ids();

    face_app.set_database("face.db");

    //face_app.insert_face_to_database_("YangMi",face_app.face_id_out[0]);
    face_app.match_face_in_database(face_app.face_id_out[0],0.4);


}