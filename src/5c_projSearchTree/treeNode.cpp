#include "treeNode.hpp"
namespace Collections {

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructor that initializes node data and nullptr node links.
////////////////////////////////////////////////////////////////////////////////
template <class T> TreeNode<T>::TreeNode(T newdata) {
    data = newdata;
    left = nullptr;
    right = nullptr;
}
}
