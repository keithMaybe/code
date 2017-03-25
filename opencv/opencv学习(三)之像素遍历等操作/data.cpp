#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main()
{
    //2D Point
    Point2f P(5, 1);
    cout << endl << "Point (2D) = " << P << endl << endl;

    //3D Point
    Point3f P3f(2, 5, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    //std::vector via cv::Mat
    vector<float> v;
    v.push_back((float)CV_PI);      //将pi的值以float类型存入v,push_back是C++中容器的一种操作方式
    v.push_back(2);
    v.push_back(3.01f);
    cout << "vector of floats via Mat = " << endl << Mat(v) << endl << endl;

    //std::vector of points
    vector<Point2f> vPoints(20);
    for(size_t i = 0; i < vPoints.size(); ++i)
    vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    cout << "vector of 2D points = " << endl << vPoints << endl << endl;


    return 0;
}