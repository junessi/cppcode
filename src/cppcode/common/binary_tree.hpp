#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#include <iostream>
#include <vector>
#include <cstdint>

namespace cppcode { namespace common { namespace binary_tree {

template <typename T>
struct Node
{
    Node(T value, Node<T>* l, Node<T>* r)
        : value{std::move(value)}
        , left{l}
        , right{r}
    {}

    T value;
    Node<T>* left;
    Node<T>* right;
};

template <typename T, typename V>
void preorder(const Node<T>* node, const V& visit)
{
    if (nullptr == node)
    {
        return;
    }

    visit(node);

    if (node->left)
    {
        preorder(node->left, visit);
    }

    if (node->right)
    {
        preorder(node->right, visit);
    }
}

}}}

#endif
