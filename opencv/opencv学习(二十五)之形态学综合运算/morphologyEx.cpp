/*
 *本程序将会产生5副目标图片与原图像进行对比
 *每幅图像采用的模板Type和Size均可通过轨迹条进行调节
 *如有兴趣也可尝试使用轨迹条改变形态学的运算类型可大幅减少代码量
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage;
Mat g_dstImageOpen, g_dstImageClose, g_dstImageGradient;
Mat g_dstImageTopHat, g_dstImageBlackHat;

//定义两个轨迹条参数
const int kernelTypeMaxValue = 2;
const int kernelSizeMaxValue = 20;
int kernelTypeValue = 1;
int kernelSizeValue = 10;

//定义模板类型声明函数
int kernelTypeFun(int kernelTypeValue);

//定义两个回调函数
void openOperation(int, void*);
void closeOperation(int, void*);
void gradientOperation(int, void*);
void topHatOperation(int, void*);
void blackHatOperation(int, void*);

int main()
{
    g_srcImage = imread("baboon.jpg");

    //判断图像是否加载成功
    if(!g_srcImage.data)
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", g_srcImage);

    //定义轨迹条参数
    char kernelTypeName[20];
    char kernelSizeName[20];

    sprintf(kernelTypeName, "模板类型 %d\n 0-Rect\n 1-Cross\n 2-Ellipse", kernelTypeMaxValue);
    sprintf(kernelSizeName, "模板尺寸 %d", kernelSizeMaxValue);

    namedWindow("开运算", WINDOW_AUTOSIZE);
    namedWindow("闭运算", WINDOW_AUTOSIZE);
    namedWindow("形态学梯度", WINDOW_AUTOSIZE);
    namedWindow("顶帽", WINDOW_AUTOSIZE);
    namedWindow("黑帽", WINDOW_AUTOSIZE);

    //创建两个轨迹条
    createTrackbar(kernelTypeName, "开运算", &kernelTypeValue, kernelTypeMaxValue, openOperation);
    createTrackbar(kernelSizeName, "开运算", &kernelSizeValue, kernelSizeMaxValue, openOperation);
    openOperation(kernelTypeValue, 0);
    openOperation(kernelSizeValue, 0);

    createTrackbar(kernelTypeName, "闭运算", &kernelTypeValue, kernelTypeMaxValue, closeOperation);
    createTrackbar(kernelSizeName, "闭运算", &kernelSizeValue, kernelSizeMaxValue, closeOperation);
    openOperation(kernelTypeValue, 0);
    openOperation(kernelSizeValue, 0);

    createTrackbar(kernelTypeName, "形态学梯度", &kernelTypeValue, kernelTypeMaxValue, gradientOperation);
    createTrackbar(kernelSizeName, "形态学梯度", &kernelSizeValue, kernelSizeMaxValue, gradientOperation);
    openOperation(kernelTypeValue, 0);
    openOperation(kernelSizeValue, 0);

    createTrackbar(kernelTypeName, "顶帽", &kernelTypeValue, kernelTypeMaxValue, topHatOperation);
    createTrackbar(kernelSizeName, "顶帽", &kernelSizeValue, kernelSizeMaxValue, topHatOperation);
    openOperation(kernelTypeValue, 0);
    openOperation(kernelSizeValue, 0);

    createTrackbar(kernelTypeName, "黑帽", &kernelTypeValue, kernelTypeMaxValue, blackHatOperation);
    createTrackbar(kernelSizeName, "黑帽", &kernelSizeValue, kernelSizeMaxValue, blackHatOperation);
    openOperation(kernelTypeValue, 0);
    openOperation(kernelSizeValue, 0);

    

    waitKey(0);

    return 0;
}

//形态学操作模板类型判断
int kernelTypeFun(int kernelTypeValue)
{
    int kernel_type;
    if(kernelTypeValue == 0)
        kernel_type = MORPH_RECT;
    else if(kernelTypeValue == 1)
        kernel_type = MORPH_CROSS;
    else
        kernel_type = MORPH_ELLIPSE;

    return kernel_type;
}

//开运算
void openOperation(int, void*)
{
    int kernel_type;
    kernel_type = kernelTypeFun(kernelTypeValue);
    
    Mat element = getStructuringElement(kernel_type, Size(kernelSizeValue * 2 + 1,
                    kernelSizeValue * 2 + 1));
    morphologyEx(g_srcImage, g_dstImageOpen, MORPH_OPEN, element);
    imshow("开运算", g_dstImageOpen);
}

//闭运算
void closeOperation(int, void*)
{
    int kernel_type;
    kernel_type = kernelTypeFun(kernelTypeValue);
    
    Mat element = getStructuringElement(kernel_type, Size(kernelSizeValue * 2 + 1,
                    kernelSizeValue * 2 + 1));
    morphologyEx(g_srcImage, g_dstImageClose, MORPH_CLOSE, element);
    imshow("闭运算", g_dstImageClose);
}

//形态学梯度
void gradientOperation(int, void*)
{
    int kernel_type;
    kernel_type = kernelTypeFun(kernelTypeValue);
    
    Mat element = getStructuringElement(kernel_type, Size(kernelSizeValue * 2 + 1,
                    kernelSizeValue * 2 + 1));
    morphologyEx(g_srcImage, g_dstImageGradient, MORPH_GRADIENT, element);
    imshow("形态学梯度", g_dstImageGradient);
}

//顶帽
void topHatOperation(int, void*)
{
    int kernel_type;
    kernel_type = kernelTypeFun(kernelTypeValue);
    
    Mat element = getStructuringElement(kernel_type, Size(kernelSizeValue * 2 + 1,
                    kernelSizeValue * 2 + 1));
    morphologyEx(g_srcImage, g_dstImageTopHat, MORPH_TOPHAT, element);
    imshow("顶帽", g_dstImageTopHat);
}

//黑帽
void blackHatOperation(int, void*)
{
    int kernel_type;
    kernel_type = kernelTypeFun(kernelTypeValue);
    
    Mat element = getStructuringElement(kernel_type, Size(kernelSizeValue * 2 + 1,
                    kernelSizeValue * 2 + 1));
    morphologyEx(g_srcImage, g_dstImageBlackHat, MORPH_BLACKHAT, element);
    imshow("黑帽", g_dstImageBlackHat);
}