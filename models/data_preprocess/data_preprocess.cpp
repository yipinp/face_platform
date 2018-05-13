#include "data_preprocess.h"



data_preprocess::data_preprocess() {
    reset();

}



data_preprocess::data_preprocess(std::queue<Mat> *data_source_queue, std::queue<Mat> *data_preprocess_queue)
                : data_source_queue_in(data_source_queue),
                  data_preprocess_queue_out(data_preprocess_queue)
{

    reset();




}

data_preprocess::~data_preprocess() {

}



void data_preprocess::reset(){
    memset(&params,0,sizeof(params));
    params.scale_mode = 2; //cubic interpolation
    params.scale_ratio = Size(1,1);
    params.scale_size = Size(0,0);
}

/************************************************
        API  core functions
************************************************/
void data_preprocess::set_scale_size(Size t){
    params.scale_size = t;
}

void data_preprocess::set_scale_ratio(Size2d ratio)
{
    params.scale_ratio = ratio;

}

void data_preprocess::set_scale_mode(int mode){
    params.scale_mode = mode;

}


Mat data_preprocess::image_scale(Mat frame_in) {
    Mat scaleframe;
    resize(frame_in,scaleframe,params.scale_size,params.scale_ratio.height,params.scale_ratio.width,params.scale_mode);
    return scaleframe;
}



#if  0

int main (int argc, char **argv){

    Mat img = imread("/home/pyp/face_app/face_platform/models/data_source/t1.png",1);
    Mat img1;
    data_preprocess  data_preprocess_module;
    Size2d t(0.5,0.5);
    data_preprocess_module.set_scale_ratio(t);
    data_preprocess_module.set_scale_mode(1);
    img1 = data_preprocess_module.image_scale(img);
    imwrite("t2.jpg",img1);

    return 1;
}
#endif