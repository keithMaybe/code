#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void addImage(Mat& image, Mat& logoImage, vector<Mat>channels, Mat imageChannel, String title);

int main()
{
	Mat srcImage = imread("七龙珠.jpg");
	Mat logoImage = imread("七龙珠logo.jpg", IMREAD_GRAYSCALE);

	//判断文件是否加载成功
	if (srcImage.empty() || logoImage.empty())
	{
		cout << "图像加载失败!" << endl;
		return false;
	}
	else
		cout << "图像加载成功!" << endl;

	//对加载的原图像进行通道分离
	vector<Mat>channels;
	split(srcImage, channels);
	Mat imageBlueChannel;
	imageBlueChannel = channels.at(0);				//提取蓝色通道

	String imageBlueTitle = "蓝色通道叠加logo融合";		//窗口名称，也可以用char数组，传入char*来指定窗口名称

	addImage(srcImage, logoImage, channels, imageBlueChannel, imageBlueTitle);
	
	return 0;
}

void addImage(Mat& image, Mat& logoImage, vector<Mat>channels, Mat imageChannel, String title)
{
	//在提取的蓝色通道上，指定ROI区域叠加logoImage
	addWeighted(imageChannel(Rect(50, 50, logoImage.cols, logoImage.rows)), 1.0, logoImage, 0.7,
		0.0, imageChannel(Rect(50, 50, logoImage.cols, logoImage.rows)));

	merge(channels, image);			//将叠加logo后的蓝色通道与另外两个颜色通道重新融合
	imshow(title, image);
	waitKey(0);
}