#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{

    Mat M1=(Mat_<double>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
    cout << "M1 = " << endl << " " << M1 << endl << endl;

    Mat M2 = M1;
    cout << "M2 = " << endl << " " << M2 << endl << endl;

    Mat RowClone = M1.row(0).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;

    Mat ColClone = M1.col(1).clone();
    cout << "ColClone = " << endl << " " << ColClone << endl << endl;

    Mat copyToM;
    M1.row(1).copyTo(copyToM);
    cout << "copyToM = " << endl << " " << copyToM << endl << endl;

    //验证数据的共享方式

    RowClone.setTo(1);
    cout << "M1(更改RowClone的值) = "<< endl  << " " << M1 << endl << endl;

    ColClone.setTo(2);
    cout << "M1(更改ColClone的值) = "<< endl << " " << M1 << endl << endl;

    M2.setTo(1);
    cout << "M1(更改M2值) = " << endl << " " << M1 << endl << endl;

    waitKey(0);

    return 0;
}
