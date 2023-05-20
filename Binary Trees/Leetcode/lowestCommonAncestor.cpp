// Question:
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

// Approach 1:
// Brute Force:
// bool getPath(TreeNode *root, vector<TreeNode *> &path, int x){
//     if(root == NULL) return false;
//     path.push_back(root);
//     if(root->val == x) return true;
//     if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true;
//     path.pop_back();
//     return false;
// }

// TreeNode *findIntersection(vector<TreeNode *> p, vector<TreeNode *> q){
//     for(int i = p.size()-1; i >= 0; i--){
//         for(int j = q.size()-1; j >= 0; j--){
//             if(p[i]->val == q[j]->val)
//                 return p[i];
//         }
//     }
//     return NULL;
// }

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     vector<TreeNode *> pathToQ, pathToP;
//     getPath(root, pathToP, p->val);
//     getPath(root, pathToQ, q->val);
//     return findIntersection(pathToP, pathToQ);
// }

// Approach 2:
// Optimized Approach:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
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

    TreeNode *p = new TreeNode(8);
    TreeNode *q = new TreeNode(10);

    lowestCommonAncestor(root, p, q);

    return 0;
}