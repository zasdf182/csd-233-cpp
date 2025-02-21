
#include <iostream>
using namespace std;

// ========================================================================== //
// ``````````````````````````````` PROBLEM 1 ```````````````````````````````` //
// Write code that:
// - Declares a pointer to an integer.
// - Increments the integer by dereferencing the pointer.
// .......................................................................... //
// ========================================================================== //

int* GetNewInt(int startingValue = 0, bool logDebug = false) {
    int* intPtr = new int(startingValue);
    if (logDebug)
        cout << "[LOG] Created new int. Current value: " << *intPtr << endl;
    return intPtr;
}

void IncrementInt(int* ptrToInt, bool logDebug = false) {
    (*ptrToInt)++;
    if (logDebug)
        cout << "[LOG] Incremented int. Current value: " << *ptrToInt << endl;
}

int main() {
    // Introduce program
    cout << endl << endl;
    cout << "Hello!";
    cout << " This program will declare a pointer to an integer.";
    cout << " Then, it will increment the integer.";
    cout << endl << endl;

    // Run program
    int* intPtr0 = GetNewInt(true);
    IncrementInt(intPtr0, true);

    // Clean up program
    cout << endl << endl;
    delete intPtr0;
    return 0;
}
