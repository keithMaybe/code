#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int minDist;
int param1;
int param2;
String windowName = "霍夫圆检测";
vector<Vec3f> circles;              //用来存放检测到的圆参数矢量


int main()
{
    Mat srcImage,grayImage;
    srcImage = imread("ball.jpg");

    //判断文件是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    //初始化参数
    minDist = srcImage.rows/8;
    param1 = 100;
    param2 = 100;

    namedWindow(windowName, WINDOW_AUTOSIZE);
    
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    imshow("灰度图", grayImage);

    GaussianBlur(grayImage, grayImage, Size(3, 3), 2, 2);       //高斯滤波

    //霍夫圆检测
    HoughCircles(grayImage, circles, CV_HOUGH_GRADIENT, 1, minDist, param1, param2, 0, 0);

    //绘制检测到的圆
    for(size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(srcImage, center, 3, Scalar(0, 0, 255), -1, 8, 0);
        circle(srcImage, center, radius, Scalar(0, 0, 255), 3, 8, 0);
    }
    imshow(windowName, srcImage);

    waitKey(0);

    return 0;
}