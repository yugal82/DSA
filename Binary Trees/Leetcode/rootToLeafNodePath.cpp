#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

bool getPath(TreeNode *root, vector<int> &path, int x){
    if(root == NULL) return false;

    path.push_back(root->val);

    if(getPath(root->left, path, x) || getPath(root->right, path, x))
        return true;
    
    path.pop_back();
    return false;
}

vector<int> rootToLeafNodePath(TreeNode *root, int x){
    vector<int> path;
    getPath(root, path, x);
    return path;
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

    rootToLeafNodePath(root, 10);

    return 0;
}