#include <string>
#include <gtest/gtest.h>
#include "treeNode.cpp"
#include "tree.cpp"
namespace TestTree {

//============================================================================//
// Unit tests for Tree::AddItem()
//============================================================================//
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

//============================================================================//
// Unit tests for Tree::FindItem()
//============================================================================//
TEST(FindItemTest, HandlesLeft) {
    Collections::Tree<int> tree;
    tree.AddItem(7);
    tree.AddItem(5);
    EXPECT_EQ(tree.FindItem(7), true);
    EXPECT_EQ(tree.FindItem(5), true);
    EXPECT_EQ(tree.FindItem(42), false);
}
}
