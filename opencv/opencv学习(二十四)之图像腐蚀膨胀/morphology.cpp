#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//定义全局变量
Mat g_srcImage;
Mat g_dilateImage;
Mat g_erodeImage;

//定义两个轨迹条属性
const int typeMaxValue = 2;         //膨胀腐蚀采用图形的类型
const int kernelSizeMaxVale = 21;   //采用kernel的尺寸最大值

int dilateTypeValue = 0;            //默认膨胀操作模板图像类型
int dilateSizeValue = 5;            //默认模板图像尺寸
int erodeTypeValue = 0;
int erodeSizeValue = 5;

//定义两个回调函数
void dilateFun(int, void*);         //膨胀回调函数
void erodeFun(int, void*);          //腐蚀回调函数

int main()
{
    g_srcImage = imread("cat.jpg");

    //判断图像是否打开成功
    if(g_srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;
    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像",g_srcImage);

    //定义膨胀操作窗口属性及轨迹条性质
    namedWindow("图像膨胀", WINDOW_AUTOSIZE);
    namedWindow("图像腐蚀", WINDOW_AUTOSIZE);

    char typeName[20];
    sprintf(typeName, "模板类型 %d", typeMaxValue);

    char sizeName[20];
    sprintf(sizeName, "模板尺寸 %d", kernelSizeMaxVale);

    //创建膨胀轨迹条
    createTrackbar(typeName, "图像膨胀", &dilateTypeValue, typeMaxValue, dilateFun);
    createTrackbar(sizeName, "图像膨胀", &dilateSizeValue, kernelSizeMaxVale, dilateFun);
    dilateFun(dilateTypeValue, 0);
    dilateFun(dilateSizeValue, 0);

    //创建腐蚀轨迹条
    createTrackbar(typeName, "图像腐蚀", &erodeTypeValue, typeMaxValue, erodeFun);
    createTrackbar(sizeName, "图像腐蚀", &erodeSizeValue, kernelSizeMaxVale, erodeFun);
    erodeFun(erodeTypeValue, 0);
    erodeFun(erodeSizeValue, 0);

    waitKey(0);

    return 0;
}

//膨胀回调函数
void dilateFun(int, void*)
{
    //确定模板图像类型
    int dilate_type;
    if(dilateTypeValue == 0)
        dilate_type = MORPH_RECT;
    else if (dilateTypeValue == 1)
        dilate_type = MORPH_CROSS;
    else
        dilate_type = MORPH_ELLIPSE;
    
    Mat element = getStructuringElement(dilate_type, Size(2*dilateSizeValue + 1, 2*dilateSizeValue + 1));
    dilate(g_srcImage, g_dilateImage, element);     //膨胀操作
    imshow("图像膨胀", g_dilateImage);

}

//腐蚀回调函数
void erodeFun(int, void*)
{
    //确定模板图像类型
    int erode_type;
    if(erodeTypeValue == 0)
        erode_type = MORPH_RECT;
    else if (erodeTypeValue == 1)
        erode_type = MORPH_CROSS;
    else
        erode_type = MORPH_ELLIPSE;
    
    Mat element = getStructuringElement(erode_type, Size(2*erodeSizeValue + 1, 2*erodeSizeValue + 1));
    erode(g_srcImage, g_erodeImage, element);     //腐蚀操作
    imshow("图像腐蚀", g_erodeImage);
}