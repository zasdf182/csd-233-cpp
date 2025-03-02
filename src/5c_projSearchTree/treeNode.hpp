#ifndef TREENODE_HPP
#define TREENODE_HPP
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// A node in a binary search tree.
/// The node must be linked to a Tree in the constructor.
/// The data must be initialized in the constructor.
/// Once constructed, all members are constant.
/// Instead of editing nodes in a Tree, delete nodes and create new ones.
/// Nodes in a Tree are unlinked and deallocated in the node deconstructor.
/// Broken Tree links are automatically fixed in the node deconstructor.
////////////////////////////////////////////////////////////////////////////////
template <class T> class TreeNode {
    private: //Encapsulated read-only constants.
        TreeNode<T> const* parent;
        TreeNode<T> const* left;
        TreeNode<T> const* right;
        T const* data;

    public: //Constructors and destructors.
        TreeNode(T data, Tree tree);
        ~TreeNode();

    public: //Getters of read-only constants.
        TreeNode<T> const& Parent() {return *parent;}
        TreeNode<T> const& Left() {return *left;}
        TreeNode<T> const& Right() {return *right;}
        T const DataValue() {return *data;}
        T const& DataRef() {return *data;}
};
}
#endif
