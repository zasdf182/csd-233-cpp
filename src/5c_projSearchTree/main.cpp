#include <iostream>
#include <random>
#include "main.hpp"
using namespace std;




int main() {
    srand(42);
    MainEngine engine;
    engine.Actions[ProgramStep::one] = IntTreeTest;
    engine.Start(IntTreeTest);
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Part one of the main program.
///        Tests Tree class by adding a list of sequential random numbers.
/// @param context A Tree object to perform tests on.
/// @return The next program step to do after this (ProgramStep::two).
////////////////////////////////////////////////////////////////////////////////
ProgramStep IntTreeTest(IntTree* context) {
    int numbers[1000];
    NumberTracker removedNumbers;
    NumberTracker foundNumbers;
    Collections::Tree<int> tree;

    cout << endl;
    cout << endl;
    cout << endl << "================ STARTING TEST SUITE 1 ================";
    cout << endl << "1. Creates an array of 1000 integers 0...999";
    cout << endl << "2. Randomizes the array by swapping numbers randomly.";
    cout << endl << "3. Inserts all of the array contents into a binary search tree.";
    cout << endl << "4. Verifies that all numbers 0...999 are in the binary search tree.";
    cout << endl << "5. Removes 10 random numbers from the binary search tree.";
    cout << endl << "6. Does an in-order traversal verifying that each number 0...999 is found except for the 10 that were removed.";

    // Create an array of 1000 integers.
    cout << endl;
    cout << endl << "STARTING STEP 1: Array created.";
    for (int i = 0; i < 1000; i++)
        numbers[i] = i;

    // Randomize the array by swapping values in the array.
    cout << endl;
    cout << endl << "STARTING STEP 2: Array randomized.";
    for (int i = 0; i < 1000; i++) {
        int randomIndex = rand() % 1000;
        int num1 = numbers[i];
        int num2 = numbers[randomIndex];
        numbers[i] = num2;
        numbers[randomIndex] = num1;
    }

    // Insert all the numbers into the binary tree.
    cout << endl;
    cout << endl << "STARTING STEP 3: Binary search tree created.";
    for (int i = 0; i < 1000; i++)
        tree.AddItem(numbers[i]);

    // Search for each number, and make sure each number is found.
    cout << endl;
    cout << endl << "STARTING STEP 4: Searching for each number 0 to 999...";
    for (int i = 0; i < 1000; i++) {
        bool found = tree.FindItem(numbers[i]);
        if (!found)
            cout << endl << "ERROR: " << i << " was not found in the tree.";
    } cout << endl << "STEP 4 COMPLETED. If nothing else was mentioned, all numbers were found in the tree.";

    // Remove 10 random numbers.
    cout << endl;
    cout << endl << "STARTING STEP 5: Ten random numbers were removed from the tree.";
    for (int i = 0; i < 10;) {
        int randomIndex = rand() % 1000;
        int randomRemovedNumber = numbers[randomIndex];
        if (removedNumbers.count(randomRemovedNumber) > 0) continue;

        removedNumbers[randomRemovedNumber] = true;
        tree.RemoveItem(randomRemovedNumber);
        i++;
    }

    // Do an in-order-traversal verifying that each number 0...999 is found except for the 10 that were removed.
    // Uses a lambda function.
    cout << endl;
    cout << endl << "STARTING STEP 6: Searching the tree with an in-order traversal...";
    tree.ExecFuncOnNodesInOrder<NumberTracker> ([](IntNode * node, NumberTracker & foundNumbers) {
        int foundNumber = node->Data();
        foundNumbers[foundNumber] = true;
    }, foundNumbers);

    for (int i = 0; i < 1000; i++) {
        if (removedNumbers.count(i) > 0) continue;
        if (foundNumbers.count(i) <= 0)
            cout << endl << "ERROR: " << i << " was not found in the tree.";
    } cout << endl << "STEP 6 COMPLETED. If nothing else was mentioned, all numbers were found in the tree.";
    return ProgramStep::two;
}
