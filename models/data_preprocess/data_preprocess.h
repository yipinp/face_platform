#ifndef _DATA_PREPROCESS_H_
#define _DATA_PREPROCESS_H_

#include <iostream>
#include <string>
#include <queue>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

typedef struct {
    //scale
    Size scale_size;
    Size2d scale_ratio;
    int scale_mode; //0-Nearest, 1: Linear, 2:cubic, 3: Area 4: lanczos4

    //crop
    Rect crop_rect;

} data_preprocess_params;



class data_preprocess{
public:
    data_preprocess();
    data_preprocess(std::queue<Mat> *data_source_queue_in,std::queue<Mat> *data_preprocess_queue_out);
    ~data_preprocess();

public:
    //public API
    void set_scale_size(Size t);
    void set_scale_ratio(Size2d ratio);
    void set_scale_mode(int mode);
    Mat image_scale(Mat frame_in);
    //crop
    void set_crop_rect(Rect t);
    Mat image_crop(Mat frame_in);
    Mat image_flip(Mat frame_in);

private:
    void reset();


private:
    std::queue<Mat> *data_source_queue_in;
    std::queue<Mat> *data_preprocess_queue_out;
    data_preprocess_params params;

};



#endif
