#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

void insert(int x){
    struct Node *newNode, *current, *follow;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        cout<<"\nMemory full!";
        return;
    }

    newNode->data = x;
    newNode->right = newNode->left = NULL;
    if(root == NULL){
        root = newNode;
    }
    else{
        current = root;
        follow = NULL;
        while(current != NULL){
            follow = current;
            if(newNode->data > current->data )
                current = current->right;
            else
                current = current->left;
        }
        
        if(newNode->data > follow->data)
            follow->right = newNode;
        else
            follow->left = newNode;  
    }
}

void create(){
    int x,i,n;
    cout<<"\nEnter the number of nodes you want to insert: ";
    cin>>n;
    cout<<"\nEnter the data for each node one by one:";
    for(i=0; i<n; i++){
        cin>>x;
        insert(x);
    }
}

void preOrder(struct Node *root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node *root){
    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void search(int x){
    struct Node *current;
    current = root;

    while(current != NULL && current->data != x ){
        if(x > current->data)
            current = current->right;
        else
            current = current->left;
    }

    if(current == NULL)
        cout<<"\nNode not found!";
    else
        cout<<"\nNode found!"; 
}

int heightOfTree(struct Node *root){
    if(root == NULL)
        return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return max(left,right) + 1;
}

int main(){
    int x,ch;
    while(1){
        cout<<"\n------------------Menu---------------------";
        cout<<"\n1.Create \n2.Insert \n3.Preorder Traversal \n4.Inorder Traversal \n5.Postorder Traversal";
        cout<<"\n6.Search \n7.Height Of Tree \n8.Exit";
        cout<<"\nEner your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            cout<<"\nEnter the data: ";
            cin>>x;
            insert(x);
            break;
        case 3:
            cout<<"\nThe Pre Order Traversal of the tree is: ";
            preOrder(root);
            break;
        case 4:
            cout<<"\nThe IN Order Traversal of the tree is: ";
            inOrder(root);
            break;
        case 5:
            cout<<"\nThe Post Order Traversal of the tree is: ";
            postOrder(root);
            break;
        case 6:
            cout<<"\nEnter the data to be searched: ";
            cin>>x;
            search(x);
            break;
        case 7:
            x = heightOfTree(root);
            cout<<"\nHeight of Tree is: "<<x;
            break;
        case 8:
            exit(0);
        }
    }

    return 0;
}