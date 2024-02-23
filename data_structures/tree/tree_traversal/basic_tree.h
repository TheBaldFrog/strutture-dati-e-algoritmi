#pragma once

#include "stackDLL.h"
#include <iostream>

template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(const T &data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

template <typename T>
void preorderTraversal(const TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    std::cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

template <typename T>
void inorderTraversal(const TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << "->";
    inorderTraversal(node->right);
}

template <typename T>
void postorderTraversal(const TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << "->";
}