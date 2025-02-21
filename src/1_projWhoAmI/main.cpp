#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

// ##################################################################### //
// ####################### FUNCTION DECLARATIONS ####################### //
// ##################################################################### //

// Helper functions
string strToLower (string str);

// OpenCV rendering functions
Mat getImage(const String& ImgPath);
void addTitle(const String& Text, const Mat& Img);
void addDesc1(int lineCount, string* lines, const Mat& Img);
void addDesc2(int lineCount, string* lines, const Mat& Img);
void addCaption1(int lineCount, string* lines, const Mat& Img);
void addCaption2(int lineCount, string* lines, const Mat& Img);

// ##################################################################### //
// ################################ MAIN ############################### //
// ##################################################################### //

int main() {

    string WinName1;
    string WinName2;
    string WinName3;

    string descLine1;
    string descLine2;
    string descLine3;
    string descEnd = "Press any key on pic window to go to next pic.";
    string* descLines;
    string desc;

    Mat img1;
    Mat img2;
    Mat img3;

    // Loop until user asks to quit
    bool isQuit = false;
    while (!isQuit) {

        // Introduce program
        cout << endl;
        cout << endl;
        cout << " ==== ABOUT CHRIS AYSON ====" << endl;
        cout << endl;
        cout << "Hello! In this program, you will learn all about me." << endl;
        cout << "Type \"instrument\" to learn about my favorite instrument." << endl;
        cout << "Type \"videogame\" to learn about my favorite video game." << endl;
        cout << "Type \"food\" to learn about my favorite food." << endl;
        cout << "Type \"quit\" to quit the program." << endl;

        // Get and validate user input
        string input;
        cout << endl;
        cout << " >> ";
        cin >> input;
        cout << endl;
        cout << endl;

        while (true) {
            string lowerInput = strToLower(input);

            // Valid input.
            if (
                lowerInput == "instrument"
                || lowerInput == "videogame"
                || lowerInput == "food"
                || lowerInput == "quit"
            ) {
                cout << endl;
                cout << endl;
                break;
            } else {

                // Invalid input. Prompt again.
                cout << "Invalid input." << endl;
                cout << "Type \"instrument\" to learn about my favorite instrument." << endl;
                cout << "Type \"videogame\" to learn about my favorite video game." << endl;
                cout << "Type \"food\" to learn about my favorite food." << endl;
                cout << "Type \"quit\" to quit the program." << endl;

                cout << endl;
                cout << " >> ";
                cin >> input;
                cout << endl;
                cout << endl;
            }
        }

        // Process input.
        string lowerInput = strToLower(input);

        if (lowerInput == "quit") {
            isQuit = true;
            break;
        }

        if (lowerInput == "instrument") {
            WinName1 = "Bass Clarinet";
            WinName2 = "Concert Band Seating Chart";
            WinName3 = "Concert Band";

            descLine1 = "My favorite instrument is the bass clarinet.";
            descLine2 = "It's a super big clarinet. It's as low as a tuba.";
            descLine3 = "I played it in middle school and high school.";
            descLines = new string[4] {descLine1, descLine2, descLine3, descEnd};

            cout << descLine1 << endl;
            cout << descLine2 << endl;
            cout << descLine3 << endl;
            cout << descEnd << endl;
            cout << endl;
            cout << endl;

            img1 = getImage("src/3_whoamiproject/img/bassclarinet.png");
            img2 = getImage("src/3_whoamiproject/img/seatingchart.jpg");
            img3 = getImage("src/3_whoamiproject/img/concertband.jpg");
            addTitle(WinName1, img1);
            addDesc1(4, descLines, img1);
            addCaption1(1, new string[1] {descEnd}, img2);
            addCaption2(1, new string[1] {"Press any key on pic window, then go back to your terminal."}, img3);

        } else if (lowerInput == "videogame") {
            WinName1 = "Against the Storm";
            WinName2 = "Against the Storm";
            WinName3 = "Programming";

            descLine1 = "My favorite video game is Against the Storm.";
            descLine2 = "It's a city builder game.";
            descLine3 = "As a programmer, I find it fun to optimize cities.";
            descLines = new string[4] {descLine1, descLine2, descLine3, descEnd};

            cout << descLine1 << endl;
            cout << descLine2 << endl;
            cout << descLine3 << endl;
            cout << descEnd << endl;
            cout << endl;
            cout << endl;

            img1 = getImage("src/3_whoamiproject/img/storm.jpg");
            img2 = getImage("src/3_whoamiproject/img/storm2.jpg");
            img3 = getImage("src/3_whoamiproject/img/cs.jpg");
            addTitle(WinName1, img1);
            addDesc2(4, descLines, img1);
            addCaption2(1, new string[1] {descEnd}, img2);
            addCaption2(1, new string[1] {"Press any key on pic window, then go back to your terminal."}, img3);

        } else { // lowerInput == food
            WinName1 = "Panda Express";
            WinName2 = "Panda Express";
            WinName3 = "Panda Express";

            descLine1 = "My favorite food is Panda Express.";
            descLine2 = "I really like their orange chicken.";
            descLine3 = "I can make a pretty good imitation at home.";
            descLines = new string[4] {descLine1, descLine2, descLine3, descEnd};

            cout << descLine1 << endl;
            cout << descLine2 << endl;
            cout << descLine3 << endl;
            cout << descEnd << endl;
            cout << endl;
            cout << endl;

            img1 = getImage("src/3_whoamiproject/img/panda1.jpg");
            img2 = getImage("src/3_whoamiproject/img/panda2.jpg");
            img3 = getImage("src/3_whoamiproject/img/panda3.jpg");
            addTitle(WinName1, img1);
            addDesc2(4, descLines, img1);
            addCaption1(1, new string[1] {descEnd}, img2);
            addCaption2(1, new string[1] {"Press any key on pic window, then go back to your terminal."}, img3);
        }

        namedWindow(WinName1);
        imshow(WinName1, img1);
        moveWindow(WinName3, 0, 0);
        setWindowProperty(WinName1, WND_PROP_TOPMOST, 1);
        waitKey(0);
        destroyWindow(WinName1);
        pollKey();

        namedWindow(WinName2);
        imshow(WinName2, img2);
        moveWindow(WinName3, 0, 0);
        setWindowProperty(WinName2, WND_PROP_TOPMOST, 1);
        waitKey(0);
        destroyWindow(WinName2);
        pollKey();

        namedWindow(WinName3);
        imshow(WinName3, img3);
        moveWindow(WinName3, 0, 0);
        setWindowProperty(WinName3, WND_PROP_TOPMOST, 1);
        waitKey(0);
        destroyWindow(WinName3);
        pollKey();
    }

    // Quit program
    cout << "Thank you for using my program! Goodbye!" << endl;
    cout << endl;
    cout << endl;
}

// ##################################################################### //
// ########################## HELPER FUNCTIONS ######################### //
// ##################################################################### //

string strToLower(string str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
    [](unsigned char c) { return std::tolower(c); });
    return result;
}

// ##################################################################### //
// ##################### OPENCV RENDERING FUNCTIONS #################### //
// ##################################################################### //

Mat getImage(const String& ImgPath) {
    Mat image = imread(ImgPath, IMREAD_COLOR);
    if (!image.data)
        cout << "Could not open or find the image " << ImgPath << "." << endl;
    return image;
}

void addTitle(const String& Text, const Mat& Img) {
    Point textPos = Point(200, 200);
    HersheyFonts textFont = FONT_HERSHEY_SCRIPT_COMPLEX;
    double textScale = 4;
    Scalar textColor = {0, 255, 255};
    int textThickness = 8;

    putText(Img, Text, textPos, textFont, textScale, textColor, textThickness);
}

void addDesc1(int lineCount, string* lines, const Mat& Img) {
    int y = 400;
    HersheyFonts textFont = FONT_HERSHEY_PLAIN;
    double textScale = 2;
    Scalar textColor = {0, 255, 255};
    int textThickness = 4;

    for (int i = 0; i < lineCount; i++) {
        Point textPos = Point(600, y);
        putText(Img, lines[i], textPos, textFont, textScale, textColor, textThickness);
        y += 50;
    }
}

void addDesc2(int lineCount, string* lines, const Mat& Img) {
    int y = 400;
    HersheyFonts textFont = FONT_HERSHEY_PLAIN;
    double textScale = 2;
    Scalar textColor = {255, 255, 0};
    int textThickness = 4;

    for (int i = 0; i < lineCount; i++) {
        Point textPos = Point(1000, y);
        putText(Img, lines[i], textPos, textFont, textScale, textColor, textThickness);
        y += 50;
    }
}

void addCaption1(int lineCount, string* lines, const Mat& Img) {
    int y = 20;
    HersheyFonts textFont = FONT_HERSHEY_PLAIN;
    double textScale = 1.5;
    Scalar textColor = {0, 0, 0};
    int textThickness = 3;

    for (int i = 0; i < lineCount; i++) {
        Point textPos = Point(20, y);
        putText(Img, lines[i], textPos, textFont, textScale, textColor, textThickness);
        y += 50;
    }
}

void addCaption2(int lineCount, string* lines, const Mat& Img) {
    int y = 20;
    HersheyFonts textFont = FONT_HERSHEY_PLAIN;
    double textScale = 1.5;
    Scalar textColor = {255, 255, 255};
    int textThickness = 3;

    for (int i = 0; i < lineCount; i++) {
        Point textPos = Point(20, y);
        putText(Img, lines[i], textPos, textFont, textScale, textColor, textThickness);
        y += 50;
    }
}
