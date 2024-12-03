#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	vector<Mat> coin_images(6);
	coin_images[0] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins0.jpg", 0);
	coin_images[1] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins1.jpg", 0);
	coin_images[2] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins2.jpg", 0);
	coin_images[3] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins3.jpg", 0);
	coin_images[4] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins4.jpg", 0);
	coin_images[5] = imread("C:/Users/jisuu/OneDrive/바탕 화면/coins5.jpg", 0);

	Mat find_edge;

	vector<Vec3f> Circle;

	vector<int> answer = { 10, 13, 9, 15, 16, 8 };

	int count = 0;

	for (int i=count; i<coin_images.size(); i++) {

		GaussianBlur(coin_images[i], coin_images[i], Size(), 5, 5);
		HoughCircles(coin_images[i], Circle, HOUGH_GRADIENT, 1, 80, 35, 30, 0, 0);

		cout << "number of coins" << i << ".jpg=" << Circle.size() << ", answer of coins" << i << ".jpg=" << answer[i] << endl;

		for (int j=0; j<Circle.size(); j++) {

			Vec<int, 3> info = Circle[j];

			Point center(info[0], info[1]);
			int radius = info[2];

			circle(coin_images[i], center, radius, Scalar::all(0), 8);
			circle(coin_images[i], center, 2, Scalar::all(0), 8);

		}
	}

	for (const auto& n: coin_images) {
		imshow("result" + to_string(count), n);
		count++;
	}

	waitKey();
	return 0;

}