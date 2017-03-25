#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void colorReduceAt(Mat& srcImage, Mat& dstImageAt, int div);
void colorReduceIterator(Mat& srcImage, Mat& dstImageIterator, int div);
void colorReducePtr(Mat& srcImage, Mat& dstImagePtr, int div);

int main()
{
    //加载lena图像
    Mat srcImage = imread("lena.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    imshow("srcImage",srcImage);

    //声明处理后图像变量
    Mat dstImageAt, dstImageIterator, dstImagePtr;
    dstImageAt = srcImage.clone();
    dstImageIterator = srcImage.clone();
    dstImagePtr = srcImage.clone();

    int div = 4;

    //声明时间变量
    double timeAt, timeIterator, timePtr;
    
    timeAt = static_cast<double>(getTickCount());
    colorReduceAt(srcImage, dstImageAt, div);
    timeAt = ((double)getTickCount() - timeAt) / getTickFrequency();
    imshow("dstImageAt",dstImageAt);
    cout << "使用at()动态地址计算耗时：" << timeAt << endl << endl;

    timeIterator = static_cast<double>(getTickCount());
    colorReduceIterator(srcImage, dstImageIterator, div);
    timeIterator = ((double)getTickCount() - timeIterator) / getTickFrequency();
    imshow("dstImageIterator",dstImageIterator);
    cout << "使用iterator迭代器耗时：" << timeIterator << endl << endl;

    timePtr = static_cast<double>(getTickCount());
    colorReducePtr(srcImage, dstImagePtr, div);
    timePtr = ((double)getTickCount() - timePtr) / getTickFrequency();
    imshow("dstImagePtr",dstImagePtr);
    cout << "使用ptr指针耗时：" << timePtr << endl;


    waitKey(0);

    return 0;
}

//使用at动态地址计算方式
void colorReduceAt(Mat& srcImage, Mat& dstImageAt, int div)
{
    int rowNumber = dstImageAt.rows;      //获取图像行数
    int colNumber = dstImageAt.cols;      //获取图像列数

    //对每个像素进行处理
    for(int i = 0; i < rowNumber; i++)
    {
        for(int j = 0; j < colNumber; j++)
        {
            dstImageAt.at<Vec3b>(i,j)[0] = dstImageAt.at<Vec3b>(i,j)[0]/div*div;    //Blue
            dstImageAt.at<Vec3b>(i,j)[1] = dstImageAt.at<Vec3b>(i,j)[1]/div*div;    //Green
            dstImageAt.at<Vec3b>(i,j)[2] = dstImageAt.at<Vec3b>(i,j)[2]/div*div;    //Red
        }
    }

}

//使用iterator迭代器方式
void colorReduceIterator(Mat& srcImage, Mat& dstImageIterator, int div)
{
    MatIterator_<Vec3b> imageIt = dstImageIterator.begin<Vec3b>();      //获取迭代器初始位置
    MatIterator_<Vec3b> imageEnd = dstImageIterator.end<Vec3b>();       //获取迭代器结束位置

    //对每个像素进行处理
    for(;imageIt != imageEnd; imageIt++)
    {
        (*imageIt)[0] = (*imageIt)[0]/div*div;      //Blue
        (*imageIt)[1] = (*imageIt)[1]/div*div;      //Green
        (*imageIt)[2] = (*imageIt)[2]/div*div;      //Red
    }
}

//使用ptr指针
void colorReducePtr(Mat& srcImage, Mat& dstImagePtr, int div)
{
    int rowNumber = dstImagePtr.rows;                           //获取图像矩阵行数
    int colNumber = dstImagePtr.cols*dstImagePtr.channels();    //三通道图像每行元素个数为列数x通道数

    for(int i = 0; i < rowNumber; i++)
    {
        uchar* pixelPtr = dstImagePtr.ptr<uchar>(i);            //获取矩阵每行首地址指针
        for(int j = 0; j < colNumber; j++)
            pixelPtr[j] = pixelPtr[j] / div * div;
    }
}