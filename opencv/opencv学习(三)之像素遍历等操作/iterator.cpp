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
    MatIterator_<uchar> grayit, grayend;
    for(grayit = grayImage.begin<uchar>(), grayend = grayImage.end<uchar>(); grayit != grayend; ++grayit)
        *grayit = rand() % 255;

    //遍历所有像素并设置像素值
    MatIterator_<Vec3b> colorit, colorend;
    for(colorit = colorImage.begin<Vec3b>(), colorend = colorImage.end<Vec3b>(); colorit != colorend; ++colorit)
    {
        (*colorit)[0] = rand() % 255;       //Blue
        (*colorit)[1] = rand() % 255;       //Green
        (*colorit)[2] = rand() % 255;       //Red
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