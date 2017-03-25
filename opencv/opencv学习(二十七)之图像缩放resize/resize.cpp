/*
 *程序主要演示了不同的插值算法在图像缩放中效果不同
 *其中图像放大图像原图像用的是缩小后的图像
 *也可以将g_shrinkImage改为g_srcImage观察直接从原图像放大效果
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage;
Mat g_shrinkImage;
Mat g_enlargeImage;

//定义轨迹条属性
const int resizeTypeMaxValue = 4;   //共八种插值运算类型
int resizeTypeValue = 0;

//声明类型转换函数
int typeDef(int typeNum);

//声明回调函数
void shrinkFun(int, void*);
void enlargeFun(int, void*);

int main()
{
    g_srcImage = imread("resize.jpg");

    //判断文件是否加载成功
    if(!g_srcImage.data)
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", g_srcImage);

    //轨迹条属性
    char resizeTypeName[20];
    sprintf(resizeTypeName, "插值运算类型 %d", resizeTypeMaxValue);

    namedWindow("图像缩小", WINDOW_AUTOSIZE);
    namedWindow("图像放大", WINDOW_AUTOSIZE);

    //创建轨迹条
    createTrackbar(resizeTypeName, "图像缩小", &resizeTypeValue, resizeTypeMaxValue, shrinkFun);
    shrinkFun(resizeTypeValue, 0);

    createTrackbar(resizeTypeName, "图像放大", &resizeTypeValue, resizeTypeMaxValue, enlargeFun);
    enlargeFun(resizeTypeValue, 0);

    waitKey(0);

    return 0;
}

int typeDef(int typeNum)
{
    int type;

    switch(typeNum)
    {
    case 0:
            type = INTER_NEAREST; break;
    case 1:
            type = INTER_LINEAR; break;
    case 2:
            type = INTER_CUBIC; break;
    case 3:
            type = INTER_AREA; break;
    case 4:
            type = INTER_LANCZOS4; break;
    default:
            break;
    }

    return type;

}

//图像缩小函数
void shrinkFun(int, void*)
{
    int shrinkType;
    shrinkType = typeDef(resizeTypeValue);
    resize(g_srcImage, g_shrinkImage, Size(g_srcImage.cols/2, g_srcImage.rows/2), 0, 0, shrinkType);
    imshow("图像缩小", g_shrinkImage);
}

//图像放大函数
void enlargeFun(int, void*)
{
    int enlargeType;
    enlargeType = typeDef(resizeTypeValue);
    resize(g_shrinkImage, g_enlargeImage, Size(g_shrinkImage.cols*2, g_shrinkImage.rows*2), 0, 0, enlargeType);
    imshow("图像放大", g_enlargeImage);
}