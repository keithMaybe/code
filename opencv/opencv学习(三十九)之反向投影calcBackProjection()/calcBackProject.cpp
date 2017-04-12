#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat srcImage, hsvImage,hueImage;
const int hueBinMaxValue = 180;
int hueBinValue=25;

//声明回调函数
void Hist_and_Backprojection(int, void*);

int main()
{
    srcImage=imread("Back_Projection_Theory2.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败" << endl;
        return -1;
    }
    else
        cout << "图像加载成功..." << endl << endl;

    //将图像转化为HSV图像
    cvtColor(srcImage, hsvImage, CV_BGR2HSV);

    //只使用图像的H参数
    hueImage.create(hsvImage.size(), hsvImage.depth());
    int ch[]={0,0};
    mixChannels(&hsvImage, 1, &hueImage, 1, ch, 1);

    //轨迹条参数设置
    char trackBarName[20];
    sprintf(trackBarName,"Hue bin:%d",hueBinMaxValue);
    namedWindow("SourceImage",WINDOW_AUTOSIZE);

    //创建轨迹条并调用回调函数
    createTrackbar(trackBarName, "SourceImage", &hueBinValue, hueBinMaxValue, Hist_and_Backprojection);
    Hist_and_Backprojection(hueBinValue, 0);

    imshow("SourceImage", srcImage);

    waitKey(0);
    
    return 0;
}

void Hist_and_Backprojection(int, void*)
{
    MatND hist;
    int histsize=MAX(hueBinValue, 2);
    float hue_range[]={0,180};
    const float* ranges={hue_range};

    //计算图像直方图并归一化处理
    calcHist(&hueImage, 1, 0, Mat(), hist, 1, &histsize, &ranges, true, false);
    normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());

    //获取反向投影
    MatND backProjection;
    calcBackProject(&hueImage, 1, 0, hist, backProjection, &ranges, 1, true);

    //输出反向投影
    imshow("BackProjection", backProjection);

    //绘制图像直方图
    int w=400;
    int h=400;
    int bin_w = cvRound((double)w/histsize);
    Mat histImage = Mat::zeros(w, h, CV_8UC3);
    for(int i=0; i < hueBinValue; i++)
    {
        rectangle(histImage, Point(i*bin_w, h), Point((i+1)*bin_w, h-cvRound(hist.at<float>(i)*h/255.0)), Scalar(0,0,255), -1);
    }
    imshow("HistImage", histImage);
}