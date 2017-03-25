/*
 *程序首先对加载的图像执行向下采样操作形成高斯金字塔
 *之后再利用向下采样得到的图像进行向上采样形成拉普拉斯金字塔
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("pyramid.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", srcImage);

    //两次向下采样操作分别输出
    Mat pyrDownImage_1, pyrDownImage_2;

    pyrDown(srcImage, pyrDownImage_1);
    namedWindow("向下采样-1", WINDOW_AUTOSIZE);
    imshow("向下采样-1", pyrDownImage_1);

    pyrDown(pyrDownImage_1, pyrDownImage_2);
    namedWindow("向下采样-2", WINDOW_AUTOSIZE);
    imshow("向下采样-2", pyrDownImage_2);

    //利用向下采样的结果进行向上采样操作
    Mat pyrUpImage_1, pyrUpImage_2;

    pyrUp(pyrDownImage_2, pyrUpImage_1);
    namedWindow("向上采样-1", WINDOW_AUTOSIZE);
    imshow("向上采样-1", pyrUpImage_1);

    pyrUp(pyrUpImage_1, pyrUpImage_2);
    namedWindow("向上采样-2", WINDOW_AUTOSIZE);
    imshow("向上采样-2", pyrUpImage_2);

    waitKey(0);

    return 0;
}