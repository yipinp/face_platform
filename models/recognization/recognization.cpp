#include <iostream>
#include "recognization.h"

recognization::recognization()
{


}

recognization::recognization(std::queue<Mat> *img_faces_in)
                : img_faces(img_faces_in)
{


}


recognization::~recognization()
{

}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}