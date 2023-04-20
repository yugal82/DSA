#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define QS 7
#define INF -32768

using namespace std;

class Queue
{
    int items[QS];
    int front,rear;

    int isEmpty()
    {
        if(front>rear)
            return 1;
        return 0;
    }
    int isFull()
    {
        if(rear==QS-1)
            return 1;
        return 0;
    }

    public:
        Queue()
        {
            rear = -1;
            front = 0;
        }

        void insert(int x)
        {   
            if(isFull())
                cout<<"\nQueue Overflow!";
            else
            {
                rear++;
                items[rear]=x;
            }
        }

        int remove()
        {
            if(isEmpty())
            {
                cout<<"\nThe queue is already empty!";
                return INF;
            }
            else
            {
                int temp;
                temp = items[front];
                front++;
                if(isEmpty())
                {
                    front=0;
                    rear=-1;
                }
                return temp;
            }
        }


        void show()
        {
            if(isEmpty())
                cout<<"\nQueue is empty, Nothing to show!";
            else
            {
                int i;
                cout<<"\nThe elements in the queue are: ";
                for(i=front;i<=rear;i++)
                    cout<<" "<<items[i];
            }
        }
};

int main()
{
    int x,ch;
    Queue q;

    while(1)
    {
        cout<<"\n------MENU------";
        cout<<"\n1.Insert \n2.Remove \n3.Display \n4.Exit";
        cout<<"\nEnter choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nEnter the element to be inserted: ";
                cin>>x;
                q.insert(x);
                break;
            case 2:
                q.remove();
                break;
            case 3:
                q.show();
                break;
            case 4:
                exit(0);
        } //end of switch
    } //end of while
    return 0;
} //end of main()