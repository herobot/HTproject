//文件名字Dis.cpp
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main( )
{
    Mat image;
    image = imread("/home/herobot/predictions.png", 1 );//目录按照自己的目录
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(10000);
    return 0;
}
