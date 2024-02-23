#include <iostream>
#include "basic_tree.h"

int main()
{
    TreeNode<int> *root = new TreeNode(1);
    root->left = new TreeNode(12);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);

    inorderTraversal(root);
    std::cout << '\n';
    preorderTraversal(root);
}