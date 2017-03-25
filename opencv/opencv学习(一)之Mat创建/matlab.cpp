#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat M1 = Mat::zeros(2,3,CV_8UC1);
    cout << "M1 = " << endl << " " << M1 << endl << endl;

    Mat M2 = Mat::ones(2,3,CV_32F);
    cout << "M2 = " << endl << " " << M2 << endl << endl;

    Mat M3 = Mat::eye(4,4,CV_64F);
    cout << "M3 = " << endl << " " << M3 << endl << endl;

    waitKey(0);

    return 0;
}
