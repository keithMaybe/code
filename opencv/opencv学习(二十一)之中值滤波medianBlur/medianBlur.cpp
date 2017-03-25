#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_mSrcImage;
Mat g_mDstImage;
const int g_nMedianBlurMaxValue = 5;
int g_nMedianBlurValue;
int g_nkernelSize;

//定义回调函数
void on_medianBlurTrackBar(int, void*);

int main()
{
    g_mSrcImage = imread("lena.jpg");

    //判断文件是否加载成功
    if(g_mSrcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl;

    //判断图像是否是CV_8U图像
    if(0 <= g_mSrcImage.depth() <= 255)
        cout << "加载图像符合处理要求!" << endl;
    else
    {
        cout << "图像深度不是CV_8U，程序即将退出..." << endl;
        return -1;
    }

    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", g_mSrcImage);

    //输出图像窗口属性及轨迹条名称
    namedWindow("中值滤波图像", WINDOW_AUTOSIZE);
    char medianBlurName[20];
    sprintf(medianBlurName, "核函数尺寸 %d", g_nMedianBlurMaxValue);
    g_nMedianBlurValue = 1;

    //创建轨迹条
    createTrackbar(medianBlurName, "中值滤波图像", &g_nMedianBlurValue,
                    g_nMedianBlurMaxValue, on_medianBlurTrackBar);
    on_medianBlurTrackBar(g_nMedianBlurValue, 0);

    waitKey(0);


    return 0;
}

void on_medianBlurTrackBar(int, void*)
{
    //重新计算尺寸值，尺寸值应为大于1的奇数
    g_nkernelSize = g_nMedianBlurValue * 2 + 1;
    medianBlur(g_mSrcImage, g_mDstImage, g_nkernelSize);

    imshow("中值滤波图像", g_mDstImage);
}