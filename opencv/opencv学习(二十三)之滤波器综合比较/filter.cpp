/*
 *本程序的目的旨在对前面介绍的滤波器进行一个比较
 *对比每种滤波器的滤波效果和耗时
 *除双边滤波外其他滤波器kernel均是5*5或5
 *对于双边滤波器取其直径典型值30
 *sigmaColor和sigmaSpace的值均由直径计算而来
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("lena.jpg");

    if(srcImage.empty())
    {
        cout << "图片加载失败!" << endl;
        return -1;
    }
    else
        cout << "图片加载成功!" << endl << endl;
    
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", srcImage);

    /********************方框滤波*******************/
    Mat dstImage_boxFilter;
    double time_boxFilter = static_cast<double>(getTickCount());
    boxFilter(srcImage, dstImage_boxFilter, -1, Size(5, 5));
    time_boxFilter = ((double)getTickCount()-time_boxFilter)/getTickFrequency();
    cout << "方框滤波耗时: " << time_boxFilter << " s" << endl;
    namedWindow("方框滤波图像", WINDOW_AUTOSIZE);
    imshow("方框滤波图像", dstImage_boxFilter);

    /********************均值滤波*****************/
    Mat dstImage_blur;
    double time_blur = static_cast<double>(getTickCount());
    blur(srcImage, dstImage_blur, Size(5, 5));
    time_blur = ((double)getTickCount()-time_blur)/getTickFrequency();
    cout << "均值滤波耗时: " << time_blur << " s" << endl;
    namedWindow("均值滤波图像", WINDOW_AUTOSIZE);
    imshow("均值滤波图像", dstImage_blur);

    /********************高斯滤波******************/
    Mat dstImage_GaussianBlur;
    double time_GaussianBlur = static_cast<double>(getTickCount());
    GaussianBlur(srcImage, dstImage_GaussianBlur, Size(5, 5), 0, 0);
    time_GaussianBlur = ((double)getTickCount()-time_GaussianBlur)/getTickFrequency();
    cout << "高斯滤波耗时: " << time_GaussianBlur << " s" << endl;
    namedWindow("高斯滤波图像", WINDOW_AUTOSIZE);
    imshow("高斯滤波图像", dstImage_GaussianBlur);

    /*******************中值滤波*******************/
    Mat dstImage_medianBlur;
    double time_medianBlur=static_cast<double>(getTickCount());
    medianBlur(srcImage, dstImage_medianBlur, 5);
    time_medianBlur = ((double)getTickCount()-time_medianBlur)/getTickFrequency();
    cout << "中值滤波耗时: " << time_medianBlur << " s" << endl;
    namedWindow("中值滤波图像", WINDOW_AUTOSIZE);
    imshow("中值滤波图像", dstImage_medianBlur);

    /******************双边滤波******************/
    Mat dstImage_bilateralFilter;
    double time_bilateralFilter = static_cast<double>(getTickCount());
    bilateralFilter(srcImage, dstImage_bilateralFilter, 30, 60, 15);
    time_bilateralFilter=((double)getTickCount()-time_bilateralFilter)/getTickFrequency();
    cout << "双边滤波耗时: " << time_bilateralFilter << " s" << endl;
    namedWindow("双边滤波图像", WINDOW_AUTOSIZE);
    imshow("双边滤波图像", dstImage_bilateralFilter);

    waitKey(0);

    return 0;
}