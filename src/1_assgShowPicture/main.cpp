#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void showImage(const string &);

int main() {
    showImage("/Users/_/zasdf182/_gh/csd-233-cpp/src/showapicture/harold.png");
}

void showImage(const String &JpgName) {
    Mat image = imread(JpgName, IMREAD_COLOR);
    if (!image.data) { // Check for invalid input
        cout << "Could not open or find the image " << JpgName;
        return;
    }

    namedWindow("PicWindow", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("PicWindow", image); // Show our image inside it.
    waitKey(0);
    destroyWindow("PicWindow");
}
