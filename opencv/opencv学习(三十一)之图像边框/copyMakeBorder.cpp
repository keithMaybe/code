/*程序说明
 *当按下按键‘c’代表使用BORDER_CONSTANT
 *RNG生成的随机数作为像素值进行填充
 *当按下按键‘r’代表使用BORDER_REPLICATE
 *图像扩充的边框由原图像边缘像素的值进行填充
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

//声明全局变量
Mat srcImage, dstImage;
int g_top, g_bottom, g_left, g_right;
int borderType;
Scalar value;
String windowName = "copyMakeBorder Demo";
RNG rng(12345);

int main()
{
    int c;

    srcImage = imread("dog.jpg");

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像记载成功" << endl << endl;
    imshow("原图像", srcImage);
    
    //程序使用说明
    printf("\n \t copyMakeBorder Demo: \n");
    printf("\t --------------------\n");
    printf("**Press 'c' to set the border to a random constant value \n");
    printf("**Press 'r' to set the border to be replicated \n");
    printf("**Press 'ESC' to exit the program \n");

    //创建窗口
    namedWindow(windowName, WINDOW_AUTOSIZE);

    //初始化边框参数
    g_top = (int)(0.05*srcImage.rows);
    g_bottom = (int)(0.05*srcImage.rows);
    g_left = (int)(0.05*srcImage.cols);
    g_right = (int)(0.05*srcImage.cols);

    //显示初始图像
    dstImage = srcImage;    
    imshow(windowName, dstImage);

    while(true)
    {
        c = waitKey(500);

        if((char)c == 27)   //c为ESC程序退出
        {break;}
        else if((char)c == 'c')
        {borderType = BORDER_CONSTANT;}
        else if((char)c == 'r')
        {borderType = BORDER_REPLICATE;}

        value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        copyMakeBorder(srcImage, dstImage, g_top, g_bottom, g_left, g_right, borderType, value);

        imshow(windowName, dstImage);
    }

    return 0;
}
