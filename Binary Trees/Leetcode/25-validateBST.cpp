// Question:
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include <bits/stdc++.h>
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

 // SOLUTION 1:
// void inorder(TreeNode *root, vector<int> &v){
//     if(root == NULL) return;
//     inorder(root->left, v);
//     v.push_back(root->val);
//     inorder(root->right, v);
// }
// bool isSorted(vector<int> v){
//     for(int i = 1; i < v.size(); i++){
//         if(v[i] <= v[i-1])
//             return false;
//     }
    
//     return true;
// }
// bool isValidBST(TreeNode* root) {
//     vector<int> v;
//     inorder(root, v);
//     return isSorted(v);
// }

// SOLUTION 2:
bool solve(TreeNode *root, long int lowerRange, long int upperRange){
    if(root == NULL) return true;
    if(root->val >= upperRange || root->val <= lowerRange) return false;

    bool left = solve(root->left, lowerRange, root->val);
    if(left == false) return false;
    bool right = solve(root->right, root->val, upperRange);
    
    return left && right;
}

 bool isValidBST(TreeNode* root) {
    long int lowerRange = LONG_MIN;
    long int upperRange = LONG_MAX;

    return solve(root, lowerRange, upperRange);
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    isValidBST(root);
    return 0;
}