#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage, dstImage;
    srcImage = imread("filter2d.jpg");

    //判断图像是否加载成功
    if(!srcImage.data)
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    //初始化滤波器参数
    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;

    anchor = Point(-1, -1);
    delta = 0;
    ddepth = -1;

    int c;

    int ind = 0;
    while(true)
    {
        c = waitKey(500);

        //按下ESC退出程序
        if((char)c==27)
        {
            break;
        }

        kernel_size = 3+2*(ind%5);
        kernel = Mat::ones(kernel_size, kernel_size, CV_32F)/(float)(kernel_size*kernel_size);

        //应用滤波器
        filter2D(srcImage, dstImage, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
        cout << "当前滤波器尺寸为: " << kernel_size << endl;
        imshow("线性滤波器", dstImage);
        ind++;
    }

    return 0;
}