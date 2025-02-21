#include <iostream>
#include <thread>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "screen.h"
using namespace std;

// App resolution
#define WIDTH 640
#define HEIGHT 480

// Bitwise & with opencv::waitKey() to get keycode.
#define KEY_BITMASK 0xFF

// Keycode for ESC.
#define KEY_ESC 27




// ##################################################################### //
// ####################### FUNCTION DECLARATIONS ####################### //
// ##################################################################### //

void WaitForESC();








// ##################################################################### //
// ################################ MAIN ############################### //
// ##################################################################### //

int main(int argc, char** argv) {
    // Startup message
    cout << endl << endl;
    cout << "    ~ Program is running in external GUI window." << endl;
    cout << "    ~ Please switch to the GUI window!" << endl;
    cout << "    ~ All keyboard inputs are handled there." << endl;
    cout << "    ~ Press ESC to close the program." << endl;
    cout << "          (the GUI window must be focused)" << endl;
    cout << endl << endl;

    // Init GUI window
    Screen* screen = new Screen(WIDTH, HEIGHT);

    // Get user input and draw shapes based on input
    int inputWordCount = argc - 1;
    char** inputWordsPtr = argv + 1;

    for (int i = 0; i < inputWordCount; i++) {
        char* inputWord = *inputWordsPtr;
        screen->AddShape(inputWord);
        if (i < (inputWordCount - 1)) inputWordsPtr++;
        delete[] inputWord;
    }

    // When ESC is pressed, end program and deallocate memory.
    WaitForESC();
    delete screen;
    delete[] inputWordsPtr;
}








// ##################################################################### //
// ########################## HELPER FUNCTIONS ######################### //
// ##################################################################### //

/**
 * Pause execution until the ESC key is pressed.
 */
inline void WaitForESC() {
    while (true) {
        int keyPress = waitKey() & KEY_BITMASK;
        if (keyPress == KEY_ESC) break;
    }
}
