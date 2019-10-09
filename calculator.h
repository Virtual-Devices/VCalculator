#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

class calculator
{
private:
	const int baseWidth = 260;
	const int baseHeight = 480;
	int width;
	int height;
	double scale;
	int x;
	int y;
	string keys[5][5];
	bool showed;
public:
	calculator(double, int, int);
	~calculator();
	void show(Mat&);
	void click(int, int);
};
