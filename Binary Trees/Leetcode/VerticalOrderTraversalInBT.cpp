// Question:
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

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

vector<vector<int>> verticalTraversal(TreeNode *root){
    map<int, map<int, multiset<int>>> nodes;
    // this map DS is used to store node->val according to the level and the vertical index.

    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode *node = p.first;
        // x is the vertical index
        int x = p.second.first;

        // y is the level of that node
        int y = p.second.second;

        // we insert the node->val in the set according to the level and vertical index.
        // the below statement means: nodes ke 'x' vertical index ke 'y' level ke andar node->val insert karo.
        nodes[x][y].insert(node->val);

        // whenever we go left, the vertical index decrements by 1
        if (node->left != NULL)
            q.push({node->left, {x - 1, y + 1}});

        // whenever we go right, the vertical index increments by 1
        if (node->right != NULL)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (auto p : nodes){
        vector<int> temp;
        for (auto s : p.second){
            temp.insert(temp.end(), s.second.begin(), s.second.end());
        }
        ans.push_back(temp);
    }

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

    verticalTraversal(root);

    return 0;
}