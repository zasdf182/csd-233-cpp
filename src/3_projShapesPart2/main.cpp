#include "screen.cpp"
using namespace std;

// App resolution
#define WIDTH 640
#define HEIGHT 480

// Bitwise & with opencv::waitKey() to get keycode.
#define KEY_BITMASK 0xFF

// Keycode for ESC.
#define KEY_ESC 27




// ##################################################################### //
// ########################## HELPER FUNCTIONS ######################### //
// ##################################################################### //

/**
 * Returns a new lowercase char array.
 * Does not mutate original char array.
 * NOTE: Remember to delete the new char array later.
 */
inline char* ToLower(char* charArray) {
    int charCount = strlen(charArray);
    char* buffer = new char[charCount + 1];
    char* cursor1 = buffer;
    char* cursor2 = charArray;
    for (int i = 0; i < charCount; i++) {
        *cursor1 = tolower(*cursor2);
        cursor1++;
        cursor2++;
    }
    *cursor1 = '\0';
    return buffer;
}





// ##################################################################### //
// ################################ MAIN ############################### //
// ##################################################################### //

int main(int argc, char** argv) {
    // Startup message
    cout << endl << endl;
    cout << "    ~ Program is running in external GUI window." << endl;
    cout << "    ~ A new shape should appear every 4 seconds." << endl;
    cout << endl << endl;

    // Init GUI window
    DRAW::Screen* screen = new DRAW::Screen(WIDTH, HEIGHT, "screen0", argc - 1);

    // Seed random number generator based on first char of argv[1] (first shape input)
    srand(**(argv + 1));

    // Loop through each command line arg
    char** inputWordsPtr = argv;
    for (int i = 0; i < (argc - 1); i++) {

        // First argv is program name, so increment first
        inputWordsPtr++;

        // Draw shape
        char* inputWord = *inputWordsPtr;
        char* inputLower = ToLower(inputWord);
        screen->AddShape(inputLower);

        // Deallocate memory
        delete[] inputLower;
    }

    // Finally, render all drawn shapes
    screen->Render();

    // Pause for an additional 4 seconds with waitKey() then deallocate memory
    cv::waitKey(4000);
    delete screen;
}
