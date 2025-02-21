#include <iostream>
using namespace std;

//// ==========================================================================
//// ``````````````````````````````````````````````````````````````````````````
//// .
//// ..          Chris Ayson
//// ...         Prof. Spinrad
//// ...         CSD233 13170 - C++ Programming
//// ...         12 Feb 2025
//// ...
//// ..          MIDTERM QUESTION 1
//// .
//// ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//// ==========================================================================


/**
 * Outputs a std::string in reverse, into a pointer to a char*.
 * NOTE: Creates a new char[] that the user should delete later.
 * NOTE: This function will add a null char to the end of the output char*,
 *       even if the input std::string already has one.
 */
void StringToCharBuffer(string s, char** pp) {
    // Dynamically allocate a buffer char[] big enough to store the string
    // Add null terminating character to the end
    char* buffer = new char[s.length() + 1];
    buffer[s.length()] = '\0';

    // Create a pointer that starts at the first char of buffer
    char* cursor = buffer;

    // Loop through all chars in s, starting from last, and going backwards
    // Copy characters to buffer using cursor
    for (int i = s.length() - 1; i >= 0; i--) {
        *cursor = s.at(i);
        cursor++;
    }

    // Output buffer to char**
    *pp = buffer;
}




//// ==========================================================================
//// ==========================================================================

/**
 * Main function that tests StringToCharBuffer.
 */
int main() {
    char* p;

    string s = "!kcoR sredoC";
    StringToCharBuffer(s, &p);
    cout << p << endl;
    delete[] p;
    return 0;
}
