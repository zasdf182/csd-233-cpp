#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ##################################################################### //
// ####################### FUNCTION DECLARATIONS ####################### //
// ##################################################################### //

int stringLen(char str[]);
int stringLen(string str);
void arrayCopy();
void swap(int* ptr0, int* ptr1);

// ##################################################################### //
// ################################ MAIN ############################### //
// ##################################################################### //

// ===================================================================== //
// Tests each "Your Turn" function from Module 2 PowerPoint
// ===================================================================== //
int main() {

    // Header
    cout << endl;

    // Slide 15
    char str0[] = "1234";
    string str1 = "5678";
    cout << "Slide 15 -- stringLen" << endl;
    cout << "---------------------" << endl;
    cout << "stringLen(char str[]): " << stringLen(str0) << endl;
    cout << "stringLen(string str): " << stringLen(str1) << endl;

    // Slide 40
    cout << endl;
    cout << "Slide 40 -- arrayCopy" << endl;
    cout << "---------------------" << endl;
    cout << "arrayCopy(): ";
    arrayCopy();
    cout << endl;

    // Slide 45
    int num0 = 11;
    int num1 = 2222;
    cout << endl;
    cout << "Slide 45 -- swap" << endl;
    cout << "----------------" << endl;
    cout << "original num0: " << num0 << endl;
    cout << "original num1: " << num1 << endl;
    swap(&num0, &num1);
    cout << "after swap num0: " << num0 << endl;
    cout << "after swap num1: " << num1 << endl;
}

// ##################################################################### //
// ######################## FUNCTION DEFINITIONS ####################### //
// ##################################################################### //

// ===================================================================== //
// SLIDE 15 -- Write a function that returns the length of a character array
// Can you use the same code for a string?
// -- Yes, I think so, as demonstrated with the function overload below
// ===================================================================== //

int stringLen(char str[]) {
    int len = 0;
    char buffer = str[0];
    while (buffer != '\0')
        buffer = str[++len];
    return len;
}

int stringLen(string str) {
    int len = 0;
    char buffer = str[0];
    while (buffer != '\0')
        buffer = str[++len];
    return len;
}

// ===================================================================== //
// SLIDE 40 -- Write a function that uses pointer arithmetic/++ incrementor
// to copy values of a 5 element integer array
// ===================================================================== //

void arrayCopy() {
    int source[] = {0, 1, 2, 3, 4};
    int dest[5];

    // use pointers to copy source to dest
    int* sp = source;

    /* add your code to copy here */
    int* sourcePtr = source; // points at 0
    int sourceBytes = sizeof(source); // source is 20 bytes
    int sourceCount = sizeof(source) / sizeof(source[0]); // source has 5 items

    // loop through each source item and copy it to dest
    for (int i = -1; i < sourceCount - 1;) {
        ++i;
        dest[i] = *(sourcePtr + i);
    }

    /* add code to print out dest array */
    int* destPtr = dest; // points at 0
    int destBytes = sizeof(source); // dest is 20 bytes
    int destCount = sizeof(source) / sizeof(source[0]); // dest has 5 items

    // loop through each dest item and print them
    for (int i = -1; i < destCount - 1;)
        std::cout << *(destPtr + (++i));
}

// ===================================================================== //
// SLIDE 45 -- Write a function that takes 2 pointers to ints, and upon return,
// the ints will have the values swapped
// ===================================================================== //

void swap(int* ptr0, int* ptr1) {
    int num0 = *ptr0;
    int num1 = *ptr1;
    *ptr0 = num1;
    *ptr1 = num0;
}

// ===================================================================== //
// SLIDE 51 -- Write a function that uses the new operator
// to dynamically allocate a character array and populates it
// with a message of your choosing.
//
// Make sure the buffer has the null terminator character.
//
// Return the dynamically allocated array via an output parameter
// (pointer to a pointer of characters).
//
// Print out the dynamically allocated array in the caller function
// using cout and free the memory using delete[]
// ===================================================================== //

void customMsg(char*** msgOut) {
    char* msg = new char[16];
    *msg = 'I'; msg++;
    *msg = ' '; msg++;
    *msg = 'L'; msg++;
    *msg = 'i'; msg++;
    *msg = 'k'; msg++;
    *msg = 'e'; msg++;
    *msg = ' '; msg++;
    *msg = 'T'; msg++;
    *msg = 'u'; msg++;
    *msg = 'r'; msg++;
    *msg = 't'; msg++;
    *msg = 'l'; msg++;
    *msg = 'e'; msg++;
    *msg = 's'; msg++;
    *msg = '!'; msg++;
    *msg = '\0';
    *msgOut = &msg;
}
