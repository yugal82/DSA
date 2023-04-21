// QUESTION:
// Given a binary tree, determine if it is height-balanced

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

// APPROACH 1: Find the height/depth of the left subtree and right subtree and check if absolute difference is greater than 1, if yes return false. CHECK THIS FOR EACH NODE. THATS WHY THE RECURSIVE CALLS FOR isBalanced() recursive calls are made for each node.
// TC: O(N^2)
int maxDepth(TreeNode *root){
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root){
    if (root == NULL)
        return true;

    int leftSubTree = maxDepth(root->left);
    int rightSubTree = maxDepth(root->right);

    if (abs(leftSubTree - rightSubTree) > 1)
        return false;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if (left == true && right == true)
        return true;
    return false;
}
// -----------------------------------------------------------------------------------

// APPROACH 2: We directly check whether the difference of height of the left subtree and right subtree is less than 1, if yes we then return directly the height of the tree, if no then we return -1. If we return -1, then the tree is not balanced BT.
// TC: O(N);
int depth(TreeNode *root){
    if (root == NULL)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if (left == -1 || right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root){
    return depth(root) != -1;
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

    int depth = maxDepth(root);
    cout << "The max depth is: " << depth;

    return 0;
}
