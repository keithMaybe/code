#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("space.jpg");
    Mat addImage = imread("astronautB.jpg");
    Mat maskImage = imread("astronautB.jpg",IMREAD_GRAYSCALE);  //加载其灰度图

    //判断文件是否加载成功
    if(srcImage.data && addImage.data)
        cout << "图像加载成功!" << endl << endl;
    else
    {
        cout << "图像加载失败!" << endl << endl;
        return -1;
    }

    //以第二种方式Range()函数设置其ROI区域
    Mat imageROI = srcImage(Range(50,maskImage.rows), Range(50,maskImage.cols));
    addImage.copyTo(imageROI,maskImage);
    imshow("混合后图像");

    waitKey(0);

    return 0;
}