// QUESTION:
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

bool traverse(TreeNode *left, TreeNode *right){
    if (left == NULL && right == NULL)
        return true;
    else if (left == NULL || right == NULL || left->val != right->val)
        return false;
    else
        return traverse(left->left, right->right) && traverse(left->right, right->left);
}

bool isSymmetric(TreeNode *root){
    if (!root || (root->right == NULL && root->left == NULL))
        return true;
    return traverse(root->left, root->right);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    int depth = isSymmetric(root);

    return 0;
}