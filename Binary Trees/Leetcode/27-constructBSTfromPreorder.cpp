// Question:
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

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

TreeNode* buildBST(vector<int> preorder, int &ps, int lowerRange, int upperRange){
    if(ps == preorder.size()) return NULL;

    if(lowerRange > preorder[ps] || upperRange < preorder[ps]) return NULL;

    TreeNode *root = new TreeNode(preorder[ps++]);
    
    root->left = buildBST(preorder, ps, lowerRange, root->val);
    root->right = buildBST(preorder, ps, root->val, upperRange);
    
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int lowerRange = 0;
    int upperRange = 1001;
    int ps = 0;
    return buildBST(preorder, ps, lowerRange, upperRange);
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};
    bstFromPreorder(preorder);
    return 0;
}