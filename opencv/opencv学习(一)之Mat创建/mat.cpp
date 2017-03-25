#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{

    Mat M1(3,2,CV_8UC3,Scalar(0, 0, 255));
    cout << "M1 = " << endl << " "  << M1 << endl;

    Mat M2(Size(3, 2), CV_8UC3, Scalar(1,2,3));
    cout << "M2 = " << endl << " " << M2 << endl;

    Mat M3(M2);
    cout << "M3 = " << endl << " " << M3 << endl;

    Mat M4(M2, Range(1,2), Range(1,2));
    cout << "M4 = " << endl << " " << M4 << endl;

    //也可以在C\C++中通过构造函数进行初始化
    int d[3] = {2,2,2};
    Mat M5(3,d,CV_8UC(1), Scalar::all(0));
    cout << "M5 = " << endl << " " << M5 << endl;

    waitKey(0);


    return 0;
}
