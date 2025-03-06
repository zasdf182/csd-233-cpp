#include "tree.hpp"
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// Constructor that initializes an empty tree.
////////////////////////////////////////////////////////////////////////////////
template <class T> Tree<T>::Tree() {
    head = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
/// Destructor that deallocates all nodes in the tree.
////////////////////////////////////////////////////////////////////////////////
template <class T> Tree<T>::~Tree() {
    // todo
}

////////////////////////////////////////////////////////////////////////////////
/// Create a new node containing item.
/// Add it to this tree, in sorted position.
/// If a node containing the item already exists, does nothing.
////////////////////////////////////////////////////////////////////////////////
template <class T> void Tree<T>::AddItem(T item) {
    head = newNode(item, head);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns true if item is in tree, and false if not.
////////////////////////////////////////////////////////////////////////////////
template <class T> bool Tree<T>::FindItem(T item) {
    return search(item, head);
}

////////////////////////////////////////////////////////////////////////////////
/// If item is in tree, returns true, and removes the item.
/// If not, returns false, and does nothing.
////////////////////////////////////////////////////////////////////////////////
template <class T> bool Tree<T>::RemoveItem(T item) {
    bool found = search(item, head);
    if (!found) return false;
    head = remove(item, head);
    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// Private recursive helper method for adding new nodes.
/// To use: tree.head = newNode(item, head);
////////////////////////////////////////////////////////////////////////////////
template <class T> TreeNode<T>* Tree<T>::newNode(T item, TreeNode<T>* recursionPointer) {
    if (recursionPointer == nullptr)
        return new TreeNode<T>(item);
    if (item == recursionPointer->Data())
        return recursionPointer;
    if (item < recursionPointer->Data())
        recursionPointer->Left() = newNode(item, recursionPointer->Left());
    else //if (item > recursionPointer->Data())
        recursionPointer->Right() = newNode(item, recursionPointer->Right());
    return recursionPointer;
}

////////////////////////////////////////////////////////////////////////////////
/// Private recursive helper method for searching for nodes.
/// If not found, returns false, and sets *out to nullptr;
/// If found, returns true, and sets *out to the node.
/// @param recursionPointer Pass tree.head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T> bool Tree<T>::search(T item, TreeNode<T>* recursionPointer, TreeNode<T>** out) {
    if (recursionPointer == nullptr) {
        if (out != nullptr)
            *out = nullptr;
        return false;
    }
    if (item == recursionPointer->Data()) {
        if (out != nullptr)
            *out = recursionPointer;
        return true;
    }
    if (item < recursionPointer->Data())
        return search(item, recursionPointer->Left(), out);
    else //if (item > recursionPointer->Data())
        return search(item, recursionPointer->Right(), out);
}

////////////////////////////////////////////////////////////////////////////////
/// Private recursive helper method for deleting nodes.
/// Returns modified head of the binary search tree (if it is modified).
/// To use: head = remove(item, head);
////////////////////////////////////////////////////////////////////////////////
template <class T> TreeNode<T>* Tree<T>::remove(T item, TreeNode<T>* recursionPointer) {
    if (recursionPointer == nullptr)
        return recursionPointer;

    // If item is in a subtree
    if (item < recursionPointer->Data())
        recursionPointer->Left() = remove(item, recursionPointer->Left());
    else if (item > recursionPointer->Data())
        recursionPointer->Right() = remove(item, recursionPointer->Right());

    // If item is on this node, delete node and relink other nodes
    else { //if (item == recursionPointer->Data())

        // If no children or only right child is present
        if (recursionPointer->Left() == nullptr) {
            TreeNode<T>* newRoot = recursionPointer->Right();
            delete recursionPointer;
            return newRoot;
        }

        // If only left child is present
        if (recursionPointer->Right() == nullptr) {
            TreeNode<T>* newRoot = recursionPointer->Left();
            delete recursionPointer;
            return newRoot;
        }

        // If both children are present
        TreeNode<T>* successor = getSuccessorOfRemovedNode(recursionPointer);
        recursionPointer->Data() = successor->Data();
        recursionPointer->Right() = remove(successor->Data(), recursionPointer->Right());
    }
    return recursionPointer;
}

////////////////////////////////////////////////////////////////////////////////
/// Private recursive helper method for finding the successor of a deleted node.
////////////////////////////////////////////////////////////////////////////////
template <class T> TreeNode<T>* Tree<T>::getSuccessorOfRemovedNode(TreeNode<T>* recursionPointer) {
    recursionPointer = recursionPointer->Right();
    while (recursionPointer != nullptr && recursionPointer->Left() != nullptr)
        recursionPointer = recursionPointer->Left();
    return recursionPointer;
}
}
