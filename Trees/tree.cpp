#include <iostream>
#include <conio.h>
#include <stdlib.h>
// #define NULL 0

using namespace std;

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

// struct Node * root = NULL;

struct Node *newNode(int val){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;

    return node;
}

void display(struct Node *root){
    if(root == NULL)
        return;
    
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int main(){
    struct Node *root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(5);
    root->left->right = newNode(12);
    root->right->right = newNode(2);
    root->right->left = newNode(7);

    display(root);
    return 0;
}

