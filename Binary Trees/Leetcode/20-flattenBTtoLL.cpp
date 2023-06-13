// Question:
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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


// SOLUTION 1:
// void preOrder(TreeNode *root, vector<TreeNode *> &preorder){
//     if(root == NULL) return;

//     preorder.push_back(root);
//     preOrder(root->left, preorder);
//     preOrder(root->right, preorder);

// }
// void flatten(TreeNode* root) {
//     vector<TreeNode *> preorder;
//     preOrder(root, preorder);

//     for(int i = 1; i < preorder.size(); i++){
//         preorder[i-1]->right = preorder[i];
//         preorder[i-1]->left = NULL;
//     }
// }

// SOLUTION 2:
// TreeNode *prev = NULL;
// void flatten(TreeNode *root){

//     if(root == NULL) return;

//     flatten(root->right);
//     flatten(root->left);

//     root->right = prev;
//     root->left = NULL;
//     prev = root;
// }

// SOLUTION 3: MORRIS TRAVERSAL
void flatten(TreeNode *root){
    TreeNode *curr = root;

    while (curr != NULL){
        if (curr->left){
            TreeNode *node = curr->left;
            while (node->right){
                node = node->right;
            }

            node->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
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

    flatten(root);

    return 0;
}