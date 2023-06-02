// Question:
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

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

TreeNode* markParent(TreeNode *root, map<TreeNode *, TreeNode *> &parent, int start){
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *startNode;
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        
        // since 'start' is an integer value, we need to traverse the tree inorder to get its pointerreference. Instead of performing a different traversal for that, we directly check it while mappingthe parents of each node. Thus saving the time.
        if(node->val == start) startNode = node;

        if(node->left){
            parent[node->left] = node;
            q.push(node->left);
        }
        
        if(node->right){
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    return startNode;
}

int amountOfTime(TreeNode* root, int start) {
    map<TreeNode *, TreeNode *> parent;
    TreeNode *startNode = markParent(root, parent, start);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(startNode);
    visited[startNode] = true;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        int doesItBurns = 0;
        for(int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                visited[node->left] = true;
                q.push(node->left);
                doesItBurns = 1;
            }

            if(node->right && !visited[node->right]){
                visited[node->right] = true;
                q.push(node->right);
                doesItBurns = 1;
            }

            TreeNode* parentNode = parent[node];
            if(parentNode && !visited[parentNode]){
                visited[parentNode] = true;
                q.push(parentNode);
                doesItBurns = 1;
            }
        }
        if(doesItBurns) time++;
    }
    return time;
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

    amountOfTime(root, 6);

    return 0;
}