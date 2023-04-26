// QUESTION:
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<limits.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

int findMaxPathSum(TreeNode *root, int &maxSum){
    if (root == NULL)
        return 0;

    int leftSum = max(0, findMaxPathSum(root->left, maxSum));
    int rightSum = max(0, findMaxPathSum(root->right, maxSum));

    maxSum = max(maxSum, (root->val + leftSum + rightSum));

    return (root->val + max(leftSum, rightSum));
}

int maxPathSum(TreeNode *root){
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
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

    int depth = maxPathSum(root);
    cout << "The max depth is: " << depth;

    return 0;
}
