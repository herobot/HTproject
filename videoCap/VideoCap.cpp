#include<stdio.h>
#include<math.h>
#include "highgui.h"
#include <cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    //视频保存位置
    string outputVideoPath = "..\\test.avi";  

    //打开摄像头
    VideoCapture capture0(0);  
	if(!capture0.isOpened())  
		return -1;
	 capture0.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	 capture0.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	 capture0.set(CV_CAP_PROP_FPS, 30);

    //VideoWriter outputVideo;
    //获取当前摄像头的视频信息
    /*
      cv::Size S = cv::Size((int)capture0.get(CV_CAP_PROP_FRAME_WIDTH),
                         (int)capture0.get(CV_CAP_PROP_FRAME_HEIGHT));
   */
    //设置写视频的路径，设置基本信息
    VideoWriter outputVideo("VideoTest2.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30.0, Size(320, 240));

    if (!outputVideo.isOpened()) 
    {
        cout << "fail to open!" << endl;
        return -1;
    }


    cv::Mat frameImage;
    int count = 0;

    while(true)
    {
        //读取当前帧
        capture0 >> frameImage;

        if (frameImage.empty()) break;

        ++count;
        //输出当前帧
        cv::imshow("output", frameImage);
        //保存当前帧
        outputVideo << frameImage;

        if (char(waitKey(1)) == 'q') break;
    }

    std::cout << "TotalFrame: " << count << std::endl;
}
