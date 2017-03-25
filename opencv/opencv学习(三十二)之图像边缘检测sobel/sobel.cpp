#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//声明全局变量
const int sobel_kernel_size_maxValue = 3;   //kernel尺寸最大值
int sobel_kernel_size_value;                //kernel尺寸

Mat srcImage, dstImage, grayImage, x_gradImage, y_gradImage;
Mat x_abs_gradImage, y_abs_gradImage;
String windowName = "Sobel算子边缘检测";

int depth = 0;      //输出图像与原图像一致
int scale = 1;      //可选缩放因子
int delta = 0;      //可选的delta

//声明轨迹条回调函数
void sobelFun(int, void*);

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

    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);   //图像转换灰度图
    namedWindow("原图像灰度图", WINDOW_AUTOSIZE);
    imshow("原图像灰度图", grayImage);

    namedWindow(windowName, WINDOW_AUTOSIZE);       //创建窗口
    
    //设置轨迹条属性
    sobel_kernel_size_value = 1;
    char kernelSizeName [20];
    sprintf(kernelSizeName, "Sobel算子kernel尺寸", sobel_kernel_size_maxValue);

    //创建轨迹条
    createTrackbar(kernelSizeName, windowName, &sobel_kernel_size_value,
                    sobel_kernel_size_maxValue, sobelFun);
    
    //调用回调函数
    sobelFun(sobel_kernel_size_value, 0);

    waitKey(0);

    return 0;
}

//回调函数
void sobelFun(int, void*)
{
    //重新计算尺寸kernel尺寸数值
    int kernelvalue;
    kernelvalue = sobel_kernel_size_value * 2 + 1;

    //计算x方向梯度
    Sobel(grayImage, x_gradImage, depth, 1, 0, kernelvalue, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(x_gradImage, x_abs_gradImage);
    namedWindow("x方向的sobel边缘检测", WINDOW_AUTOSIZE);
    imshow("x方向的sobel边缘检测", x_abs_gradImage);

    //计算y方向梯度
    Sobel(grayImage, y_gradImage, depth, 0, 1, kernelvalue, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(y_gradImage, y_abs_gradImage);
    namedWindow("y方向上的sobel边缘检测", WINDOW_AUTOSIZE);
    imshow("y方向上的sobel边缘检测", y_abs_gradImage);

    //将x方向和y方向的梯度叠加
    addWeighted(x_abs_gradImage, 0.5, y_abs_gradImage, 0.5, 0, dstImage);
    

    imshow(windowName, dstImage);
}