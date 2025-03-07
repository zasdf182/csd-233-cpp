#ifndef MAIN_HPP
#define MAIN_HPP
#include "engine.cpp"
#include "treeNode.cpp"
#include "tree.cpp"
using namespace std;




////////////////////////////////////////////////////////////////////////////////
// Data structures
////////////////////////////////////////////////////////////////////////////////

typedef map<int, bool> NumberTracker;
typedef Collections::TreeNode<int> IntNode;
typedef Collections::Tree<int> IntTree;
typedef Collections::TreeNode<string> StringNode;
typedef Collections::Tree<string> StringTree;




////////////////////////////////////////////////////////////////////////////////
// Types used to break down the main program into smaller steps
////////////////////////////////////////////////////////////////////////////////

enum ProgramStep {
    one = 1,
    two = 2,
    quit = 'q',
};
typedef Singletons::Engine<string, ProgramStep> MainEngine;
ProgramStep IntTreeTest(string* context);
ProgramStep StringTreeTest(string* context);




////////////////////////////////////////////////////////////////////////////////
#endif
