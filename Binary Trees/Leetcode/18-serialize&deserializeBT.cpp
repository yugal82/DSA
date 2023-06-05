// Question:
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.


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

// Encodes a tree to a single string.
string serialize(TreeNode *root){
    string s = "";
    if (root == NULL)
        return s;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
            s.append("#,");
        else
            s.append(to_string(node->val) + ',');
        if (node != NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }

    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data){
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#"){
            node->left = NULL;
        }
        else{
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#"){
            node->right = NULL;
        }
        else{
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}