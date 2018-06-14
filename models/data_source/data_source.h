/*
 *     The module will handle all inputs including image/video file input and camera input.
 *     Many others data sources will also be added in the future.
 *
 *     image_file                  queue
 *     image_dir     =>  process    =>  get_output_images =>queue
 *     cameraId
 *
 *
 *
 *
 *
 *
 */
#ifndef _DATA_SOURCE_H_
#define _DATA_SOURCE_H_


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

typedef enum {
    SINGLE_IMAGE,
    DIR_SCAN_MODE,
    VIDEO_CAMERA,
} SOURCE_MODE;



typedef struct {
    //input source control
    SOURCE_MODE mode;
    string image_file;
    string dir_name;
    char camera_id;
    //output image number setting
    int batch_size;

} data_source_params;




class data_source {

public:
    data_source(std::queue<Mat> *data_source_queue_out);
    ~data_source();

public:
    //single file mode
    void set_image_file(string image_name);

    //dir scan mode
    void set_directory(string dir_name);

    //camera mode
    void set_camera_id(char camera_id);

    void set_batch_size(int size);

    bool get_next_batch_images();


    void dump_images(char *baseName);
private:
    data_source_params params;
    std::queue<Mat> *data_source_queue_out;

};

#endif
