#include "face_api.h"


face_api::face_api()
{

    setup_face_model();
    high_quality = false;
    face_image = "";
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
    switch(face_model){
        case DLIB_DNN:
            dlib_face_model();
            break;

        default:
            break;
    }

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

void face_api::set_high_quality() {
    high_quality = true;
}


void face_api::dlib_face_model(){


    //load dnn models
    //char model_name[256] = "/home/pyp/face_app/face_platform/dnn_models/shape_predictor_68_face_landmarks.dat";
    char model_name[256] = "/home/pyp/face_app/face_platform/dnn_models/shape_predictor_5_face_landmarks.dat";
    detector_module->dlib_load_model(model_name);
    detector_module->dlib_set_detector(DLIB_FACE,150,0.25);

    char recognization_model_name[256]="/home/pyp/face_app/face_platform/dnn_models/dlib_face_recognition_resnet_model_v1.dat";
    recognization_module->dlib_load_model(recognization_model_name);
    recognization_module->create_recognization(DLIB_DNN_RECOGNIZATION);
    if(high_quality) recognization_module->set_high_quality();

}

void face_api::dlib_run_one_image() {
    char baseName[] = "/home/pyp/face_app/face_platform/dumps/dump";
    //data source
    if(face_image != "")
        data_source_module->set_image_file(face_image);
    else
        data_source_module->set_camera_id(-1);
    data_source_module->get_next_batch_images();
    data_source_module->dump_images(baseName);

    //data preprocess
   // Size2d t(0.5,0.5);
   // data_preprocess_module->set_scale_ratio(t);
   // data_preprocess_module->set_scale_mode(1);
    data_preprocess_module->get_next_batch_images();
    data_preprocess_module->dump_images(baseName);


    //detection and alignment
    detector_module->face_detection_alignment();
    detector_module->dump_images(baseName);

    //recognization
    recognization_module->dlib_recognization();
    recognization_module->dump_face_features(baseName);

}


/*
 *   database API
 */
bool face_api::table_exists(database& db, const std::string& tablename)
{
    // Sometimes you want to just run a query that returns one thing.  In this case, we
    // want to see how many tables are in our database with the given tablename.  The only
    // possible outcomes are 1 or 0 and we can do this by looking in the special
    // sqlite_master table that records such database metadata.  For these kinds of "one
    // result" queries we can use the query_int() method which executes a SQL statement
    // against a database and returns the result as an int.
    return query_int(db, "select count(*) from sqlite_master where name = '"+tablename+"'")==1;
}


void face_api::set_database(string face_database_name)
{

     face_db.open(face_database_name);

    // Create a people table that records a person's name, age, and their "data".
    if (!table_exists(face_db,"user_face"))
        face_db.exec("create table user_face (username, user_face_id)");

}



bool face_api::insert_face_to_database(string face_name, matrix<float, 0, 1> face_id)
{
    bool found = false;
    statement st(face_db, "insert into user_face VALUES(?,?)");
    statement st2(face_db, "select * from user_face");
    st2.exec();
    while (st2.move_next()) {
        string name;
        st2.get_column(0, name);
        if (name == face_name) {
            found = true;
            return found;
        }
    }

    if (!found) {
        cout<<"no same name is in the database, insert it to database"<<endl;
        st.bind(1, face_name);
        st.bind(2, face_id);
        st.exec();
        transaction my_trans(face_db);
        my_trans.commit();
    } else{
        cout<<"The same name is already in the database, skip it"<<endl;

    }
    return found;
}


bool face_api::match_face_in_database(matrix<float, 0, 1> face_id, double threshold)
{
    bool matched = false;
    double diff = 0;

    matrix<float, 0, 1> face_id_data;
    statement st2(face_db, "select * from user_face");
    st2.exec();
    while (st2.move_next()) {
        string name;
        st2.get_column(1, face_id_data);
        diff = length(face_id_data-face_id);
        cout<<diff<<endl;
        matched = diff < threshold;
        if (matched) {
            st2.get_column(0, name);
            cout<<"Find the matched user:" << name <<", distance:" << diff <<endl;
            return true;
        }
    }
    cout<<"no user is found in the database" << endl;
    return false;
}