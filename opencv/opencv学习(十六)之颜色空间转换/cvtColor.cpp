#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("星空.png");

    //判断图像是否加载成功
    if(!srcImage.data)
    {
        cout << "图像加载失败!" << endl;
        return false;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    //显示原图像
    namedWindow("原图像",WINDOW_AUTOSIZE);
    imshow("原图像",srcImage);

    //将图像转换为灰度图，采用CV_前缀
    Mat grayImage;
    cvtColor(srcImage, grayImage, CV_BGR2GRAY);     //将图像转换为灰度图
    namedWindow("灰度图",WINDOW_AUTOSIZE);
    imshow("灰度图",grayImage);

    //将图像转换为HSV，采用COLOR_前缀
    Mat HSVImage;
    cvtColor(srcImage, HSVImage, COLOR_BGR2HSV);    //将图像转换为HSV图
    namedWindow("HSV",WINDOW_AUTOSIZE);
    imshow("HSV",HSVImage);

    waitKey(0);

    return 0;
}