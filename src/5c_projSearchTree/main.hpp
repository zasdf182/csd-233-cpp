#ifndef MAIN_HPP
#define MAIN_HPP
#include "engine.cpp"
#include "treeNode.cpp"
#include "tree.cpp"
using namespace std;




////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////

enum ProgramStep {
    quit = 'q',
    one = 1,
    two = 2,
};
typedef Singletons::Engine<string, ProgramStep> MainEngine;
ProgramStep IntTreeTest(string* context);
ProgramStep StringTreeTest(string* context);




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
IntTestStep InitIntArray(IntTestContext* context);
IntTestStep RandomizeIntArray(IntTestContext* context);
IntTestStep CreateIntTree(IntTestContext* context);
IntTestStep ValidateTree(IntTestContext* context);
IntTestStep RemoveRandomTenIntsFromTree(IntTestContext* context);
IntTestStep TraverseAndValidateTree(IntTestContext* context);




////////////////////////////////////////////////////////////////////////////////
#endif
