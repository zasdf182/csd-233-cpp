#include "tree.hpp"
namespace Collections {








// ##################################################################### //
// ########################### PUBLIC METHODS ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Constructor that initializes an empty tree.
////////////////////////////////////////////////////////////////////////////////
template <class T> Tree<T>::Tree() {
    head = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Destructor that does an in-order traversal and deletes all nodes.
////////////////////////////////////////////////////////////////////////////////
template <class T> Tree<T>::~Tree() {
    int ctx = 0;
    execFuncOnNodesPostOrder<int> ([](TreeNode<T>* node, int& context) {
        delete node;
    }, ctx, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Emplaces a new node containing item, in sorted position.
///        Does nothing if a node containing item is already present.
////////////////////////////////////////////////////////////////////////////////
template <class T>
void Tree<T>::AddItem(T item) {
    head = newNode(item, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief If item is in tree, returns true, and removes the item.
/// If not, returns false, and does nothing.
////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Tree<T>::RemoveItem(T item) {
    bool found = search(item, head);
    if (!found)
        return false;
    else {
        head = remove(item, head);
        return true;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Returns true if item is in tree, and false if not.
////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Tree<T>::FindItem(T item) {
    return search(item, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Returns true if item is in tree, and false if not.
////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Tree<T>::FindItem(T item) const {
    return search(item, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Does an in-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::ExecFuncOnNodesInOrder(NodeAction<T, ctx> funcPtr, ctx& context) {
    execFuncOnNodesInOrder(funcPtr, context, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Does a pre-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::ExecFuncOnNodesPreOrder(NodeAction<T, ctx> funcPtr, ctx& context) {
    execFuncOnNodesPreOrder(funcPtr, context, head);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Does a post-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::ExecFuncOnNodesPostOrder(NodeAction<T, ctx> funcPtr, ctx& context) {
    execFuncOnNodesPostOrder(funcPtr, context, head);
}








// ##################################################################### //
// ########################## PRIVATE METHODS ########################## //
// ##################################################################### //


////////////////////////////////////////////////////////////////////////////////
/// @brief Recursive helper method.
///        Emplaces a new node containing item, in sorted position.
///        If a node containing item is already present, returns that node.
///        Otherwise, returns a newly created node.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
TreeNode<T>* Tree<T>::newNode(T item, TreeNode<T>* recursionPointer) {
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
/// @brief Recursive helper method.
///        Searches for a node containing item.
///        If not found, returns false, and sets *out to nullptr;
///        If found, returns true, and sets *out to the node.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Tree<T>::search(T item, TreeNode<T>* recursionPointer, TreeNode<T>** out) {
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
/// @brief Recursive helper method.
///        Deletes the node containing item, if present.
///        Returns the tree head after any modifications.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
TreeNode<T>* Tree<T>::remove(T item, TreeNode<T>* recursionPointer) {
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
        TreeNode<T>* successor = getSuccessor(recursionPointer);
        recursionPointer->Data() = successor->Data();
        recursionPointer->Right() = remove(successor->Data(), recursionPointer->Right());
    }
    return recursionPointer;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Recursive helper method.
///        Finds the successor of a node.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
TreeNode<T>* Tree<T>::getSuccessor(TreeNode<T>* recursionPointer) {
    recursionPointer = recursionPointer->Right();
    while (recursionPointer != nullptr && recursionPointer->Left() != nullptr)
        recursionPointer = recursionPointer->Left();
    return recursionPointer;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Recursive helper method.
///        Does an in-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::execFuncOnNodesInOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer) {
    if (recursionPointer == nullptr) return;
    execFuncOnNodesInOrder(funcPtr, context, recursionPointer->Left());
    (*funcPtr)(recursionPointer, context);
    execFuncOnNodesInOrder(funcPtr, context, recursionPointer->Right());
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Recursive helper method.
///        Does a pre-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::execFuncOnNodesPreOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer) {
    if (recursionPointer == nullptr) return;
    (*funcPtr)(recursionPointer, context);
    execFuncOnNodesPreOrder(funcPtr, context, recursionPointer->Left());
    execFuncOnNodesPreOrder(funcPtr, context, recursionPointer->Right());
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Recursive helper method.
///        Does a post-order traversal, and executes a function on each node.
/// @param context An optional object for passing data in/out of the function.
/// @param recursionPointer Pass the tree head to this parameter.
////////////////////////////////////////////////////////////////////////////////
template <class T>
template <class ctx>
void Tree<T>::execFuncOnNodesPostOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer) {
    if (recursionPointer == nullptr) return;
    execFuncOnNodesPostOrder(funcPtr, context, recursionPointer->Left());
    execFuncOnNodesPostOrder(funcPtr, context, recursionPointer->Right());
    (*funcPtr)(recursionPointer, context);
}
}
