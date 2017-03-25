#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage;         //定义输入图像
Mat g_dstImage;         //定义目标图像

const int g_nTrackbarMaxValue = 9;      //定义轨迹条最大值
int g_nTrackbarValue;                   //定义轨迹条初始值
int g_nKernelValue;                     //定义kernel尺寸

void on_kernelTrackbar(int, void*);     //定义回调函数

int main()
{
    g_srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(g_srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像",WINDOW_AUTOSIZE);     //定义窗口显示属性
    imshow("原图像",g_srcImage);

    g_nTrackbarValue = 1;
    namedWindow("均值滤波", WINDOW_AUTOSIZE);   //定义滤波后图像显示窗口属性

    //定义轨迹条名称和最大值
    char kernelName[20];
    sprintf(kernelName, "kernel尺寸 %d", g_nTrackbarMaxValue);    

    //创建轨迹条
    createTrackbar(kernelName, "均值滤波", &g_nTrackbarValue, g_nTrackbarMaxValue, on_kernelTrackbar);
    on_kernelTrackbar(g_nTrackbarValue, 0);

    waitKey(0);

    return 0;
}

void on_kernelTrackbar(int, void*)
{
    //根据输入值重新计算kernel尺寸
    g_nKernelValue = g_nTrackbarValue * 2 + 1;

    //均值滤波函数
    blur(g_srcImage, g_dstImage, Size(g_nKernelValue, g_nKernelValue));

    imshow("均值滤波", g_dstImage);
}