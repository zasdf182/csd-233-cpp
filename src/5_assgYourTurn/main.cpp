#include "charPtrLinkedList.cpp"
#include <iostream>
using namespace std;


/**
 * Reads a file and loads all the words into a list.
 * Then, interactively asks the user to delete words,
 * until the program quits.
 */
int main(int argc, char** argv) {
    char* filePath; // Path to file with words.

    // Part 1: Read a file (user inputs filePath on first command line arg).
    if (argc < 2) {
        cout << endl;
        cout << endl << "ERROR: Missing arg.";
        cout << endl << "First arg should be path to file to read.";
        return 1;
    }
    filePath = argv[1];

    // Part 2,3: Store all words in file in a linked list.
    // List is doubly linked and alphabetically sorted.

    // Part 4,5: Display all strings in reverse order.
    // Ask user to provide words, and delete Nodes containing those words.
    // Give an error message if word isnt in list.
    // Display the new contents after each deletion.

    // End: Deallocate all Nodes in list
}
