#include <iostream>
#include "face_api.h"
#include <dlib/sqlite.h>

using namespace dlib;
using namespace std;

bool table_exists (
    database& db,
    const std::string& tablename
)
{
    // Sometimes you want to just run a query that returns one thing.  In this case, we
    // want to see how many tables are in our database with the given tablename.  The only
    // possible outcomes are 1 or 0 and we can do this by looking in the special
    // sqlite_master table that records such database metadata.  For these kinds of "one
    // result" queries we can use the query_int() method which executes a SQL statement
    // against a database and returns the result as an int.
    return query_int(db, "select count(*) from sqlite_master where name = '"+tablename+"'")==1;
}


void insert_face_to_database_(database *face_db,string face_name, matrix<float, 0, 1> face_id)
{
    bool found = false;
    statement st(*face_db, "insert into people VALUES(?,?)");
    statement st2(*face_db, "select * from people");
    st2.exec();
    while (st2.move_next()) {
        string name;
        st2.get_column(0, name);
        if (name == face_name) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout<<"no same name is in the database, insert it to database"<<endl;
        st.bind(1, face_name);
        st.bind(2, face_id);
        st.exec();
        transaction my_trans(*face_db);
        my_trans.commit();
    } else{
        cout<<"The same name is already in the database, skip it"<<endl;

    }
}

bool match_face_in_database(database *face_db,matrix<float, 0, 1> face_id)
{
    bool matched = false;
    double diff = 0;

    matrix<float, 0, 1> face_id_data;
    statement st2(*face_db, "select * from people");
    st2.exec();
    while (st2.move_next()) {
        string name;
        st2.get_column(1, face_id_data);
        diff = length(face_id_data-face_id);
        cout<<diff<<endl;
        matched = diff < 0.6;
        if (matched) {
            st2.get_column(0, name);
            cout<<"Find the matched user:" << name <<", distance:" << diff <<endl;
            return true;
        }
    }
    cout<<"no user is found in the database" << endl;
    return false;
}

int main() {
    face_api face_app;
    string image_file("/home/pyp/face_app/face_platform/images/suweimasuo_0.jpeg");
    face_app.set_input_source(image_file);
    face_app.set_high_quality();
    face_app.set_face_model(DLIB_DNN);
    face_app.get_face_ids();

    database face_db("face.db");

    // Create a people table that records a person's name, age, and their "data".
    if (!table_exists(face_db,"people"))
        face_db.exec("create table people (name, face_id)");

    //insert_face_to_database_(&face_db,"YangMi",face_app.face_id_out[0]);
    match_face_in_database(&face_db,face_app.face_id_out[0]);


}