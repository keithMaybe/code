#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat srcImage, dstImage;
Mat map1_x, map2_y;
String windowName = "图像重映射";
int ind;        //重映射类型选择

void updateMap(void);

int main()
{
    //初始化参数
    ind = 0;
    srcImage = imread("dog.jpg");
    dstImage.create(srcImage.size(), srcImage.type());
    map1_x.create(srcImage.size(), CV_32FC1);
    map2_y.create(srcImage.size(), CV_32FC1);

    //创建窗口
    namedWindow(windowName, WINDOW_AUTOSIZE);

    while(true)
    {
        int c = waitKey(1000);      //延迟1000ms

        if((char)c == 27)
        {
            break;      //ESC退出
        }

        updateMap();        //调用函数，更新重映射模式
        remap(srcImage, dstImage, map1_x, map2_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

        imshow(windowName, dstImage);
    }

    return 0;
}

void updateMap(void)
{
    ind = ind%4;

    for(int j = 0; j < srcImage.rows; j++)
    {
        for(int i = 0; i < srcImage.cols; i++)
        {
            switch(ind)
            {
            //图像长宽缩小到原来的一半并居中显示
            case 0:
                if(i > srcImage.cols*0.25 && i < srcImage.cols*0.75 && j > srcImage.rows*0.25 && j < srcImage.rows*0.75)
                {
                    map1_x.at<float>(j, i) = 2*(i - srcImage.cols*0.25) + 0.5;
                    map2_y.at<float>(j, i) = 2*(j - srcImage.rows*0.25) + 0.5;
                }
                else
                {
                    map1_x.at<float>(j, i) = 0;
                    map2_y.at<float>(j, i) = 0;
                }
                break;
            
            //图像左右翻转
            case 1:
                map1_x.at<float>(j, i) = i;
                map2_y.at<float>(j, i) = srcImage.rows - j;
                break;

            //图像上下翻转
            case 2:
                map1_x.at<float>(j, i) = srcImage.cols - i;
                map2_y.at<float>(j, i) = j;
                break;
            
            //图像上下左右均翻转
            case 3:
                map1_x.at<float>(j, i) = srcImage.cols - i;
                map2_y.at<float>(j, i) = srcImage.rows - j;
                break;

            default:
                break;
            }
        }
    }

    ind++;
}