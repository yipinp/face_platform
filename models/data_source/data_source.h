/*
 *     The module will handle all inputs including image/video file input and camera input.
 *     Many others data sources will also be added in the future.
 *
 *     image_file                  queue
 *     image_dir     =>  process    =>  get_output_images queue
 *     cameraId
 *
 *
 *
 *
 *
 *
 */
#include <iostream>
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





} data_source_params;




class data_source {

public:
    void set_image_file(const char *name);
    void set_image_directory(const char *dir);
    void set_camera_id(const int cameraId);












};
