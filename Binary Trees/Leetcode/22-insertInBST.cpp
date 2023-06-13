// Question:
// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

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


TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode *node = new TreeNode(val);
    if(root == NULL){
        root = node;
        return root;
    }
    // Iterative Solution
    // TreeNode *curr = root;
    // TreeNode *follow = NULL;
    // while(curr){
    //     follow = curr;
    //     if(val > curr->val)
    //         curr = curr->right;
    //     else
    //         curr = curr->left;
    // }
    // if(val > follow->val)
    //     follow->right = node;
    // else
    //     follow->left = node;
    // return root;
    
    // Recursive
    if(val > root->val)
        root->right = insertIntoBST(root->right, val);
    else
        root->left = insertIntoBST(root->left, val);
    
    return root;
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    insertIntoBST(root, 10);

    return 0;
}