// Question:
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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

int findPosition(vector<int> inorder, int val){
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

TreeNode* helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
    
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    int inorderRoot = findPosition(inorder, root->val);
    int nodesLeft = inorderRoot - inStart;

    root->left = helper(preorder, preStart+1, preStart+nodesLeft, inorder, inStart, inorderRoot-1);
    root->right = helper(preorder, preStart+nodesLeft+1, preEnd, inorder, inorderRoot+1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode *root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    return root;
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    buildTree(preorder, inorder);
    return 0;
}