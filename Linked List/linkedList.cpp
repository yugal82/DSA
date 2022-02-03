// WAP in C++ to create a linked list and perform various operations on the list..

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define NULL 0

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;  // start is defined as "first" in DSA notebook

void insertAtBeg()
{
    struct Node *pnode;
    pnode = (struct Node*) malloc(sizeof(struct Node));
    if(pnode == NULL)
        cout<<"\nMemory overflow!";
    else
    {
        cout<<"\nEnter the data you want to insert: ";
        cin>> pnode->data;

        pnode->next = start;
        start = pnode;

        cout<<"\nNode Inserted!";
    }
}

void insertAtEnd()
{
    struct Node *pnode, *current;
    pnode = (struct Node*) malloc(sizeof(struct Node));
    if(pnode == NULL)
        cout<<"\nMemory Overflow!";
    else
    {
        cout<<"\nEnter the data you want to insert: ";
        cin>>pnode->data;

        if(start == NULL)
        {
            pnode->next = start;
            start = pnode;
        }
        else
        {
            current = start;
            while(current->next != NULL)
                current = current->next;   
            
            pnode->next = current->next;
            current->next = pnode;
            
            cout<<"\nNode Inserted!";
        }
    }
}

void insertAfter()
{
    int x;
    struct Node *pnode, *current;
    pnode = (struct Node*) malloc(sizeof(struct Node));

    if(pnode == NULL)
        cout<<"\nMemory Overflow!";
    else
    {
        cout<<"\nEnter the element you want to insert: ";
        cin>>pnode->data;

        cout<<"\nEnter the data after which you want to insert the new node: ";
        cin>>x;

        current = start;
        while(current->next != NULL && current->data != x)
            current = current->next;
        
        if(current != NULL)
        {
            pnode->next = current->next;
            current->next = pnode;

            cout<<"\nNode Inserted!";
        }
        else
            cout<<"\nNode you were looking for was not found in the list!";
    }
}

void insertBefore()
{
    int x;
    struct Node *pnode, *current, *follow;
    pnode = (struct Node*) malloc(sizeof(struct Node));

    if(pnode == NULL)
        cout<<"\nMemory Overflow!";
    else
    {
        cout<<"\nEnter the data you want to insert: ";
        cin>>pnode->data;

        cout<<"\nEnter the data before which you want to insert the new node: ";
        cin>>x;

        follow = NULL;
        current = start;

        while (current->next != NULL && current->data != x)
        {
            follow = current;
            current = current->next;
        }
        
        if(current == NULL)
            cout<<"\nNode you were looking for was not found in the list!";
        else if(current == start)
        {
            pnode->next = start;  // pnode->next = current; 
            start = pnode;
        }
        else
        {
            pnode->next = follow->next;  // pnode->next = current  (is also correct code)   
            follow->next = pnode;

            cout<<"\nNode Inserted!";
        }
    }
}

void deleteFromFront()
{
    struct Node *current;
    if(start == NULL)
        cout<<"\nThe list is empty, cannot delete!";
    else
    {
        current = start;
        start = current->next ;  //start = start->next;  
        cout<<"\nDeleted node: "<<current->data;
        free(current);
    }
}

void deleteFromEnd()
{
    struct Node *current, *follow;
    if(start == NULL)
        cout<<"\nThe list is empty, cannot delete!";
    else
    {
        current = start;
        follow = NULL;

        while(current->next != NULL)
        {
            follow = current;
            current = current->next;
        }
        if(current == start)
        {
            start = current->next;  // start = NULL;  
            cout<<"\nDeleted node: "<<current->data;
            free(current);
        }
        else
        {
            follow->next = current->next;  // follow->next = NULL;
            cout<<"\nDeleted node: "<<current->data;
            free(current);
        }
    }
}

void deleteNode()
{
    int x;
    struct Node *current, *follow;

    if(start == NULL)
        cout<<"\nThe list is empty, cannot delete!";
    else
    {
        cout<<"\nEnter the node to be deleted: ";
        cin>>x;

        follow = NULL;
        current = start;

        while(current != NULL && current->data != x)
        {
            follow = current;
            current = current->next;
        }
        if(current == NULL)
        {
            cout<<"\nThe node is not present in the list!";
        }
        else if(current == start)
        {
            start = start->next;  // start = current->next;  
            free(current);
            cout<<"\nNode Deleted!";
        }
        else
        {
            follow->next = current->next;
            free(current);
            cout<<"\nNode Deleted!";
        }
        
    }
}

void searchNode()  // void search() in DSA notebook
{
    int x;
    struct Node *current;
    if(start == NULL)
        cout<<"\nThe list is empty, cannot search!";
    else
    {
        cout<<"\nEnter the node you want to search: ";
        cin>>x;

        current = start;
        while(current != NULL && current->data != x)
            current = current->next;
        
        if(current == NULL)
            cout<<"\nNode you want to search is not present in the list!";
        else
            cout<<"\nNode found!"<<current->data;
    }
}

void destroyList()
{
    struct Node *current;
    if(start == NULL)
        cout<<"\nList is empty, cannot destroy list!";
    else
    {
        while(start != NULL)
        {
            current = start;
            start = start->next;
            free(current);
        }
        cout<<"\nThe list has been destroyed!";
    }
}

void reverse()
{
    struct Node *current, *follow, *ahead;
    if(start == NULL)
        cout<<"\nThe list is empty!";
    else
    {
        current = start;
        follow = NULL;
        while(current != NULL)
        {
            ahead = current->next;
            current->next = follow;
            follow = current;
            current = ahead;
        }
        start = follow;
        cout<<"\nThe list has been reversed!";
    }
}

void display()  // void traverse() in DSA notebook
{
    struct Node *current;
    if(start == NULL)
        cout<<"\nThe list is empty, cannot display!";
    else
    {
        current = start;
        cout<<"\nList items: ";
        while(current != NULL)
        {
            cout<<" "<<current->data;
            current = current->next;
        }
    }
}

int main()
{
    int ch;

    while (1)
    {
        cout<<"\n------MENU------";
        cout<<"\n1.Insert At Beginning \n2.Insert At End \n3.Insert After \n4.Insert Before";
        cout<<"\n5.Delete From Front \n6.Delete From End \n7.Delete Node";
        cout<<"\n8.Search \n9.Destroy List \n10.Reverse \n11.Display List \n12.Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                insertAtBeg();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAfter();
                break;
            case 4:
                insertBefore();
                break;
            case 5:
                deleteFromFront();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                deleteNode();
                break;
            case 8:
                searchNode();
                break;
            case 9:
                destroyList();
                break;
            case 10:
                reverse();
                break;
            case 11:
                display();
                break;
            case 12:
                exit(0);
        }
    }
    return 0;
}