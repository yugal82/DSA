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

void solve(TreeNode *root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);

    solve(root->right, level+1, ans);
    solve(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    
    // ITERATIVE SOLUTION:
    // vector<int> ans;
    // if(root == NULL) return ans;
    // queue<TreeNode *> q;
    // q.push(root);
    // while(!q.empty()){
    //     int size = q.size();
    //     for(int i = 0; i < size; i++){
    //         TreeNode *node = q.front();
    //         q.pop();
    //         if(i == size - 1) ans.push_back(node->val);
    //         if(node->left != NULL)
    //             q.push(node->left);
            
    //         if(node->right != NULL)
    //             q.push(node->right);
    //     }
    // }
    // return ans;


    // RECURSIVE SOLUTION:
    vector<int> ans;
    if(root == NULL) return ans;
    solve(root, 0, ans);
    return ans; 
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

    rightSideView(root);

    return 0;
}