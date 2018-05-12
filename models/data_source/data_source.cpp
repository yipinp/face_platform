#include "data_source.h"


data_source::data_source(std::queue<Mat> *data_source_queue)
                        : data_source_queue_out(data_source_queue)
{
    memset(&params,0,sizeof(params));
    params.batch_size = 1;
    params.camera_id = -1; //default camera

}


data_source::~data_source()
{


};




/***************************************************
              main API functions
***************************************************/
void data_source::set_image_file(string image_file){
    params.image_file = image_file;
    params.mode = SINGLE_IMAGE;

}


void data_source::set_directory(string dir_name) {
    params.dir_name = dir_name;
    params.mode = DIR_SCAN_MODE;

}


void data_source::set_camera_id(char camera_id) {
    params.camera_id = camera_id;
    params.mode = VIDEO_CAMERA;

}

void data_source::set_batch_size(int size) {
    params.batch_size = size;

}



bool data_source::get_next_batch_images() {
    Mat frame;
    VideoCapture capture;
    //process based on the mode
    switch(params.mode){
        case SINGLE_IMAGE:
            frame = imread(params.image_file,1);
            data_source_queue_out->push(frame);
            break;

        case DIR_SCAN_MODE:

            break;

        case VIDEO_CAMERA:
            capture.open(params.camera_id);
            if(!capture.isOpened()) {
                cout <<"Fail to open the camera"<<endl;
                return false;
            }
            for(int i = 0; i < params.batch_size; i++){
                capture.read(frame);
                if(frame.empty()){
                    cout<<"No capture frame"<<endl;
                    return false;
                }
                data_source_queue_out->push(frame);
            }

            capture.release();

            break;

        default:
            break;

    }

    return true;


}



#if 0
int main(int argc, char **argv){
    std::queue<Mat> data_source_queue_out;
    data_source data_source(&data_source_queue_out);
    Mat frame;

#if 0
    //test0
    string image_file("/home/pyp/CLionProjects/face_app/t1.png");
    data_source.set_image_file(image_file);
#endif
    //test1
    data_source.set_camera_id(-1);
    data_source.set_batch_size(128);


    data_source.get_next_batch_images();
    cout <<"size :" << data_source_queue_out.size()<<endl;
    //display image
    namedWindow("show");
    for(int i =0; i < data_source_queue_out.size(); i ++){
        frame = data_source_queue_out.front();
        imshow("show",frame);
        waitKey(10);

    }


}

#endif