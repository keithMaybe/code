#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_SrcImage, g_DstImage;
const int g_nAlphaTrackbarMaxValue = 30;    //滑动条最大值
const int g_nBetaTrackbarMaxValue = 100;
int g_nAlphaTrackValue;                  //滑动条对比度对应值
int g_nBetaTrackValue;                   //滑动条亮度对应值
double g_dAlpahValue;
//double g_dBetaValue;

//声明回调函数
void on_AlphaTrackbar(int, void*);
void on_BetaTrackbar(int, void*);

int main()
{
    g_SrcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(g_SrcImage.empty())
    {
        cout << "图像加载失败!" << endl << endl;
        return -1;
    }   
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像",WINDOW_AUTOSIZE);
    imshow("原图像",g_SrcImage);

    g_DstImage = Mat::zeros(g_SrcImage.size(),g_SrcImage.type());     

    namedWindow("图像调节",WINDOW_AUTOSIZE);          //声明轨迹条依附的窗口
    g_nAlphaTrackValue = 10;                      //轨迹条中alpha初始值
    g_nBetaTrackValue = 50;                       //轨迹条中beta初始值

    //在创建的窗体中创建轨迹条并命名
    char alphaTrackName[50];
    char betaTrackName[50];
    sprintf(alphaTrackName,"对比度 %d", g_nAlphaTrackbarMaxValue);
    sprintf(betaTrackName,"亮 度 %d",g_nBetaTrackbarMaxValue);

    //创建对比度调节和亮度调节的轨迹条
    createTrackbar(alphaTrackName,"图像调节",&g_nAlphaTrackValue,g_nAlphaTrackbarMaxValue,on_AlphaTrackbar);
    createTrackbar(betaTrackName,"图像调节",&g_nBetaTrackValue,g_nBetaTrackbarMaxValue,on_BetaTrackbar);

    //调用回调函数
    on_AlphaTrackbar(g_nAlphaTrackValue, 0);
    on_BetaTrackbar(g_nBetaTrackValue, 0);
    
    waitKey(0);

    return 0;
}

void on_AlphaTrackbar(int, void*)
{
    g_dAlpahValue = (double)g_nAlphaTrackValue / 10;
    for(int y = 0; y < g_DstImage.rows; y++)
    {
        for(int x = 0; x < g_DstImage.cols; x++)
        {
            for(int c = 0; c < 3; c++)
            {
                g_DstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(g_dAlpahValue * 
                (g_SrcImage.at<Vec3b>(y, x)[c]));
            }
        }
    }
    imshow("图像调节",g_DstImage);
}

void on_BetaTrackbar(int, void*)
{
    for(int y = 0; y < g_DstImage.rows; y++)
    {
        for(int x = 0; x < g_DstImage.cols; x++)
        {
            for(int c = 0; c < 3; c++)
            {
                g_DstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_SrcImage.at<Vec3b>(y, x)[c]) + 
                g_nBetaTrackValue);
            }
        }
    }
    imshow("图像调节",g_DstImage);
}