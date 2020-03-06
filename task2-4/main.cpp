#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	int histgram1[256] = { 0 };
	float  histgram[256] = { 0 };
	cv::Mat srcMat = imread("1.png",0);
	int height = srcMat.rows;
	int width = srcMat.cols;
	int sum = height * width;
	for (int i = 0; i < 256; i++) {
		histgram1[i] = i;
	}
	for (int j = 0; j < height; j++) {
		//单行处理结束
		for (int i = 0; i < width; i++) {
			//------开始处理每个像素------------
			int a = srcMat.at<uchar>(j, i);
			histgram[a] = histgram[a] + 1;
			//-----结束每个像素的处理-----------
		}
	}
	for (int i = 0; i < 256; i++) {
		histgram[i] = histgram[i] / sum;
		cout << histgram[i] << endl;
	}
	waitKey(0);
	system("pause");
	return 0;
}