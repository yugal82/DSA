// Question:
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

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

// Failed code
// TreeNode* deleteNode(TreeNode* root, int key) {

//     TreeNode *curr = root;
//     TreeNode *follow = NULL;
//     while(curr != NULL){
//         if(curr->val == key)
//             break;

//         follow = curr;
//         if(curr->val < key)
//             curr = curr->right;
//         else
//             curr = curr->left;
//     }

//     // if the node to be deleted is not present
//     if(curr == NULL) return root;

//     // if the node to be deleted is root and there are no other nodes other than root
//     if(curr->right == NULL && curr->left == NULL){
//         delete(curr);
//         return NULL;
//     }

//     // if the node to be deleted is root
//     if(curr == root){
//         root = curr->right;
//         root->left = curr->left;
//         delete(curr);
//         return root;
//     }

//     // if the node to be deleted is a normal node in the BST
//     TreeNode *left = curr->left;
//     TreeNode *right = curr->right;

//     if(follow->left == curr){
//         follow->left = right;
//         while(right->left)
//             right = right->left;

//         right->left = left;
//     }
//     else{
//         follow->right = left;
//         while(left->right)
//             left = left->right;

//         left->right = right;
//     }

//     delete(curr);
//     return root;
// }

TreeNode *findLastRightChild(TreeNode *root){
    while (root->right)
        root = root->right;

    return root;
}

TreeNode *helper(TreeNode *root){
    
    if (root->left == NULL){
        return root->right;
    }
    else if (root->right == NULL){
        return root->left;
    }

    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRightChild(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key){
    if (root == NULL)
        return root;

    if (root->val == key){
        return helper(root);
    }

    TreeNode *curr = root;
    while (curr != NULL){

        if (curr->val > key){
            if (curr->left != NULL && curr->left->val == key){
                curr->left = helper(curr->left);
                break;
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if (curr->right != NULL && curr->right->val == key){
                curr->right = helper(curr->right);
                break;
            }
            else
                curr = curr->right;
        }
    }

    return root;
}

int main(){
    TreeNode *root = new TreeNode(1);
    // make a BST according to the rules of BST

    deleteNode(root, 10);

    return 0;
}