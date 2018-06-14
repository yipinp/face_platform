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
    params.count = 0;
}

/************************************************
        API  core functions
************************************************/
void data_preprocess::set_scale_size(Size t){
    params.scale_size = t;
    params.order |= (SCALE << MODE_BITS*params.count);
    params.count ++;
}

void data_preprocess::set_scale_ratio(Size2d ratio)
{
    params.scale_ratio = ratio;
    params.order |= (SCALE << MODE_BITS*params.count);
    params.count ++;

}

void data_preprocess::set_scale_mode(int mode){
    params.scale_mode = mode;

}


Mat data_preprocess::image_scale(Mat frame_in) {
    Mat scaleframe;
    resize(frame_in,scaleframe,params.scale_size,params.scale_ratio.height,params.scale_ratio.width,params.scale_mode);
    return scaleframe;
}

void data_preprocess::set_crop_rect(Rect t){
    params.crop_rect = t;
    params.order |= (CROP << MODE_BITS*params.count);
    params.count ++;
}

Mat data_preprocess::image_crop(Mat frame_in) {
    return frame_in(params.crop_rect);
}


void data_preprocess::set_image_flip(int flip_code){
    params.flipcode = flip_code;
    params.order |= (FLIP << MODE_BITS*params.count);
    params.count ++;
}

Mat data_preprocess::image_flip(Mat frame_in) {
    Mat frame;
    flip(frame_in,frame,params.flipcode);
    return frame;
}


bool data_preprocess::get_next_batch_images()
{
    Mat frame;
    unsigned char order;

    for(int i = 0; i < data_source_queue_in->size(); i++){
        frame = data_source_queue_in->front();
        data_source_queue_in->pop();
        order = params.order;
        //bypass mode
        while(true){
            if(order == 0){
                data_preprocess_queue_out->push(frame);
                break;
            } else {
                if ((order & MODE_MASK) == SCALE) {
                    frame = image_scale(frame);
                } else if ((order & MODE_MASK) == CROP) {
                    frame = image_crop(frame);
                } else if ((order & MODE_MASK) == FLIP) {
                    frame = image_flip(frame);
                }
            }
            order >>= MODE_BITS;
        }
    }

    return true;
}


//debug only
void data_preprocess::dump_images(char *baseName) {
    if(data_preprocess_queue_out == NULL) return;

    std::queue<Mat> temp = *data_preprocess_queue_out;
    char image_name[256];
    for(int i =0; i < temp.size(); i ++)
    {
        sprintf(image_name,"%s_preprocess_%d.jpg",baseName,i);
        imwrite(image_name,temp.front());
        temp.pop();
    }
}

#if  0


int main (int argc, char **argv){

    Mat img = imread("/home/pyp/face_app/face_platform/models/data_source/t1.png",1);
    Mat img1;
    data_preprocess  data_preprocess_module;
    Size2d t(0.5,0.5);
    data_preprocess_module.set_scale_ratio(t);
    data_preprocess_module.set_scale_mode(1);

    data_preprocess_module.set_image_flip(0);

    return 1;
}
#endif