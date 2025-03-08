#include <iostream>
#include <random>
#include "main.hpp"
using namespace std;








int main() {
    srand(42);
    MainEngine engine;
    engine.Actions[ProgramStep::one] = IntTreeTest;
    engine.Actions[ProgramStep::two] = StringTreeTest;
    engine.Start(IntTreeTest);
}








// ##################################################################### //
// ########################### SUBPROGRAM ONE ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Subprogram one of the main program.
///        Tests Tree class by adding a list of sequential random numbers.
////////////////////////////////////////////////////////////////////////////////
ProgramStep IntTreeTest(string* context) {
    IntTestEngine engine;
    engine.Actions[IntTestStep::introMsg] = TestOneIntro;
    engine.Actions[IntTestStep::a] = InitIntArray;
    engine.Actions[IntTestStep::b] = RandomizeIntArray;
    engine.Actions[IntTestStep::c] = CreateIntTree;
    engine.Actions[IntTestStep::d] = ValidateTree;
    engine.Actions[IntTestStep::e] = RemoveRandomTenIntsFromTree;
    engine.Actions[IntTestStep::f] = TraverseAndValidateTree;
    engine.Start(TestOneIntro);
    return ProgramStep::two;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step zero of subprogram one.
///        Prints an introductory message explaining the subprogram.
////////////////////////////////////////////////////////////////////////////////
IntTestStep TestOneIntro(IntTestContext* context) {
    cout << endl;
    cout << endl;
    cout << endl << "================ STARTING TEST SUITE 1 ================";
    cout << endl << "1. Creates an array of 1000 integers 0...999";
    cout << endl << "2. Randomizes the array by swapping numbers randomly.";
    cout << endl << "3. Inserts all of the array contents into a binary search tree.";
    cout << endl << "4. Verifies that all numbers 0...999 are in the binary search tree.";
    cout << endl << "5. Removes 10 random numbers from the binary search tree.";
    cout << endl << "6. Does an in-order traversal verifying that each number 0...999 is found except for the 10 that were removed.";
    return IntTestStep::a;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step one of subprogram one.
///        Creates an array of 1000 integers and an empty int tree.
/// @param context A pair this function uses to output the new array and new tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep InitIntArray(IntTestContext* context) {
    array<int, 1000> numbers;
    IntTree tree;

    for (int i = 0; i < 1000; i++) numbers[i] = i;
    *context = make_pair(numbers, tree);

    cout << endl;
    cout << endl << "COMPLETED STEP 1. Created array:";
    cout << endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << ' ' << *it;
    return IntTestStep::b;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step two of subprogram one.
///        Randomly swaps values in the int array.
////////////////////////////////////////////////////////////////////////////////
IntTestStep RandomizeIntArray(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    for (int i = 0; i < 1000; i++) {
        int randomIndex = rand() % 1000;
        int num1 = numbers[i];
        int num2 = numbers[randomIndex];
        numbers[i] = num2;
        numbers[randomIndex] = num1;
    }

    cout << endl;
    cout << endl << "COMPLETED STEP 2. Randomized array to:";
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << ' ' << *it;
    return IntTestStep::c;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step three of subprogram one.
///        Inserts the int array contents into the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep CreateIntTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    for (int i = 0; i < 1000; i++)
        tree.AddItem(numbers[i]);

    cout << endl;
    cout << endl << "COMPLETED STEP 3: Created binary search tree. Head value:";
    cout << tree.Head()->Data();
    return IntTestStep::d;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step four of subprogram one.
///        Verifies that all numbers 0...999 are in the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep ValidateTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    NumberTracker foundNumbers;
    NumberTracker missingNumbers;

    for (int i = 0; i < 1000; i++)
        if (tree.FindItem(numbers[i]))
            foundNumbers[i] = true;
        else
            missingNumbers[i] = true;

    cout << endl;
    if (missingNumbers.size() <= 0)
        cout << endl << "COMPLETED STEP 4. All numbers were found. None were missing.";
    else {
        cout << endl << "COMPLETED STEP 4. These numbers were missing:";
        cout << endl;
        for (auto it = missingNumbers.begin(); it != missingNumbers.end(); it++)
            cout << ' ' << it->first;
        cout << endl << "These numbers were found:";
        for (auto it = foundNumbers.begin(); it != foundNumbers.end(); it++)
            cout << ' ' << it->first;
    } return IntTestStep::e;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step five of subprogram one.
///        Removes 10 random numbers from the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep RemoveRandomTenIntsFromTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    NumberTracker removedNumbers;
    for (int i = 0; i < 10;) {
        int randomIndex = rand() % 1000;
        int randomRemovedNumber = numbers[randomIndex];

        bool numberAlreadyRemoved = removedNumbers.count(randomRemovedNumber) > 0;
        if (numberAlreadyRemoved) continue;

        removedNumbers[randomRemovedNumber] = true;
        tree.RemoveItem(randomRemovedNumber);
        i++;
    }

    cout << endl;
    cout << "COMPLETED STEP 5: These numbers were removed from the tree:";
    cout << endl;
    for (auto it = removedNumbers.begin(); it != removedNumbers.end(); it++)
        cout << ' ' << it->first;
    return IntTestStep::f;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step six of subprogram one.
///        Verifies that 0...999 is found in tree, except for 10 removed nums.
///        Does an in-order traversal and uses a lambda function on each node.
////////////////////////////////////////////////////////////////////////////////
IntTestStep TraverseAndValidateTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    NumberTracker foundNumbers;
    tree.ExecFuncOnNodesInOrder<NumberTracker> ([](IntNode * node, NumberTracker & foundNumbers) {
        int foundNumber = node->Data();
        foundNumbers[foundNumber] = true;
    }, foundNumbers);

    cout << endl;
    cout << "COMPLETED STEP 6: These numbers were found:";
    cout << endl;
    for (auto it = foundNumbers.begin(); it != foundNumbers.end(); it++)
        cout << ' ' << it->first;
    return IntTestStep::DONE;
}








// ##################################################################### //
// ########################### SUBPROGRAM TWO ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Part two of the main program.
///        Tests Tree class by using strings from a file specified on cmd line.
/// @return The next program step to do after this.
////////////////////////////////////////////////////////////////////////////////
ProgramStep StringTreeTest(string* context) {
    return ProgramStep::quit;
}
