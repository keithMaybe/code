#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    RNG rng;
    Mat image = Mat::zeros(400, 400, CV_8UC3);

    Point pt1, pt2;
    
    for(int i = 0; i < 10; i++)
    {
        pt1.x = rng.uniform(0,400);
        pt1.y = rng.uniform(0,400);
        pt2.x = rng.uniform(0,400);
        pt2.y = rng.uniform(0,400);

        line(image, pt1, pt2, Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),rng.uniform(1,5),8);
        waitKey(500);
        imshow("随机图形",image);
        rectangle(image,pt1,pt2,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),rng.uniform(1,5),8);
        waitKey(500);
        imshow("随机图形",image);
        circle(image,pt1,(pt1.x < pt1.y)?pt1.x:pt1.y,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),1,8);
        waitKey(500);
        imshow("随机图形",image);
        ellipse(image,pt2,Size(pt2.x/5, pt2.y/5),0,0,360,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),rng.uniform(1,5),8);
        waitKey(500);
        imshow("随机图形",image);
    }

    waitKey(0);

    

    return 0;
}