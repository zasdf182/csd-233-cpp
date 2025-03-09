#include "main.hpp"
using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// @brief Main program driver.
///        Starts with an intro message asking the user to run subprogram one or two.
///        After the chosen subprogram ends, the entire program will end.
///        Run the program again to see other subprograms.
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    {
        srand(42);
        MainEngine engine;

        engine.CurrentState->argc = argc;
        engine.CurrentState->argv = argv;

        engine.Actions[ProgramStep::quit] = QuitMessage;
        engine.Actions[ProgramStep::getInput] = GetSubprogramChoice;
        engine.Actions[ProgramStep::introMsg] = IntroMessage;
        engine.Actions[ProgramStep::one] = IntTreeTest;
        engine.Actions[ProgramStep::two] = StringTreeTest;

        engine.Start(IntroMessage);
    }

    cout << endl;
    cout << endl;
    return 0;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Explains the program.
///        Asks the user to choose subprogram one or two.
///        After the chosen subprogram ends, the entire program will end.
///        Run the program again to see other subprograms.
////////////////////////////////////////////////////////////////////////////////
ProgramStep IntroMessage(ProgramContext* context) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "================ BINARY SEARCH TREE TEST PROGRAM ================";
    cout << endl << "This program has two subprograms.";
    cout << endl << "Each subprogram is a test suite for binary search trees.";
    cout << endl;
    cout << endl << "Subprogram one tests an IntTree with an array of numbers 0...999";
    cout << endl << "It is completely linear and requires no user input.";
    cout << endl;
    cout << endl << "Subprogram two tests a StringTree with a list of words read from a file.";
    cout << endl << "It has an interactive input section that loops until the user chooses to quit.";
    cout << endl;
    cout << endl << "After a subprogram ends, the entire program will end.";
    cout << endl << "Run the program again to see other subprograms.";
    cout << endl;
    cout << endl << "Now, choose a subprogram to run.";
    cout << endl << "Type '1' to run subprogram one.";
    cout << endl << "Type '2' to run subprogram two.";
    cout << endl << "Type 'q' to quit the program.";
    cout << endl;
    return ProgramStep::getInput;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief A final message displayed right before the program quits.
////////////////////////////////////////////////////////////////////////////////
ProgramStep QuitMessage(ProgramContext* context) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "================ PROGRAM FINISHED ================";
    cout << endl << "The program will now exit. Thank you and come again!";
    cout << endl;
    return ProgramStep::DONE;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Reads cmd input and runs the appropriate subprogram.
///        If input is invalid, display an error message and run this step again.
////////////////////////////////////////////////////////////////////////////////
ProgramStep GetSubprogramChoice(ProgramContext* context) {
    string input;
    cout << endl << " -> ";
    cin >> input;

    if (input == "q")
        return ProgramStep::quit;
    else if (input == "1")
        return ProgramStep::one;
    else if (input == "2")
        return ProgramStep::two;

    cout << "  X " << "Invalid input.";
    cout << endl;
    return ProgramStep::getInput;
}








// ##################################################################### //
// ########################### SUBPROGRAM ONE ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Subprogram one of the main program.
///        Tests Tree class by adding a list of sequential random numbers.
////////////////////////////////////////////////////////////////////////////////
ProgramStep IntTreeTest(ProgramContext* context) {
    IntTestEngine engine;

    engine.Actions[IntTestStep::aIntroMsg] = TestOneIntro;
    engine.Actions[IntTestStep::a1] = a1_InitIntArray;
    engine.Actions[IntTestStep::a2] = a2_RandomizeIntArray;
    engine.Actions[IntTestStep::a3] = a3_CreateIntTree;
    engine.Actions[IntTestStep::a4] = a4_ValidateTree;
    engine.Actions[IntTestStep::a5] = a5_RemoveRandomTenIntsFromTree;
    engine.Actions[IntTestStep::a6] = a6_TraverseAndValidateTree;

    engine.Start(TestOneIntro);
    return ProgramStep::quit;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 0 of subprogram one.
///        Prints an introductory message explaining the subprogram.
////////////////////////////////////////////////////////////////////////////////
IntTestStep TestOneIntro(IntTestContext* context) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "================ STARTING TEST SUITE 1 ================";
    cout << endl << "1. Creates an array of 1000 integers 0...999";
    cout << endl << "2. Randomizes the array by swapping numbers randomly.";
    cout << endl << "3. Inserts all of the array contents into a binary search tree.";
    cout << endl << "4. Verifies that all numbers 0...999 are in the binary search tree.";
    cout << endl << "5. Removes 10 random numbers from the binary search tree.";
    cout << endl << "6. Does an in-order traversal verifying that each number 0...999 is found except for the 10 that were removed.";
    return IntTestStep::a1;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 1 of subprogram one.
///        Creates an array of 1000 integers and an empty int tree.
/// @param context A pair this function uses to output the new array and new tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a1_InitIntArray(IntTestContext* context) {
    array<int, 1000> numbers;
    IntTree tree;

    for (int i = 0; i < 1000; i++) numbers[i] = i;
    *context = make_pair(numbers, tree);

    cout << endl;
    cout << endl << "COMPLETED STEP 1. Created array:";
    cout << endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << ' ' << *it;
    return IntTestStep::a2;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 2 of subprogram one.
///        Randomly swaps values in the int array.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a2_RandomizeIntArray(IntTestContext* context) {
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
    cout << endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << ' ' << *it;
    return IntTestStep::a3;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 3 of subprogram one.
///        Inserts the int array contents into the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a3_CreateIntTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    for (int i = 0; i < 1000; i++)
        tree.AddItem(numbers[i]);

    cout << endl;
    cout << endl << "COMPLETED STEP 3: Created binary search tree. Head value: ";
    cout << tree.Head()->Data();
    return IntTestStep::a4;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 4 of subprogram one.
///        Verifies that all numbers 0...999 are in the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a4_ValidateTree(IntTestContext* context) {
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
    } return IntTestStep::a5;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 5 of subprogram one.
///        Removes 10 random numbers from the binary search tree.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a5_RemoveRandomTenIntsFromTree(IntTestContext* context) {
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
    cout << endl << "COMPLETED STEP 5: These numbers were removed from the tree:";
    cout << endl;
    for (auto it = removedNumbers.begin(); it != removedNumbers.end(); it++)
        cout << ' ' << it->first;
    return IntTestStep::a6;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 6 of subprogram one.
///        Verifies that 0...999 is found in tree, except for 10 removed nums.
///        Does an in-order traversal and uses a lambda function on each node.
////////////////////////////////////////////////////////////////////////////////
IntTestStep a6_TraverseAndValidateTree(IntTestContext* context) {
    array<int, 1000>& numbers = context->first;
    IntTree& tree = context->second;

    NumberTracker foundNumbers;
    tree.ExecFuncOnNodesInOrder<NumberTracker> ([](IntNode * node, NumberTracker & foundNumbers) {
        int foundNumber = node->Data();
        foundNumbers[foundNumber] = true;
    }, foundNumbers);

    cout << endl;
    cout << endl << "COMPLETED STEP 6: These numbers were found:";
    cout << endl;
    for (auto it = foundNumbers.begin(); it != foundNumbers.end(); it++)
        cout << ' ' << it->first;
    cout << endl;
    return IntTestStep::aDONE;
}








// ##################################################################### //
// ########################### SUBPROGRAM TWO ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Part two of the main program.
///        Tests Tree class by using strings from a file specified on cmd line.
/// @return The next program step to do after this.
////////////////////////////////////////////////////////////////////////////////
ProgramStep StringTreeTest(ProgramContext* context) {
    StringTestEngine engine;

    engine.CurrentState->argc = context->argc;
    engine.CurrentState->argv = context->argv;
    engine.CurrentState->file = new ifstream();
    engine.CurrentState->tree = StringTree();

    engine.Actions[bIntroMsg] = TestTwoIntro;
    engine.Actions[b1] = b1_GetFilePathFromCmdArg;
    engine.Actions[b1e] = b1e_ErrorCmdArg;
    engine.Actions[b2] = b2_TryOpenFile;
    engine.Actions[b2e] = b2e_ErrorOpenFile;
    engine.Actions[b2ee] = b2ee_ErrorEmptyFile;
    engine.Actions[b3] = b3_ReadFileIntoTree;
    engine.Actions[b4] = b4_PrintPreOrderTraversal;
    engine.Actions[b5] = b5_PrintInOrderTraversal;
    engine.Actions[b6] = b6_CmdInputSearchOrQuit;
    engine.Actions[b6s] = b6s_SearchTreeForWord;

    engine.Start(TestTwoIntro);
    return ProgramStep::quit;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 0 of subprogram two.
///        Prints an introductory message explaining the subprogram.
////////////////////////////////////////////////////////////////////////////////
StringTestStep TestTwoIntro(StringTestContext* context) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "================ STARTING TEST SUITE 2 ================";
    cout << endl << "1. Gets the file specified on the command line arg.";
    cout << endl << "   If the command line doesnt have 1 argument, display an error message.";
    cout << endl << "2. Opens the file specified in the command line argument.";
    cout << endl << "   Verify the file opened successfully.";
    cout << endl << "   If the file failed to open, display an error message.";
    cout << endl << "3. Reads the entire file.";
    cout << endl << "   Parses each word separated by whitespaces.";
    cout << endl << "   Inserts each word into a binary search tree.";
    cout << endl << "4. Does a pre-order traversal of the tree.";
    cout << endl << "   Prints out the word at each node.";
    cout << endl << "5. Does an in-order traversal of the tree.";
    cout << endl << "   Prints out the word at each node.";
    cout << endl << "   The words should be displayed in alphabetical order.";
    cout << endl << "6. Loops on user input.";
    cout << endl << "   Asks the user to search for a word or to quit.";
    cout << endl << "   Tells the user if the corresponding word is in the binary tree. ";
    cout << endl << "   After the user quits, deletes all the tree nodes. ";
    cout << endl << "   Uses a post-order recursive traversal to delete them. ";
    cout << endl << "   Prints out the word at each node before deleting them. ";
    return StringTestStep::b1;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 1 of subprogram two.
///        Get the filepath specified on the command line arg.
///        If the command line doesnt have 1 argument, go to error msg step.
///        If it has at least 1 argument, go to try open file step.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b1_GetFilePathFromCmdArg(StringTestContext* context) {
    cout << endl;
    cout << endl << "COMPLETED STEP 1: Checked command line args for filepath.";

    if (context->argc <= 0)
        return StringTestStep::b1e;
    else
        return StringTestStep::b2;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 1E of subprogram two.
///        Displays an error message.
///        Informs the user they should rerun the program with a cmd line arg.
///        Ends subprogram two.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b1e_ErrorCmdArg(StringTestContext* context) {
    cout << endl;
    cout << endl << "ERROR: This program requires at least one command line arg.";
    cout << endl << "       Try run the program again.";
    cout << endl << "       The first command line arg should be a filepath to read.";
    cout << endl << "       The file should contain a list of whitespace-separated words to read.";
    return StringTestStep::bDONE;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 2 of subprogram two.
///        Attempts to open the file located at the given filepath.
///        If the file does not open successfully, go to error msg step.
///        If the file is empty, go to error msg step.
///        If the file opens successfully, go to read file into tree step.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b2_TryOpenFile(StringTestContext* context) {
    cout << endl;
    cout << endl << "COMPLETED STEP 2: Attempted to open file.";
    cout << endl;

    char* filepath = context->argv[1];
    context->file->open(filepath);

    if (!context->file->is_open())
        return StringTestStep::b2e;
    else if (!context->file->good())
        return StringTestStep::b2ee;
    else
        return StringTestStep::b3;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 2E of subprogram two.
///        Displays an error message that the specified file failed to open.
///        Informs the user they should rerun the program with another file.
///        Ends subprogram two.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b2e_ErrorOpenFile(StringTestContext* context) {
    cout << endl;
    cout << endl << "ERROR: Failed to open the specified file.";
    cout << endl << "       Try run the program again with another file.";
    return StringTestStep::bDONE;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 2EE of subprogram two.
///        Displays an error message that the specified file was empty.
///        Informs the user they should rerun the program with another file.
///        Ends subprogram two.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b2ee_ErrorEmptyFile(StringTestContext* context) {
    cout << endl;
    cout << endl << "ERROR: The specified file was empty.";
    cout << endl << "       Try run the program again with another file.";
    return StringTestStep::bDONE;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 3 of subprogram two.
///        Parses each word separated by whitespaces.
///        Inserts each word into a binary search tree.
///        Closes and deletes context->file.
///        It's expected that further subprogram steps will not need the ifstream.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b3_ReadFileIntoTree(StringTestContext* context) {
    cout << endl;
    cout << "COMPLETED STEP 3: Read words from file.";

    list<string> words = Str::GetWordsFromFile(context->file);
    for (auto it = words.begin(); it != words.end(); it++)
        context->tree.AddItem(*it);

    context->file->close();
    delete context->file;
    return StringTestStep::b4;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 4 of subprogram two.
///        Does a pre-order traversal of the tree.
///        Prints out the word stored in each node.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b4_PrintPreOrderTraversal(StringTestContext* context) {
    cout << endl;
    cout << endl << "COMPLETED STEP 4: Did a pre-order traversal of the tree.";
    cout << endl << "                  Printing out the word stored in each node:";
    cout << endl;

    int throwawayCtx = 0;
    context->tree.ExecFuncOnNodesPreOrder<int> ([](StringNode * node, int& ctx) {
        cout << ' ' << node->Data();
    }, throwawayCtx);
    return StringTestStep::b5;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 5 of subprogram two.
///        Does an in-order traversal of the tree.
///        Prints out the word stored in each node.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b5_PrintInOrderTraversal(StringTestContext* context) {
    cout << endl;
    cout << endl << "COMPLETED STEP 5: Did an in-order traversal of the tree.";
    cout << endl << "                  Printing out the word stored in each node:";
    cout << endl;

    int throwawayCtx = 0;
    context->tree.ExecFuncOnNodesInOrder<int> ([](StringNode * node, int& ctx) {
        cout << ' ' << node->Data();
    }, throwawayCtx);
    return StringTestStep::b6;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 6 of subprogram two.
///        Prints a message explaining the next program step.
///        Asks the user to search for a word or "q" to quit.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b6_CmdInputSearchOrQuit(StringTestContext* context) {
    cout << endl;
    cout << endl << "STEP 6: You may now choose a program action.";
    cout << endl << "        Type a word to search the tree for that word.";
    cout << endl << "        Type 'q' to quit the program.";
    cout << endl;
    return StringTestStep::b6s;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Step 6S of subprogram two.
///        Prints a prompt -> asking user for input.
///        If "q" is input, end subprogram two.
///        Otherwise, search the tree for the input word.
///        Tells the user if the corresponding word is in the binary tree.
///        Repeats this step until "q" is input.
////////////////////////////////////////////////////////////////////////////////
StringTestStep b6s_SearchTreeForWord(StringTestContext* context) {
    string input;
    cout << endl << " -> ";
    cin >> input;

    if (input == "q")
        return StringTestStep::bDONE;

    if (context->tree.FindItem(input))
        cout << "  + " << input << " was found in the tree.";
    else
        cout << "  X " << input << " was not found in the tree.";
    cout << endl;
    return StringTestStep::b6s;
}
