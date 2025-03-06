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

TEST(FindItemTest, HandlesRight) {
    Collections::Tree<int> tree;
    tree.AddItem(888);
    tree.AddItem(999);
    EXPECT_EQ(tree.FindItem(888), true);
    EXPECT_EQ(tree.FindItem(999), true);
    EXPECT_EQ(tree.FindItem(333), false);
}

TEST(FindItemTest, HandlesLeftLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(444444);
    tree.AddItem(333333);
    tree.AddItem(222222);
    EXPECT_EQ(tree.FindItem(444444), true);
    EXPECT_EQ(tree.FindItem(333333), true);
    EXPECT_EQ(tree.FindItem(222222), true);
    EXPECT_EQ(tree.FindItem(111111), false);
}

TEST(FindItemTest, HandlesLeftRight) {
    Collections::Tree<int> tree;
    tree.AddItem(123456789);
    tree.AddItem(1234567);
    tree.AddItem(12345678);
    EXPECT_EQ(tree.FindItem(123456789), true);
    EXPECT_EQ(tree.FindItem(1234567), true);
    EXPECT_EQ(tree.FindItem(12345678), true);
    EXPECT_EQ(tree.FindItem(987654), false);
}

TEST(FindItemTest, HandlesRightLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(1);
    tree.AddItem(3);
    tree.AddItem(2);
    EXPECT_EQ(tree.FindItem(1), true);
    EXPECT_EQ(tree.FindItem(3), true);
    EXPECT_EQ(tree.FindItem(2), true);
    EXPECT_EQ(tree.FindItem(55), false);
}

TEST(FindItemTest, HandlesRightRight) {
    Collections::Tree<int> tree;
    tree.AddItem(333);
    tree.AddItem(555);
    tree.AddItem(777);
    EXPECT_EQ(tree.FindItem(333), true);
    EXPECT_EQ(tree.FindItem(555), true);
    EXPECT_EQ(tree.FindItem(777), true);
    EXPECT_EQ(tree.FindItem(123), false);
}

//============================================================================//
// Unit tests for Tree::RemoveItem()
//============================================================================//
TEST(RemoveItemTest, HandlesEmptyTree) {
    Collections::Tree<int> tree;
    EXPECT_EQ(tree.RemoveItem(INT_MIN), false);
    EXPECT_EQ(tree.RemoveItem(INT_MIN + 1), false);
    EXPECT_EQ(tree.RemoveItem(-1), false);
    EXPECT_EQ(tree.RemoveItem(0), false);
    EXPECT_EQ(tree.RemoveItem(1), false);
    EXPECT_EQ(tree.RemoveItem(INT_MAX - 1), false);
    EXPECT_EQ(tree.RemoveItem(INT_MAX), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(7);
    tree.AddItem(5);
    EXPECT_EQ(tree.RemoveItem(7), true);
    EXPECT_EQ(tree.RemoveItem(5), true);
    EXPECT_EQ(tree.RemoveItem(42), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesRight) {
    Collections::Tree<int> tree;
    tree.AddItem(888);
    tree.AddItem(999);
    EXPECT_EQ(tree.RemoveItem(888), true);
    EXPECT_EQ(tree.RemoveItem(999), true);
    EXPECT_EQ(tree.RemoveItem(333), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesLeftLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(444444);
    tree.AddItem(333333);
    tree.AddItem(222222);
    EXPECT_EQ(tree.RemoveItem(444444), true);
    EXPECT_EQ(tree.RemoveItem(333333), true);
    EXPECT_EQ(tree.RemoveItem(222222), true);
    EXPECT_EQ(tree.RemoveItem(111111), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesLeftRight) {
    Collections::Tree<int> tree;
    tree.AddItem(123456789);
    tree.AddItem(1234567);
    tree.AddItem(12345678);
    EXPECT_EQ(tree.RemoveItem(123456789), true);
    EXPECT_EQ(tree.RemoveItem(1234567), true);
    EXPECT_EQ(tree.RemoveItem(12345678), true);
    EXPECT_EQ(tree.RemoveItem(987654), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesRightLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(1);
    tree.AddItem(3);
    tree.AddItem(2);
    EXPECT_EQ(tree.RemoveItem(1), true);
    EXPECT_EQ(tree.RemoveItem(3), true);
    EXPECT_EQ(tree.RemoveItem(2), true);
    EXPECT_EQ(tree.RemoveItem(55), false);
    EXPECT_EQ(tree.Head(), nullptr);
}

TEST(RemoveItemTest, HandlesRightRight) {
    Collections::Tree<int> tree;
    tree.AddItem(333);
    tree.AddItem(555);
    tree.AddItem(777);
    EXPECT_EQ(tree.RemoveItem(333), true);
    EXPECT_EQ(tree.RemoveItem(555), true);
    EXPECT_EQ(tree.RemoveItem(777), true);
    EXPECT_EQ(tree.RemoveItem(123), false);
    EXPECT_EQ(tree.Head(), nullptr);
}
}
