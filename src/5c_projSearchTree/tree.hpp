#include "treeNode.hpp"
#ifndef TREE_HPP
#define TREE_HPP
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// A binary search tree.
/// The default constructor has no parameters and does nothing.
/// After construction, use public methods to add and remove nodes.
/// The deconstructor must deallocate all nodes.
////////////////////////////////////////////////////////////////////////////////
template <class T> class Tree {
    private: //Encapsulated read-only variables.
        TreeNode<T>* head;

    public: //Constructors and destructors.
        Tree();
        ~Tree();

    public: //Getters of read-only variables.
        TreeNode<T> const& Head() {return *head;}
        T const DataValue() {return head->DataValue();}
        T const& DataRef() {return head->DataRef();}

    public: //Public methods.
        void AddItem (T item);
        bool FindItem (T item);
        Bool RemoveItem (T item);
};
}
#endif
