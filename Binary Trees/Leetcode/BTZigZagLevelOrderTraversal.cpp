// Question:
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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

vector<vector<int>> zigzagLevelOrder(TreeNode *root){
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;
    // false says your direction of traversal is from left to right
    // true says your direction of traversal is from right to left
    while (!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);

            temp.push_back(node->val);
        }
        if (flag)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        flag = !flag;
    }

    // int j = 1;
    // while(j < ans.size()){
    //     reverse(ans[j].begin(), ans[j].end());
    //     j += 2;
    // }

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

    zigzagLevelOrder(root);

    return 0;
}