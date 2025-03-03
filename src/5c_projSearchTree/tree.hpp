#include "treeNode.hpp"
#ifndef TREE_HPP
#define TREE_HPP
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// A binary search tree.
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

    public: //Retrieval methods.
        const bool FindItem(T item);
        const bool FindItem(T item) const;
        const bool RemoveItem(T item);
        const bool RemoveItem(T item) const;

    private: //Binary search tree helper methods.
        TreeNode<T>* newNode(T newItem, TreeNode<T>* recursionPointer);
        bool search(T item, TreeNode<T>* recursionPointer, TreeNode<T>** out = nullptr);
        TreeNode<T>* remove(T item, TreeNode<T>* recursionPointer);
        TreeNode<T>* getParentOfRemovedNode(TreeNode<T>* recursionPointer);
};
}
#endif
