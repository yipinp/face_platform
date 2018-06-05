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

    cout <<"hello"<<endl;



}