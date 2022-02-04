#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *last = NULL;

/*
struct Node *createNode()
{
    struct Node *pnode;
    pnode = (struct Node *)malloc(sizeof(struct Node));
    if (pnode == NULL)
        return NULL;
    
    cout<<"\nEnter data you want to insert: ";
    cin>>pnode->data;
    pnode->next = NULL;

    return pnode;  


- This is a helper function to create a new node. Instead of writing the code for new node(pnode) everytime, this helper function can be passed and the node can be created!

    pnode = create()

- This is how we can pass and create a new node named pnode!
}
*/

void insertAtBeg()
{
    struct Node *pnode;
    pnode = (struct Node *)malloc(sizeof(struct Node));

    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        cout << "\nEnter the data you want to insert: ";
        cin >> pnode->data;

        if (start == NULL)
        {
            pnode->next = NULL;
            start = last = pnode;
            last->next = start;
        }
        else
        {
            pnode->next = start;
            start = pnode;
            last->next = start;
        }
        cout << "\nNode Inserted!";
    }
}

void insertAtEnd()
{
    struct Node *pnode;
    pnode = (struct Node *)malloc(sizeof(struct Node));

    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        cout << "\nEnter the data you want to insert: ";
        cin >> pnode->data;

        if (start == NULL)
        {
            start = last = pnode;
            last->next = start;
        }
        else
        {
            last->next = pnode;
            last = pnode;
            last->next = start;
        }
        cout << "\nNode Inserted!";
    }
}

void insertAfter()
{
    int x;
    struct Node *pnode, *current;

    if (start == NULL)
    {
        cout << "\nThe list is empty!";
        return;
    }

    pnode = (struct Node *)malloc(sizeof(struct Node));

    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        cout << "\nEnter the data you want to insert: ";
        cin >> pnode->data;

        cout << "\nEnter the data after which you want to insert the new node: ";
        cin >> x;

        current = start;
        while (current->data != x && current != last)
            current = current->next;

        if (current->data != x)
            cout << "\nThe node you were looking for is not present in the list!";
        else if (current == last)
        {
            last->next = pnode;
            last = pnode;
            last->next = start;
            cout << "\nNode Inserted!";
        }
        else
        {
            pnode->next = current->next;
            current->next = pnode;
            cout << "\nNode Inserted!";
        }
    }
}

void insertBefore()
{
    int x;
    struct Node *pnode, *current, *follow;

    if (start == NULL)
    {
        cout << "\nThe list is empty!";
        return;
    }
    pnode = (struct Node *)malloc(sizeof(struct Node));

    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        cout << "\nEnter the data you want to insert: ";
        cin >> pnode->data;

        cout << "\nEnter the data before which you want to insert the new node: ";
        cin >> x;

        current = start;
        follow = NULL;
        while (current->data != x && current != NULL)
        {
            follow = current;
            current = current->next;
        }
        if (current->data != x)
            cout << "\nNode you were looking for is not present in the list!";
        else if (current == start)
        {
            pnode->next = current;
            start = pnode;
            last->next = start;
            cout << "\nNode Inserted!";
        }
        else
        {
            pnode->next = current;
            follow->next = pnode;
            cout << "\nNode Inserted!";
        }
    }
}

void deleteFromFront()
{
    struct Node *current;
    if (start == NULL)
        cout << "\nThe list is empty!";
    else
    {
        current = start;
        if (start == last)
            start = last = NULL;
        else
        {
            start = start->next;
            last->next = start;
        }
        cout << "\nDeleted Node: " << current->data;
        free(current);
    }
}

void deleteFromEnd()
{
    struct Node *current, *follow;
    if (start == NULL)
        cout << "\nList is empty!";
    else
    {
        current = last;
        if (start == last)
            start = last = NULL;
        else
        {
            follow = start;
            while (follow->next != last)
                follow = follow->next;

            last = follow;
            last->next = start;
        }
        cout << "\nDeleted Node: " << current->data;
        free(current);
    }
}

void deleteNode()
{
    int x;
    struct Node *current, *follow;
    if (start == NULL)
        cout << "\nThe list is empty!";
    else
    {
        cout << "\nEnter the node you want to delete: ";
        cin >> x;

        current = start;
        follow = NULL;
        while (current->data != x && current != last)
        {
            follow = current;
            current = current->next;
        }
        if (current->data != x)
        {
            cout << "\nNode you want to delete is not present in the list!";
            return;
        }
        if (start == last)
            start = last = NULL;
        else if (current == start)
        {
            start = current->next;
            last->next = start;
        }
        else if (current == last)
        {
            last = follow;
            last->next = start;
        }
        else
        {
            follow->next = current->next;
        }
        free(current);
        cout << "\nNode Deleted!";
    }
}

void display()
{
    struct Node *current;
    if(start == NULL)
        cout<<"\nThe list is empty, nothing to display!";
    else
    {
        cout<<"\nList elements: ";
        current = start;
        while(current != last)
        {
            cout<<" "<<current->data;
            current = current->next;
        }
        cout<<" "<<last->data;
    }
}
/*
    void searchNode() , void destroyList() , void reverse() fucntions can also be made like functions in linked list programm. 
*/
int main()
{
    int ch;

    while (1)
    {
        cout<<"\n------MENU------";
        cout<<"\n1.Insert At Beginning \n2.Insert At End \n3.Insert After \n4.Insert Before";
        cout<<"\n5.Delete From Front \n6.Delete From End \n7.Delete Node";
        cout<<"\n8.Display List \n9.Exit";

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
                display();
                break;
            case 9:
                exit(0);
        }
    }
    return 0;
}