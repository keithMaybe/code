#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const int g_nTrackBarMaxValue = 9;      //轨迹条最大值
int g_nTrackBarValue;                   //轨迹条初始值
Mat g_srcImage, g_dstImage;             //定义图像全局变量
int g_nKernelTrackbarValue;             //定义轨迹条的值

void on_kernelTrackbar(int, void*);

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

    namedWindow("原图像",WINDOW_AUTOSIZE);
    imshow("原图像", g_srcImage);            //显示原图像

    g_nTrackBarValue = 1;                   //初始化轨迹条初始值
    namedWindow("方框滤波",WINDOW_AUTOSIZE);      //轨迹条依附窗口
    char kernelName[20];
    sprintf(kernelName, "滤波kernel %d",g_nTrackBarMaxValue);

    //创建轨迹条
    createTrackbar(kernelName, "方框滤波", &g_nTrackBarValue,g_nTrackBarMaxValue,on_kernelTrackbar);
    on_kernelTrackbar(g_nTrackBarValue, 0);

    waitKey(0);

    return 0;
}

void on_kernelTrackbar(int, void*)
{
    //根据输入值重新计算kernel尺寸，见程序详解
    g_nKernelTrackbarValue = g_nTrackBarValue * 2 + 3;

    //方框滤波函数
    boxFilter(g_srcImage, g_dstImage, -1, Size(g_nKernelTrackbarValue, g_nKernelTrackbarValue));
    imshow("方框滤波", g_dstImage);
}