#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage;         //输入图像
Mat g_dstImage;         //输出图像

//定义轨迹条最大值参量
const int g_nKwidthTrackBarMaxValue = 9;
const int g_nKheightTrackBarMaxValue = 9;
const int g_nsigmaXTrackBarMaxValue = 5;
const int g_nsigmaYTrackBarMaxvalue = 5;

//定义每个轨迹条的初始值
int g_nKwidthTrackBarValue = 1;
int g_nKheightTrackBarValue = 1;
int g_nsigmaXTrackBarValue = 1;
int g_nsigmaYTrackBarValue = 1;

int g_kernelWidthValue;
int g_kernelHeightValue;

void on_GaussianBlurTrackbar(int, void*);       //定义回调函数

int main()
{
    g_srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(!g_srcImage.data)
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像", WINDOW_NORMAL);         //定义窗口显示属性
    imshow("原图像", g_srcImage);

    namedWindow("高斯滤波图像", WINDOW_NORMAL);

    //定义每个轨迹条名字
    char widthTrackBarName[20];
    sprintf(widthTrackBarName, "核函数width %d", g_nKwidthTrackBarMaxValue);

    char heightTrackBarName[20];
    sprintf(heightTrackBarName,"核函数height %d", g_nKheightTrackBarMaxValue);

    char sigmaXTrackBarName[20];
    sprintf(sigmaXTrackBarName, "核函数sigmaX %d", g_nsigmaXTrackBarMaxValue);

    char sigmaYTrackBarName[20];
    sprintf(sigmaYTrackBarName, "核函数sigmaY %d", g_nsigmaYTrackBarMaxvalue);

    //创建轨迹条
    createTrackbar(widthTrackBarName, "高斯滤波图像", &g_nKwidthTrackBarValue, 
                    g_nKwidthTrackBarMaxValue, on_GaussianBlurTrackbar);
    on_GaussianBlurTrackbar(g_nKwidthTrackBarValue, 0);

    createTrackbar(heightTrackBarName, "高斯滤波图像", &g_nKheightTrackBarValue,
                    g_nKheightTrackBarMaxValue, on_GaussianBlurTrackbar);
    on_GaussianBlurTrackbar(g_nKheightTrackBarValue, 0);
    
    createTrackbar(sigmaXTrackBarName, "高斯滤波图像", &g_nsigmaXTrackBarValue,
                    g_nsigmaXTrackBarMaxValue, on_GaussianBlurTrackbar);
    on_GaussianBlurTrackbar(g_nsigmaXTrackBarValue, 0);

    createTrackbar(sigmaYTrackBarName, "高斯滤波图像", &g_nsigmaYTrackBarValue,
                    g_nsigmaYTrackBarMaxvalue, on_GaussianBlurTrackbar);
    on_GaussianBlurTrackbar(g_nsigmaYTrackBarValue, 0);

    waitKey(0);

    return 0;
}

void on_GaussianBlurTrackbar(int, void*)
{
    //根据输入的width和height重新计算ksize.width和ksize.height
    g_kernelWidthValue = g_nKwidthTrackBarValue * 2 + 1;
    g_kernelHeightValue = g_nKheightTrackBarValue * 2 + 1;

    //高斯滤波
    GaussianBlur(g_srcImage, g_dstImage, Size(g_kernelWidthValue, g_kernelHeightValue),
                g_nsigmaXTrackBarValue, g_nsigmaYTrackBarValue);
    
    imshow("高斯滤波图像", g_dstImage);
}