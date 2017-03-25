/*
 *程序通过创建trackbar来控制阈值化类型
 *通过调节trackbar来调节
 *其具体阈值化类型如下：
 *0: THRESH_BINARY 二进制阈值化
 *1: THRESH_BINARY_INV 反二进制阈值化
 *2: THRESH_TRUNC 截断阈值化
 *3: THRESH_TOZERO 阈值化为0
 *4: THRESH_TOZERO_INV 反阈值化为0
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage, g_srcGrayImage, g_dstImage;

const int typeMaxValue = 4;
int typeValue = 0;
const int binaryMaxValue = 255;

const int thresholdMaxValue = 255;      //阈值的最大值
int thresholdValue = 0;     //阈值的初始值

//定义回调函数
void thresholdFun(int, void*);

int main()
{
    g_srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(g_srcImage.empty())
    {
        cout << "图像记载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    cvtColor(g_srcImage, g_srcGrayImage, COLOR_RGB2GRAY);   //将图像转化为灰度图

    //创建轨迹条及其依附窗口
    namedWindow("图像阈值化处理", WINDOW_AUTOSIZE);

    char threasholdTypeName[20];
    sprintf(threasholdTypeName, "阈值化类型 %d", typeMaxValue);
    createTrackbar(threasholdTypeName, "图像阈值化处理", &typeValue, typeMaxValue, thresholdFun);
    thresholdFun(typeValue, 0);

    char thresholdValueName[20];
    sprintf(thresholdValueName, "阈   值 %", thresholdMaxValue);
    createTrackbar(thresholdValueName, "图像阈值化处理", &thresholdValue, thresholdMaxValue, thresholdFun);
    thresholdFun(thresholdValue, 0);

    waitKey(0);

    return 0;
}

//回调函数
void thresholdFun(int, void*)
{
    int thresholdType;
    switch(typeValue)
    {
    case 0:
        thresholdType = THRESH_BINARY;
        break;
    case 1:
        thresholdType = THRESH_BINARY_INV;
        break;
    case 2:
        thresholdType = THRESH_TRUNC;
        break;
    case 3:
        thresholdType = THRESH_TOZERO;
        break;
    case 4:
        thresholdType = THRESH_TOZERO_INV;
        break;
    default:
        break;
    }

    //图像阈值化处理
    threshold(g_srcGrayImage, g_dstImage, thresholdValue, binaryMaxValue, thresholdType);   

    imshow("图像阈值化处理", g_dstImage);
}