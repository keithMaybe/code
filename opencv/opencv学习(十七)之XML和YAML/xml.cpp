#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class MyData
{
public:
	MyData():A(0),X(0),id(){}
	explicit MyData(int):A(97),X(CV_PI), id("mydata1234"){}	//explicit to avoid implicit conversion
	void write(FileStorage& fs) const
	{

		fs << "{ " << "A" << A << "X" << X << "id" << id << "}";
	}
	void read(const FileNode& node)
	{
		A = (int)node["A"];
		X = (double)node["X"];
		id = (string)node["id"];
	}
public:
	//data members
	int A;
	double X;
	string id;
};

//These write and read functions must be defined for the serialization in FileStorage to work
static void write(FileStorage&fs, const string&, const MyData& x)
{

	x.write(fs);
}

static void read(const FileNode& node, MyData& x, const MyData& default_value = MyData())
{

	if(node.empty())
		x = default_value;
	else
		x.read(node);
}

//This function will print our custom class to the console
static ostream& operator<<(ostream& out, const MyData& m)
{
	out << "{ id = " << m.id << ", ";
	out << "X = " << m.X << ", ";
	out << "A = " << m.A << "}";
	return out;
}

int main(int ac, char** av)
{
	if(ac != 2)
	{
		//help(av);
		return 1;
	}

	string filename = av[1];
	{
		//write
		Mat R = Mat_<uchar>::eye(3, 3), T = Mat_<double>::zeros(3,1);
		MyData m(1);

		FileStorage fs(filename, FileStorage::WRITE);

		fs << "iterationNr"<<100;
		fs << "strings" << "[";
		fs << "image1.jpg" << "Awesomeness" << "baboon.jpg";
		fs << "]";

		fs << "Mapping";
		fs << "{" << "One" << 1;
		fs <<        "Two" << 2 << "}";

		fs << "R" << R;
		fs << "T" << T;

		fs << "MyData" << m;

		fs.release();
		cout << "Write Done." << endl;
	}

	{//read
		cout << endl << "Reading: " << endl;
		FileStorage fs;
		fs.open(filename, FileStorage::READ);

		int itNr;
		//fs["iterationNr"] >> itNr;
		itNr = (int)fs["iterationNr"];
		cout << itNr;
		if(!fs.isOpened())
		{
			cerr << "Failed to open " << filename << endl;
			return 1;
		}

		FileNode n = fs["strings"];
		if(n.type() != FileNode::SEQ)
		{
			cerr << "string is not a sequence! FAIL" << endl;
			return 1;
		}

		FileNodeIterator it = n.begin(), it_end = n.end();
		for (; it != it_end; ++it)
		{
			cout << (string)*it << endl;
		}
		n = fs["Mapping"];
		cout << "Two " << (int)(n["Two"]) << "; ";
		cout << "One " << (int)(n["One"]) << endl << endl;

		MyData m;
		Mat R, T;

		fs["R"] >> R;
		fs["T"] >> T;
		fs["MyData"] >> m;

		cout << endl << "R = " << R << endl;
		cout << "T = " << T << endl << endl;
		cout << "MyData = " << endl << m << endl << endl;

		//Show default behavior for non existing nodes
		cout << "Attempt to read NonExisting(should initialize the data structure with its defaule).";
		fs["NonExisting"] >> m;
		cout << endl << "NonExisting = " << endl << m << endl;
	}
	cout << endl << "Tip: Open up" << filename << "with a text editor to see the serialized data." << endl;
	return 0;
}