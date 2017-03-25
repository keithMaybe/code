#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//声明全局变量
Mat srcImage, grayImage, dstImage, dst_absImage;
const int scale = 1;
const int delta = 0;
const int ddepth = CV_16S;
const int kernelSizeMaxValue = 3;
int kernelSizeValue;

//声明回调函数
void laplacianFun(int, void*);
String windowName = "Laplace算子边缘检测";

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

    //对图像进行高斯滤波操作
    GaussianBlur(srcImage, srcImage, Size(3, 3), 0, 0, BORDER_DEFAULT);
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);      //将图像转换为灰度图
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", grayImage);

    namedWindow(windowName, WINDOW_AUTOSIZE);
    kernelSizeValue = 1;        //轨迹条初始值为1
    char trackbarName[20];      //轨迹条名称
    sprintf(trackbarName, "laplacian算子kernel尺寸", kernelSizeMaxValue);
    
    //创建轨迹条
    createTrackbar(trackbarName, windowName, &kernelSizeValue, kernelSizeMaxValue, laplacianFun);
    laplacianFun(kernelSizeValue, 0);       //调用回调函数

    waitKey(0);

    return 0;
}

void laplacianFun(int, void*)
{
    //重新计算kernel的尺寸
    int kernelSize;
    kernelSize = kernelSizeValue * 2 + 1;

    Laplacian(grayImage, dstImage, ddepth, kernelSize, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(dstImage, dst_absImage);
    imshow(windowName, dst_absImage);
}