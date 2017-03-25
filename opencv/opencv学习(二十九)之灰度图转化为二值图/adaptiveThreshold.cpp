#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat srcImage, grayImage, dstImage;

const int thresholdTypeMaxValue = 1;
int thresholdTypeValue = 0;
const int CMaxValue = 50;
int CValue = 10;
const double maxValue = 255;
int blockSize = 5;

//定义回调函数
void adaptiveThresholdFun(int, void*);

int main()
{
    Mat srcImage = imread("lena.jpg");

    //判断图像是否读取成功
    if(srcImage.empty())
    {
        cout << "图像读取失败!" << endl;
        return -1;
    }
    else
        cout << "图像读取成功!" << endl << endl;

    cvtColor(srcImage, grayImage, COLOR_RGB2GRAY);
    namedWindow("灰度图",WINDOW_AUTOSIZE);
    imshow("灰度图", grayImage);

    //轨迹条属性和依附窗口设置
    namedWindow("二值图像", WINDOW_AUTOSIZE);
    char thresholdTypeName[20];
    sprintf(thresholdTypeName, "阈值类型\n 0: THRESH_BINARY\n 1: THRESH_BINARY_INV ", thresholdTypeMaxValue);
    createTrackbar(thresholdTypeName, "二值图像", &thresholdTypeValue, thresholdTypeMaxValue, adaptiveThresholdFun);
    adaptiveThresholdFun(thresholdTypeValue, 0);

    char CName[20];
    sprintf(CName, "常  数 %d", CMaxValue);
    createTrackbar(CName, "二值图像", &CValue, CMaxValue, adaptiveThresholdFun);
    adaptiveThresholdFun(CValue, 0);
    

    waitKey(0);
    return 0;
}

void adaptiveThresholdFun(int, void*)
{
    int thresholdType;
    switch(thresholdTypeValue)
    {
    case 0:
        thresholdType = THRESH_BINARY;
        break;

    case 1:
        thresholdType = THRESH_BINARY_INV;
        break;

    default:
        break;
    }
    adaptiveThreshold(grayImage, dstImage, maxValue, ADAPTIVE_THRESH_MEAN_C,
                        thresholdType, blockSize, CValue);
    
    imshow("二值图像", dstImage);
}