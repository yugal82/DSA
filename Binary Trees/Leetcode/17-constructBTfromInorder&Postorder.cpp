// Question:
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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

int findPosition(vector<int> &inorder, int val){
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == val)
            return i;
    }

    return -1;
}

TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int postStart, int postEnd, int inStart, int inEnd){
    
    if(postStart > postEnd || inStart > inEnd ) return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);
    int pos = findPosition(inorder, root->val);
    int nodesLeft = pos - inStart;

    root->left = helper(inorder, postorder, postStart, postStart + nodesLeft - 1, inStart, pos-1);
    root->right = helper(inorder, postorder, postStart + nodesLeft, postEnd-1, pos+1, inEnd);
    
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode *root = helper(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
    
    return root;
}

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};

    buildTree(inorder, postorder);
    return 0;
}