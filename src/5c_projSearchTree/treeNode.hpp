#ifndef TREENODE_HPP
#define TREENODE_HPP
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// A node in a binary search tree.
/// The Data is initialized in the constructor and is constant.
////////////////////////////////////////////////////////////////////////////////
template <class T> class TreeNode {
    private: //Encapsulated properties.
        TreeNode<T>* left;
        TreeNode<T>* right;
        T data;

    public: //Constructors and destructors.
        TreeNode(T newdata);

    public: //Getters of encapsulated properties. Read-only if TreeNode is const.
        T& Data() {return data;}
        T const& Data() const {return data;}
        TreeNode<T>*& Left() {return left;}
        TreeNode<T>*& Right() {return right;}
        TreeNode<T> const* const& Left() const {return left;}
        TreeNode<T> const* const& Right() const {return right;}
};
}
#endif
