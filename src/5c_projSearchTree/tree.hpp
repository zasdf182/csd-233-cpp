#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "treeNode.hpp"
namespace Collections {




////////////////////////////////////////////////////////////////////////////////
/// @brief A pointer to a function that manipulates nodes during tree traversals.
/// @tparam ctx An optional object used to pass data in/out of the function.
////////////////////////////////////////////////////////////////////////////////
template <class T, class ctx>
using NodeAction = void (*) (TreeNode<T>* node, ctx& context);




////////////////////////////////////////////////////////////////////////////////
/// @brief A binary search tree.
/// The constructor creates an empty tree.
/// After construction, use public methods to mutate the tree.
/// The deconstructor must deallocate all nodes.
////////////////////////////////////////////////////////////////////////////////
template <class T> class Tree {
    private: //Encapsulated read-only properties.
        TreeNode<T>* head;

    public: //Getters of read-only properties.
        TreeNode<T> const* Head() {return head;}
        TreeNode<T> const* Head() const {return head;}

    public: //Constructors and destructors.
        Tree();
        ~Tree();

    public: //Mutation methods. Unavailable to const Trees.
        void AddItem(T item);
        bool RemoveItem(T item);
        template <class ctx> void ExecFuncOnNodesInOrder(NodeAction<T, ctx> funcPtr, ctx& context);
        template <class ctx> void ExecFuncOnNodesPreOrder(NodeAction<T, ctx> funcPtr, ctx& context);
        template <class ctx> void ExecFuncOnNodesPostOrder(NodeAction<T, ctx> funcPtr, ctx& context);

    public: //Retrieval methods.
        bool FindItem(T item);
        bool FindItem(T item) const;

    private: //Binary search tree helper methods.
        TreeNode<T>* newNode(T newItem, TreeNode<T>* recursionPointer);
        TreeNode<T>* remove(T item, TreeNode<T>* recursionPointer);
        TreeNode<T>* getSuccessor(TreeNode<T>* recursionPointer);
        bool search(T item, TreeNode<T>* recursionPointer, TreeNode<T>** out = nullptr);
        template <class ctx> void execFuncOnNodesInOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer);
        template <class ctx> void execFuncOnNodesPreOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer);
        template <class ctx> void execFuncOnNodesPostOrder(NodeAction<T, ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer);
};
}
#endif
