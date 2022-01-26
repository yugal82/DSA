//WAP in C++ to create a stack using array also using structure

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define SS 5
#define INF -32768

using namespace std;

struct Stack
{
    int items[SS];
    int top;
};

int isEmpty(struct Stack s)
{
    if (s.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack s)
{
    if (s.top == SS - 1)
        return 1;
    return 0;
}

void push(struct Stack *ps, int x)
{
    if (isFull(*ps))
        cout << "\nStack Overflow!";
    else
    {
        ps->top++;
        ps->items[ps->top] = x;
    }
}

int pop(struct Stack *ps)
{
    if (isEmpty(*ps))
    {
        cout << "\nStack Underflow!";
        return INF;
    }
    else
    {
        int temp;
        temp = ps->items[ps->top];
        ps->top--;
        return temp;
    }
}

int stackTop(struct Stack s)
{
    if (isEmpty(s))
    {
        cout << "\nStack is already empty! No stack top!";
        return INF;
    }
    else
        return s.items[s.top];
}

void show(struct Stack s)
{
    if (isEmpty(s))
        cout << "\nStack is empty!";
    else
    {
        cout << "\nThe elements in the stack are: ";
        for (int i = s.top; i >= 0; i--)
            cout << " " << s.items[i];
    }
}

int main()
{
    struct Stack s;
    s.top = -1;
    int ch, x;

    while (1)
    {
        cout << "\n------MENU------";
        cout << "\n1.Push \n2.Pop \n3.Stack Top \n4.Display \n5.Eixt";
        cout << "\nEnter choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the element to be pushed:";
            cin >> x;
            push(&s, x);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            x = stackTop(s);
            if (x != INF)
                cout << "\nThe stack top is: " << x;
            break;
        case 4:
            show(s);
            break;
        case 5:
            exit(0);
        } //end of switch
    } //end of while
    return 0;
}
