// Question:
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

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

void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTracker){
    // the parentTracker stores the parent of the child. i.e the unordered_map will store the child as key and parent as value.
    // parentTracker[child] = parent;
    // in technical terms, the parent of the node->left and node->right is node

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        if (node->left != NULL){
            // the parent of node-left is node
            parentTracker[node->left] = node;
            q.push(node->left);
        }

        if (node->right != NULL){
            // the parent of node->right is node
            parentTracker[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k){
    unordered_map<TreeNode *, TreeNode *> parentTracker;
    markParent(root, parentTracker);
    // the markParent functions marks the parent of each node in the map inorder for us to traverse upwards as in conventional traversing techniques, it is not possible to traverse updwards.

    // now we declare another hashmap to keep track of the visited node
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int dist = 0;

    // this BFS traversal is to traverse from the target node to the nodes which are at distance k
    // we start the queue with target node first.
    while (!q.empty()){
        int size = q.size();
        if (dist == k)
            break;
        dist++;
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();

            // traverse downwards to target's left child and check beforehand whether it is already visited
            if (node->left != NULL && !visited[node->left]){
                visited[node->left] = true;
                q.push(node->left);
            }

            // traverse downwards to target's right child and check beforehand whether it is already visited
            if (node->right != NULL && !visited[node->right]){
                visited[node->right] = true;
                q.push(node->right);
            }

            // now check for parent and traverse upwards towards parent
            TreeNode *parent = parentTracker[node];
            if (parent && !visited[parent]){
                visited[parent] = true;
                q.push(parent);
            }
        }
    }

    vector<int> res;
    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        res.push_back(node->val);
    }

    return res;
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

    TreeNode *target = root->left->right->left;

    distanceK(root, target, 2);

    return 0;
}