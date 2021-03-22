
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;




int main()
{

	string camera ;
	char c[100];
	cout << "---------------------------------------------------" << endl;
	cout << "  �п�Jrtsp�榡                                  " << endl;
	cout << "  rtsp://account:password@ddns or ip address:port " << endl;
	cout << "  ��v���}�ҫ�                                    " << endl;
	cout << "  ���UESC�Y�i�����v��                             " << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Input: ";
	cin >> c;
	camera = (string)c;
	Mat image;
	Mat src;
	VideoCapture capture;
	capture.open(camera);
	capture >> src;
	bool isColor = (src.type() == CV_8UC3);

	cout << "���b�s����v��... " << endl;


	if (!capture.isOpened()) {
		cout << "��v���s�u�w���_" << endl;
		capture.release();
		destroyAllWindows();
		system("pause");
		return -1;
	}

	for (;;)
	{
		capture >> image;

		imshow("Sample", image);
		char c = (char)waitKey(1);
		if (c == 27) break;
	}
	cout << "�w���_��v���s�u" << endl;
	capture.release();
	destroyAllWindows();
	system("pause");
	return 0;
}