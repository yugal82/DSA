// QUESTION:
// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

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

// Approach 1:
// TC: O(N^2)
int diameter = 0;
int maxDepth(TreeNode* root){
    if(root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree1(TreeNode* root) {
    if(root == NULL)
        return 0;

    int leftSub = maxDepth(root->left);
    int rightSub = maxDepth(root->right);

    diameter = max(diameter, leftSub + rightSub);

    diameterOfBinaryTree1(root->left);
    diameterOfBinaryTree1(root->right);

    return diameter;
}

// Approach 2:
// TC: O(N)
int maxDepth(TreeNode *root, int &diameter){
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left, diameter);
    int right = maxDepth(root->right, diameter);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree2(TreeNode *root){
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
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

    int depth = diameterOfBinaryTree2(root);
    cout << "The max depth is: " << depth;

    return 0;
}