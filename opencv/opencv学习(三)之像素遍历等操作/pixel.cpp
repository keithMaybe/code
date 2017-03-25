#include <iostream>
#include <cstring>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat& ScanImageAndReduce(Mat& I,const uchar* const table);

int main(int argc, char** argv)
{
    int divideWith = 0;
    
    Mat srcImage = imread("lena.jpg");

    //image is load sucessful?
    if(srcImage.data)
        cout << "Success" << endl;
    else
        return -1;

    imshow("srcImage",srcImage);

    cout << "input divideWith: ";
    cin >> divideWith;

    if(!divideWith)
    {
        cout << "输入的划分间隔无效." << endl;
        return -1;
    }
    uchar table[256];
    for(int i = 0;i < 256; ++i)
        table[i] = (uchar)(divideWith * (i * divideWith));

    ScanImageAndReduce(srcImage,table);
    waitKey(0);

    return 0;
}

Mat& ScanImageAndReduce(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);

    //定义变量与原图像保持一致
    int channels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * channels;

    //判断矩阵是否是连续矩阵
    if(I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    for(i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);        //获取矩阵第i行的首地址
        for(j = 0; j < nCols; ++j)  //列循环进行处理
        {
            p[j] = table[p[j]];
        }
    }
    imshow("reduce-100",I);         //根据输入值对窗口名字进行更改

    return I;
}