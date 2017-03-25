#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    double timeConsume = static_cast<double>(getTickCount());
    Mat grayImage(400, 600, CV_8UC1);       //创建一个大小为600x800的单通道灰度图
    Mat colorImage(400, 600, CV_8UC3);      //创建一个大小为600x800的三通道彩色图

    //遍历所有像素并设置像素值
    for(int i = 0; i < grayImage.rows; ++i)         //遍历行
        for(int j = 0; j < grayImage.cols; ++j)     //遍历列
            grayImage.at<uchar>(i, j) = (i + j) % 255;

    //遍历所有像素并设置像素值
    
    for(int i = 0; i < colorImage.rows; ++i)         //遍历行
        for(int j = 0; j < colorImage.cols; ++j)     //遍历列
        {
            Vec3b pixel;            //定义三通道像素值变量
            pixel[0] = i % 255;     //Blue
            pixel[1] = j % 255;     //Green
            pixel[2] = 0;           //Red

            colorImage.at<Vec3b>(i, j) = pixel;
        }
            
    //显示简历图像的结果
    namedWindow("grayImage", WINDOW_AUTOSIZE);
    imshow("grayImage", grayImage);

    namedWindow("colorImage", WINDOW_AUTOSIZE);
    imshow("colorImage", colorImage);

    timeConsume = ((double)getTickCount() - timeConsume) / getTickFrequency();
    cout << "程序耗时： " << timeConsume << endl;

    waitKey(0);

    return 0;
}