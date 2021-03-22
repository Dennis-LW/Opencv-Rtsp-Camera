
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
	cout << "  請輸入rtsp格式                                  " << endl;
	cout << "  rtsp://account:password@ddns or ip address:port " << endl;
	cout << "  攝影機開啟後                                    " << endl;
	cout << "  按下ESC即可關閉影像                             " << endl;
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

	cout << "正在連結攝影機... " << endl;


	if (!capture.isOpened()) {
		cout << "攝影機連線已中斷" << endl;
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
	cout << "已中斷攝影機連線" << endl;
	capture.release();
	destroyAllWindows();
	system("pause");
	return 0;
}