#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat M1;
    M1.create(4,4,CV_8UC(2));
    cout << "M1 = " << endl << " " << M1 << endl << endl;

    waitKey(0);

    return 0;
}
