#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//声明全局变量
Mat srcImage, grayImage, dstImage;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;           //阈值倍数
int kernel_size = 3;    //Sobel算子孔径尺寸
String windowName =  "Canny算子边缘检测";

//声明回调函数
void CannyThreshold(int, void*);

int main()
{
    srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    //高斯滤波
    GaussianBlur(srcImage, srcImage, Size(3, 3), 0, 0, BORDER_DEFAULT);
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", grayImage);

    //定义轨迹条属性
    namedWindow(windowName, WINDOW_AUTOSIZE);
    char trackbarName[20];
    sprintf(trackbarName, "阈值", max_lowThreshold);
    lowThreshold = 20;

    //创建轨迹条
    createTrackbar(trackbarName, windowName, &lowThreshold, max_lowThreshold, CannyThreshold);
    CannyThreshold(lowThreshold, 0);
    
    waitKey(0);

    return 0;
}

void CannyThreshold(int, void*)
{
    Canny(grayImage, dstImage, lowThreshold, lowThreshold*ratio, kernel_size);

    imshow(windowName, dstImage);
}