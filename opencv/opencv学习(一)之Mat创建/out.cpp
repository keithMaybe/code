#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    //使用函数randu()生成随机数,随机数范围为0-255
    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));

    //以默认格式输出
    cout << "R(Default) = " << endl << " " << R << endl << endl;

    //以Python格式输出
    cout << "R(Python) = " << endl << format(R, "python") << endl << endl;

    //以CSV格式输出
    cout << "R(CSV) = " << endl << format(R, "csv") << endl << endl;

    //以Numpy格式输出
    cout << "R(Numpy) = " << endl << format(R, "numpy") << endl << endl;

    //以C语言的格式输出
    cout << "R(C) = " << endl << format(R, "C") << endl << endl;

    Point2f P2f(5,1);
    cout << "Point (2D) = " << P2f << endl << endl;

    Point3f P3f(2,6,7);
    cout << "Point (3D) = " << P3f << endl << endl;

    waitKey(0);


    return 0;
}
