#include "detection_alignment.h"
#include "common.h"

detection_alignment::detection_alignment()
{


}

detection_alignment::~detection_alignment()
{


}



bool detection_alignment::dlib_face_detection_alignment(Mat image)
{
    //cv_image<bgr_pixel> dlib_img(image);
    dlib::array2d<bgr_pixel> dlib_img;
    dlib::assign_image(dlib_img, dlib::cv_image<bgr_pixel>(image));
   // pyramid_up(dlib_img);
    frontal_face_detector detector = get_frontal_face_detector();
    shape_predictor sp;
    std::vector<dlib::rectangle> faces = detector(dlib_img);
    cout <<"Number of faces detected:"<<faces.size()<<endl;
    cv::Rect rect;

    std::vector<full_object_detection> shapes;
    for (int i = 0; i < faces.size(); i++){
        full_object_detection shape = sp(dlib_img, faces[i]);
        cout << "number of parts: "<< shape.num_parts() << endl;
        shapes.push_back(shape);

        rect = convert_dlib2cv_rectangle(faces[i]);
        cv::rectangle(image,rect,Scalar(0,0,255),3,8,0);

    }

    dlib::array<array2d<rgb_pixel> > face_chips;
    extract_image_chips(dlib_img, get_face_chip_details(shapes), face_chips);

    namedWindow("faces",1);
    imshow("image",image);
    waitKey(10000);

    return true;
}



int main(int argc, char **argv)
{
    //char imageName[256] = "/home/pyp/face_app/face_platform/models/detection_alignment/multiple_faces.jpg";
    char imageName[256] = "/home/pyp/face_app/face_platform/models/detection_alignment/t2.jpeg";
    Mat img = imread(imageName,1);

    detection_alignment *dlib_detector = new detection_alignment();

    dlib_detector->dlib_face_detection_alignment(img);
}


//
//int main()
//{
//    try
//    {
//        cv::VideoCapture cap(0);
//        if (!cap.isOpened())
//        {
//            cerr << "Unable to connect to camera" << endl;
//            return 1;
//        }
//
//        image_window win;
//
//        // Load face detection and pose estimation models.
//        frontal_face_detector detector = get_frontal_face_detector();
//        shape_predictor pose_model;
//        deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;
//
//        // Grab and process frames until the main window is closed by the user.
//        while(!win.is_closed())
//        {
//            // Grab a frame
//            cv::Mat temp;
//            if (!cap.read(temp))
//            {
//                break;
//            }
//            // Turn OpenCV's Mat into something dlib can deal with.  Note that this just
//            // wraps the Mat object, it doesn't copy anything.  So cimg is only valid as
//            // long as temp is valid.  Also don't do anything to temp that would cause it
//            // to reallocate the memory which stores the image as that will make cimg
//            // contain dangling pointers.  This basically means you shouldn't modify temp
//            // while using cimg.
//            cv_image<bgr_pixel> cimg(temp);
//
//            // Detect faces
//            std::vector<dlib::rectangle> faces = detector(cimg);
//            // Find the pose of each face.
//            std::vector<full_object_detection> shapes;
//            for (unsigned long i = 0; i < faces.size(); ++i)
//                shapes.push_back(pose_model(cimg, faces[i]));
//
//            // Display it all on the screen
//            win.clear_overlay();
//            win.set_image(cimg);
//            win.add_overlay(render_face_detections(shapes));
//        }
//    }
//    catch(serialization_error& e)
//    {
//        cout << "You need dlib's default face landmarking model file to run this example." << endl;
//        cout << "You can get it from the following URL: " << endl;
//        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
//        cout << endl << e.what() << endl;
//    }
//    catch(exception& e)
//    {
//        cout << e.what() << endl;
//    }
//}