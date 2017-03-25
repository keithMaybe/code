#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("//home//keith//图片//星空.jpg", IMREAD_COLOR);       //读取图像到srcImage，注意图像路径即后缀
    namedWindow("Opencv图像读取-星空", WINDOW_AUTOSIZE);	//创建一个名字为“Opencv图像读取-星空”的窗口，窗口属性为自适应
    imshow("Opencv图像读取-星空", srcImage);			//显示读入的图像，窗口名称与namedWindow中名字要一致


    Mat srcImageGray;						//创建一个Mat类型用于存储将读取到的彩色图像转换为灰度图之后的图像
    cvtColor(srcImage, srcImageGray, CV_RGB2GRAY);		//使用函数CV_RGB2GRAY将彩色图像转换为灰度图
    namedWindow("星空灰度图", WINDOW_NORMAL);
    imshow("星空灰度图",srcImageGray);
    imwrite("星空灰度图.jpg",srcImageGray);			//将转换的灰度图以.bmp格式存储，默认路径为工程目录下


    waitKey(0);


    return 0;
}
