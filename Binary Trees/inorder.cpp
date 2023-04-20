#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    inorder(root);

    return 0;
}