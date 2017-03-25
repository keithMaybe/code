#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage, histImage;
   
    srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    //显示原图像
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", srcImage);

    //定义变量
    int dims = 1;       //定义直方图维度
    float range[] = {0, 255};
    const float* histRange = {range};
    int binNum = 256;
    bool uniform_hist = true;
    bool accumulate_hist = false;
    int channels = 0;

    //计算直方图
    calcHist(&srcImage, 1, &channels, Mat(), histImage, dims, &binNum, &histRange, uniform_hist, accumulate_hist);

    //获取最大值
    double maxValue = 0.0;
    minMaxLoc(histImage, 0, &maxValue, 0, 0);

    // //计算直方图的值
    // int value = cvRound()

    //计算每个bin的宽度
    Mat dstImage(srcImage.cols, srcImage.rows, CV_8U, Scalar(0));
    int bin_width = cvRound((double)srcImage.cols / binNum);

    //将直方图归一化到范围[0, srcImage.rows]
    //normalize(histImage, histImage, 0, srcImage.rows, NORM_MINMAX, -1, Mat());

    //循环绘制直方图
    for(int i = 0; i < binNum; i++)
    {
        int value = cvRound((histImage.at<float>.(i))*srcImage.rows/maxValue);
        rectangle(dstImage, Point(bin_width*i, srcImage.rows),
                Point(bin_width*(i+1), srcImage.rows - value), Scalar(255));
        // line(dstImage, Point(bin_width*(i-1), srcImage.rows - cvRound(histImage.at<float>(i-1))),
        //     Point(bin_width*(i), srcImage.rows - cvRound(histImage.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
    }
    namedWindow("直方图", WINDOW_AUTOSIZE);
    imshow("直方图", dstImage);

    waitKey(0);

    return 0;
}