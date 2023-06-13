// Question
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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

// void inorder(TreeNode *root, vector<int> &treeVal){
//     if(root == NULL) return;

//     inorder(root->left, treeVal);
//     treeVal.push_back(root->val);
//     inorder(root->right, treeVal);

// }

// int kthSmallest(TreeNode* root, int k) {
//     vector<int> treeVal;
//     inorder(root, treeVal);
//     return treeVal[k-1];
// }

int ans;
void inorder(TreeNode *root, int &count, int k){
    if (root == NULL)
        return;

    inorder(root->left, count, k);
    count++;
    if (count == k){
        ans = root->val;
        return;
    }
    inorder(root->right, count, k);
}

int kthSmallest(TreeNode *root, int k){
    int count = 0;
    inorder(root, count, k);
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    kthSmallest(root, 2);

    return 0;
}