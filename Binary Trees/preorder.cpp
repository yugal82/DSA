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

void preorder(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
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

    preorder(root);

    return 0;
}