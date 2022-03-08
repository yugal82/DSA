#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define SS 5
#define INF -32768

using namespace std;

class Stack
{
    int items[SS];
    int top;

    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if (top == SS - 1)
            return 1;
        return 0;
    }

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (isFull())
            cout << "\nStack Overflow!";
        else
        {
            top++;
            items[top] = x;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow!";
            return INF;
        }
        else
        {
            int temp;
            temp = items[top];
            top--;
            return temp;
        }
    }
    int stackTop()
    {
        if (isEmpty())
        {
            cout << "\nStack is already empty! No stack top!";
            return INF;
        }
        else
            return items[top];
    }
    void show()
    {
        if (isEmpty())
            cout << "\nStack is empty!";
        else
        {
            cout << "\nThe elements in the stack are: ";
            for (int i = top; i >= 0; i--)
                cout << " " << items[i];
        }
    }
};

int main()
{
    Stack s;
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
            s.push(x);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            x = s.stackTop();
            if (x != INF)
                cout << "\nThe stack top is: " << x;
            break;
        case 4:
            s.show();
            break;
        case 5:
            exit(0);
        } //end of switch
    } //end of while
    return 0;
}
