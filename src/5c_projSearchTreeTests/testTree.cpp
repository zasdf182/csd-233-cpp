#include <string>
#include <gtest/gtest.h>
#include "treeNode.cpp"
#include "tree.cpp"
namespace TestTree {

//============================================================================//
// Unit tests for Tree::AddItem()
//============================================================================//
TEST(AddItemTest, HandlesInts) {
    Collections::Tree<int> tree;
    tree.AddItem(INT_MIN);
    tree.AddItem(INT_MIN + 1);
    tree.AddItem(-1);
    tree.AddItem(0);
    tree.AddItem(1);
    tree.AddItem(INT_MAX - 1);
    tree.AddItem(INT_MAX);
}

TEST(AddItemTest, HandlesFloats) {
    Collections::Tree<float> tree;
    tree.AddItem(FLT_MIN);
    tree.AddItem(FLT_MIN + 1);
    tree.AddItem(-1);
    tree.AddItem(0);
    tree.AddItem(1);
    tree.AddItem(FLT_MAX - 1);
    tree.AddItem(FLT_MAX);
}

TEST(AddItemTest, HandlesDoubles) {
    Collections::Tree<double> tree;
    tree.AddItem(DBL_MIN);
    tree.AddItem(DBL_MIN + 1);
    tree.AddItem(-1);
    tree.AddItem(0);
    tree.AddItem(1);
    tree.AddItem(DBL_MAX - 1);
    tree.AddItem(DBL_MAX);
}

TEST(AddItemTest, HandlesChars) {
    Collections::Tree<char> tree;
    tree.AddItem(CHAR_MIN);
    tree.AddItem(CHAR_MIN + 1);
    tree.AddItem(-1);
    tree.AddItem(0);
    tree.AddItem(1);
    tree.AddItem(CHAR_MAX - 1);
    tree.AddItem(CHAR_MAX);
}

TEST(AddItemTest, HandlesBools) {
    Collections::Tree<bool> tree;
    tree.AddItem(false);
    tree.AddItem(true);
}

TEST(AddItemTest, HandlesEmptyTree) {
    Collections::Tree<int> tree;
    EXPECT_EQ(tree.Head(), nullptr);
    tree.AddItem(0);
    EXPECT_EQ(tree.Head()->Data(), 0);
    EXPECT_EQ(tree.Head()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right(), nullptr);
}

TEST(AddItemTest, HandlesLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(8);
    tree.AddItem(5);
    EXPECT_EQ(tree.Head()->Data(), 8);
    EXPECT_EQ(tree.Head()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Data(), 5);
    EXPECT_EQ(tree.Head()->Left()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Right(), nullptr);
}

TEST(AddItemTest, HandlesRight) {
    Collections::Tree<int> tree;
    tree.AddItem(8);
    tree.AddItem(11);
    EXPECT_EQ(tree.Head()->Data(), 8);
    EXPECT_EQ(tree.Head()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Data(), 11);
    EXPECT_EQ(tree.Head()->Right()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Right(), nullptr);
}

TEST(AddItemTest, HandlesLeftLeft) {
    Collections::Tree<char> tree;
    tree.AddItem('e');
    tree.AddItem('d');
    tree.AddItem('c');
    EXPECT_EQ(tree.Head()->Data(), 'e');
    EXPECT_EQ(tree.Head()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Data(), 'd');
    EXPECT_EQ(tree.Head()->Left()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Left()->Data(), 'c');
    EXPECT_EQ(tree.Head()->Left()->Left()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Left()->Left(), nullptr);
}

TEST(AddItemTest, HandlesLeftRight) {
    Collections::Tree<char> tree;
    tree.AddItem('z');
    tree.AddItem('x');
    tree.AddItem('y');
    EXPECT_EQ(tree.Head()->Data(), 'z');
    EXPECT_EQ(tree.Head()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Data(), 'x');
    EXPECT_EQ(tree.Head()->Left()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Right()->Data(), 'y');
    EXPECT_EQ(tree.Head()->Left()->Right()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Left()->Right()->Left(), nullptr);
}

TEST(AddItemTest, HandlesRightLeft) {
    Collections::Tree<char> tree;
    tree.AddItem('g');
    tree.AddItem('m');
    tree.AddItem('j');
    EXPECT_EQ(tree.Head()->Data(), 'g');
    EXPECT_EQ(tree.Head()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Data(), 'm');
    EXPECT_EQ(tree.Head()->Right()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Left()->Data(), 'j');
    EXPECT_EQ(tree.Head()->Right()->Left()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Left()->Left(), nullptr);
}

TEST(AddItemTest, HandlesRightRight) {
    Collections::Tree<int> tree;
    tree.AddItem(2084);
    tree.AddItem(2160);
    tree.AddItem(2868);
    EXPECT_EQ(tree.Head()->Data(), 2084);
    EXPECT_EQ(tree.Head()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Data(), 2160);
    EXPECT_EQ(tree.Head()->Right()->Left(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Right()->Data(), 2868);
    EXPECT_EQ(tree.Head()->Right()->Right()->Right(), nullptr);
    EXPECT_EQ(tree.Head()->Right()->Right()->Left(), nullptr);
}

//============================================================================//
// Unit tests for Tree::FindItem()
//============================================================================//
TEST(FindItemTest, HandlesEmptyTree) {
    Collections::Tree<int> tree;
    EXPECT_EQ(tree.FindItem(INT_MIN), false);
    EXPECT_EQ(tree.FindItem(INT_MIN + 1), false);
    EXPECT_EQ(tree.FindItem(-1), false);
    EXPECT_EQ(tree.FindItem(0), false);
    EXPECT_EQ(tree.FindItem(1), false);
    EXPECT_EQ(tree.FindItem(INT_MAX - 1), false);
    EXPECT_EQ(tree.FindItem(INT_MAX), false);
}

TEST(FindItemTest, HandlesLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(7);
    tree.AddItem(5);
    EXPECT_EQ(tree.FindItem(7), true);
    EXPECT_EQ(tree.FindItem(5), true);
    EXPECT_EQ(tree.FindItem(42), false);
}
}
