#ifndef TREE_HPP
#define TREE_HPP
#include "treeNode.hpp"
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// A binary search tree.
/// The constructor creates an empty tree.
/// After construction, use public methods to mutate the tree.
/// The deconstructor must deallocate all nodes.
////////////////////////////////////////////////////////////////////////////////
template <class T> class Tree {
    public: //Aliases and typedefs.
        template <class ctx> using TraversalFuncPtr = void (*) (TreeNode<T>* node, ctx& context);

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
        template <class ctx> void ExecFuncOnNodesInOrder(TraversalFuncPtr<ctx> funcPtr, ctx& context);

    public: //Retrieval methods.
        bool FindItem(T item);
        bool FindItem(T item) const;

    private: //Binary search tree helper methods.
        TreeNode<T>* newNode(T newItem, TreeNode<T>* recursionPointer);
        bool search(T item, TreeNode<T>* recursionPointer, TreeNode<T>** out = nullptr);
        TreeNode<T>* remove(T item, TreeNode<T>* recursionPointer);
        TreeNode<T>* getSuccessorOfRemovedNode(TreeNode<T>* recursionPointer);
        template <class ctx> void execFuncOnNodesInOrder(TraversalFuncPtr<ctx> funcPtr, ctx& context, TreeNode<T>* recursionPointer);
};
}
#endif
