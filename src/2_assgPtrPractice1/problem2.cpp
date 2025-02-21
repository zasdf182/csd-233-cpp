
#include <iostream>
using namespace std;

// ========================================================================== //
// ``````````````````````````````` PROBLEM 2 ```````````````````````````````` //
// Write code that:
// - Allocates an array of characters that is initialized to your name.
// - Declares a pointer to the array.
// - Uses pointer arithmetic change the second character in your name to "Z."
// .......................................................................... //
// ========================================================================== //

char* GetNewCharArr(string contents = "", bool logDebug = false) {
    // Init char array
    char charArr[contents.length() + 1];
    // Init pointer used to debug, before char array is mutated
    char* charArrPtr = charArr;
    // Mutate char array
    strcpy(charArr, contents.c_str());
    // Debug
    if (logDebug) {
        cout << "[LOG] Created new char array. Current value: ";
        while (charArrPtr != '\0') {
            cout << *charArrPtr;
            charArrPtr++;
        }
        cout << endl;
    }
}

void ChangeNthCharToZ(char charArrToChange[], int n) {
    char* charPtr = charArrToChange;
    charPtr = charPtr + n - 1; // charPtr starts at 1st char, so its n - 1
    *charPtr = 'Z';
}

int main() {
    char* charArrWithMyName = GetNewCharArr("Chris Ayson", true);
    ChangeNthCharToZ(charArrWithMyName, 2);
}
