#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("七龙珠grayBackground.jpg");
    Mat addImage = imread("ll.jpg");

    //判断文件是否加载成功
    if(srcImage.data && addImage.data)
        cout << "图像加载成功!" << endl << endl;
    else
    {
        cout << "图像加载失败!" << endl << endl;
        return -1;
    }
    imshow("srcImage",srcImage);
    imshow("astronaut",addImage);

    //设置srcImage感兴趣区域
    //第一种方式，使用Rect()函数设置ROI
    Mat imageROI = srcImage(Rect(50,50,addImage.cols,addImage.rows));
    addWeighted(imageROI,0.7,addImage,0.3,0,imageROI);
    imshow("混合后图像",srcImage);

    waitKey(0);

    return 0;
}
