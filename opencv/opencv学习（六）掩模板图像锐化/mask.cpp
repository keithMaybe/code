#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void Sharpen(const Mat& myImage, Mat& Result);

int main()
{
    Mat srcImage = imread("lena.jpg");
    
    //判断图像是否加载成功
    if(srcImage.data)
        cout << "图像加载成功!" << endl << endl;
    else
    {
        cout << "图像加载失败!" << endl << endl;
        return -1;
    }
    namedWindow("srcImage", WINDOW_AUTOSIZE);
    imshow("srcImage", srcImage);

    Mat dstImage;
    dstImage.create(srcImage.size(), srcImage.type());
    Sharpen(srcImage, dstImage);
    namedWindow("dstImage",WINDOW_AUTOSIZE);
    imshow("dstImage",dstImage);

    waitKey(0);

    return 0;
}

void Sharpen(const Mat& myImage, Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);        //判断函数CV_Assert
    const int nChannels = myImage.channels();

    for(int j = 1; j < myImage.rows - 1; ++j)
    {
        const uchar* precious = myImage.ptr<uchar>(j - 1);      //当前像素上一行指针
        const uchar* current = myImage.ptr<uchar>(j);           //当前像素行指针
        const uchar* next = myImage.ptr<uchar>(j + 1);          //当前像素下一行指针

        uchar* output = Result.ptr<uchar>(j);

        //利用公式和上下左右四个像素对当前像素值进行处理
        for(int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
        {
            *output++ = saturate_cast<uchar>(5 * current[i]
            -current[i-nChannels]-current[i+nChannels]-precious[i]-next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0));                 //设置第一行所有元素值为0
    Result.row(Result.rows-1).setTo(Scalar(0));     //设置最后一行所有元素值为0
    Result.col(0).setTo(Scalar(0));                 //设置第一列所有元素值为0
    Result.col(Result.cols-1).setTo(Scalar(0));     //设置最后一列所有元素值为0
}