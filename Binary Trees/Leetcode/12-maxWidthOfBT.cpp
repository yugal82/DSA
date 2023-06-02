// Question:
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

int widthOfBinaryTree(TreeNode *root){
    if (root == NULL)
        return 0;
    int maxWidth = 0;

    // we take a queue of pair inorder to store the node and its respective index
    queue<pair<TreeNode *, unsigned long long int>> q;
    q.push({root, 1});
    while (!q.empty()){
        int size = q.size();
        auto first = q.front();
        auto last = q.back();
        int diff = last.second - first.second;

        if (maxWidth < (diff + 1))
            maxWidth = diff + 1;
        // maxWidth = max(maxWidth, diff + 1);

        for (int i = 0; i < size; i++){
            auto pair = q.front();
            q.pop();

            TreeNode *node = pair.first;

            if (node->left != NULL){
                // since the left child of the parent will always have index = parentIndex * 2
                q.push({node->left, (pair.second - 1) * 2});
                // q.push({ node->left, pair.second * 2 });
            }

            if (node->right != NULL){
                // since the right child of the parent will always have index = parentIndex * 2 + 1
                q.push({node->right, (pair.second - 1) * 2 + 1});
                // q.push({ node->right, pair.second * 2 + 1 });
            }
        }
    }

    return maxWidth;
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

    widthOfBinaryTree(root);

    return 0;
}