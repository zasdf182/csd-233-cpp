#ifndef MAIN_HPP
#define MAIN_HPP
#include <fstream>
#include <iostream>
#include <random>
#include "engine.cpp"
#include "treeNode.cpp"
#include "tree.cpp"
#include "str.cpp"
using namespace std;




////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////

struct ProgramContext {
    int argc;
    char** argv;
};

enum ProgramStep {
    DONE = -1,
    quit = 'q',
    getInput = 'i',
    introMsg = 0,
    one = 1,
    two = 2,
};

typedef Singletons::Engine<ProgramContext, ProgramStep> MainEngine;
ProgramStep IntroMessage(ProgramContext* context);
ProgramStep QuitMessage(ProgramContext* context);
ProgramStep GetSubprogramChoice(ProgramContext* context);
ProgramStep IntTreeTest(ProgramContext* context);
ProgramStep StringTreeTest(ProgramContext* context);




////////////////////////////////////////////////////////////////////////////////
// Subprogram one: Int Tree Test
////////////////////////////////////////////////////////////////////////////////

typedef map<int, bool> NumberTracker;
typedef Collections::TreeNode<int> IntNode;
typedef Collections::Tree<int> IntTree;
typedef pair<array<int, 1000>, IntTree> IntTestContext;

enum IntTestStep {
    aDONE = -1,
    aIntroMsg = 0,
    a1 = 1,
    a2 = 2,
    a3 = 3,
    a4 = 4,
    a5 = 5,
    a6 = 6,
};

typedef Singletons::Engine<IntTestContext, IntTestStep> IntTestEngine;
IntTestStep TestOneIntro(IntTestContext* context);
IntTestStep a1_InitIntArray(IntTestContext* context);
IntTestStep a2_RandomizeIntArray(IntTestContext* context);
IntTestStep a3_CreateIntTree(IntTestContext* context);
IntTestStep a4_ValidateTree(IntTestContext* context);
IntTestStep a5_RemoveRandomTenIntsFromTree(IntTestContext* context);
IntTestStep a6_TraverseAndValidateTree(IntTestContext* context);




////////////////////////////////////////////////////////////////////////////////
// Subprogram two: String Tree Test
////////////////////////////////////////////////////////////////////////////////

typedef Collections::TreeNode<string> StringNode;
typedef Collections::Tree<string> StringTree;
struct StringTestContext {
    int argc;
    char** argv;
    ifstream* file;
    StringTree tree;
};

enum StringTestStep {
    bDONE = -1,
    bIntroMsg = 0,
    b1 = 1,
    b1e = 1001,
    b2 = 2,
    b2e = 2001,
    b2ee = 2002,
    b3 = 3,
    b4 = 4,
    b5 = 5,
    b6 = 6,
    b6s = 6001
};

typedef Singletons::Engine<StringTestContext, StringTestStep> StringTestEngine;
StringTestStep TestTwoIntro(StringTestContext* context);
StringTestStep b1_GetFilePathFromCmdArg(StringTestContext* context);
StringTestStep b1e_ErrorCmdArg(StringTestContext* context);
StringTestStep b2_TryOpenFile(StringTestContext* context);
StringTestStep b2e_ErrorOpenFile(StringTestContext* context);
StringTestStep b2ee_ErrorEmptyFile(StringTestContext* context);
StringTestStep b3_ReadFileIntoTree(StringTestContext* context);
StringTestStep b4_PrintPreOrderTraversal(StringTestContext* context);
StringTestStep b5_PrintInOrderTraversal(StringTestContext* context);
StringTestStep b6_CmdInputSearchOrQuit(StringTestContext* context);
StringTestStep b6s_SearchTreeForWord(StringTestContext* context);




////////////////////////////////////////////////////////////////////////////////
#endif
