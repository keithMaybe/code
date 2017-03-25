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
    for(int i = 0; i < grayImage.rows; ++i)
    {
        uchar* p = grayImage.ptr<uchar>(i);     //获取第i行第一个像素的指针
        for(int j = 0; j < grayImage.cols; ++j)
            p[j] = (i + j) % 255;               //对每个i行的所有像素进行赋值操作
    }

    //遍历所有像素并设置像素值
    
    for(int i = 0; i < colorImage.rows; ++i)
    {
        Vec3b* p = colorImage.ptr<Vec3b>(i);
        for(int j = 0; j < colorImage.cols; ++j)
        {
            p[j][0] = i % 255;      //Blue
            p[j][1] = j % 255;      //Gree
            p[j][2] = 0;            //Red
        }
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