// WAP in C++ to implement doubly linked list and perform various operations on the list.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *start = NULL;
struct Node *last = NULL;

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
            start = last = pnode;
            start->prev = NULL;
            start->next = NULL;
        }
        else
        {
            pnode->next = start;
            start = pnode;
            pnode->prev = NULL;
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
            start->next = NULL;
            start->prev = NULL;
        }
        else
        {
            last->next = pnode;
            pnode->prev = last;
            last = pnode;
            last->next = NULL;
        }
        cout << "\nNode Inserted!";
    }
}

void insertAfter()
{

    if (start == NULL)
    {
        cout << "\nList is empty!";
        return;
    }
    int x;
    struct Node *pnode, *current;
    pnode = (struct Node *)malloc(sizeof(struct Node));

    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        current = start;
        cout << "\nEnter the data you want to insert in the node: ";
        cin >> pnode->data;

        cout << "\nEnter the node after which you want to insert the new node: ";
        cin >> x;

        while (current->data != x && current != last)
            current = current->next;

        if (current->data != x)
            cout << "\nThe node is not present!";
        else if (current == last)
        {
            last->next = pnode;
            pnode->next = NULL;
            pnode->prev = last;
            last = pnode;
            cout << "\nNode Inserted!";
        }
        else
        {
            pnode->next = current->next;
            pnode->prev = current;
            current->next->prev = pnode;
            current->next = pnode;
            cout << "\nNode Inserted!";
        }
    }
}

void insertBefore()
{
    int x;
    if (start == NULL)
    {
        cout << "\nList is empty!";
        return;
    }

    struct Node *pnode, *current;
    pnode = (struct Node *)malloc(sizeof(struct Node));
    if (pnode == NULL)
        cout << "\nMemory Overflow!";
    else
    {
        current = start;
        cout << "\nEnter the data you want to insert in the node: ";
        cin >> pnode->data;

        cout << "\nEnter the node before which you want to insert the new node: ";
        cin >> x;

        while (current->data != x && current != last)
            current = current->next;

        if (current->data != x)
            cout << "\nThe node is not present!";
        else if (current == start)
        {
            pnode->next = current;
            pnode->prev = NULL;
            start = pnode;
            current->prev = pnode;
            // last = start->next; 
            cout << "\nNode Inserted!";
        }
        else
        {
            pnode->next = current;
            pnode->prev = current->prev;
            current->prev->next = pnode;
            current->prev = pnode;
            cout << "\nNode Inserted!";
        }
    }
}

void deleteFromFront()
{
    struct Node *current;
    if (start == NULL)
        cout << "\nList is already empty!";
    else
    {
        current = start;
        start = start->next;
        start->prev = NULL;
        cout << "\nDeleted node: " << current->data;
        free(current);
    }
}

void deleteFromEnd()
{
    struct Node *current;
    if (start == NULL)
        cout << "\nList is already empty!";
    else
    {
        current = last;
        last = last->prev;
        current->prev->next = NULL;
        cout << "\nDeleted node: " << current->data;
        free(current);
    }
}

void deleteNode()
{
    int x;
    struct Node *current;
    if (start == NULL)
        cout << "\nList is already empty!";
    else
    {
        cout << "\nEnter the node you want to delete: ";
        cin >> x;

        current = start;
        while (current->data != x && current != last)
            current = current->next;

        if (current->data != x)
            cout << "\nNode not found!";
        else if (current == start)
        {
            start = current->next;
            start->prev = NULL;
            free(current);
            cout << "\nNode deleted!";
        }
        else if (current == last)
        {
            last = current->prev;
            last->next = NULL;
            free(current);
            cout << "\nNode deleted!";
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            cout << "\nNode deleted!";
        }
    }
}

void display()
{
    struct Node *current;
    if (start == NULL)
        cout << "\nList is empty!";
    else
    {
        cout << "\nList elements: ";
        current = start;
        while (current != last)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << last->data;
    }
}
int main()
{
    int ch;

    while (1)
    {
        cout << "\n------MENU------";
        cout << "\n1.Insert At Beginning \n2.Insert At End \n3.Insert After \n4.Insert Before";
        cout << "\n5.Delete From Front \n6.Delete From End \n7.Delete Node";
        cout << "\n8.Display List \n9.Exit";

        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
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