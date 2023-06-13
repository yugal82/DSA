// Question:
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    lowestCommonAncestor(root, root, root);
    return 0;
}