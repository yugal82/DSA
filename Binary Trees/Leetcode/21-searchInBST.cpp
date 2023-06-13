// Question:
// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

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


TreeNode *searchBST(TreeNode *root, int val){
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    searchBST(root, 10);

    return 0;
}