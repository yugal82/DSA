#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};

void display(Node* root){
    if(root == NULL)
        return;
    
    display(root->left);
    cout<<" "<<root->val;
    display(root->right);
}

int main(){
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);

    display(root);

    return 0;
}
