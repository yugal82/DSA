#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define QS 6
#define INF -32768

using namespace std;

struct PQueue
{
    int items[QS];
    int front, rear;
};
int isFull(struct PQueue q)
{
    if(q.rear == QS-1)
        return 1;
    return 0;
}
int isEmpty(struct PQueue q)
{
    if(q.front > q.rear)
        return 1;
    return 0;
}

void insert(struct PQueue *pq, int x)
{
    if (isFull(*pq))
        cout << "\nQueue Overflow!";
    else
    {
        pq->rear++;
        pq->items[pq->rear] = x;
    }
}

int remove(struct PQueue *pq)
{
    int small,index,i,temp;
    if(isEmpty(*pq))
    {
        cout<<"\nQueue underflow!";
        return INF;
    }
    else
    {
        small = pq->items[0];
        index = 0;
        for(i=pq->front;i<=pq->rear;i++)
        {
            if(small > pq->items[i])
            {
                small = pq->items[i];
                temp = small;
                index = i;
            }
        }

        for(i=index;i<pq->rear;i++)
            pq->items[i] = pq->items[i+1];

        pq->rear--;
        return temp;    
    }

}

void show(struct PQueue q)
{
    if (isEmpty(q))
        cout << "\nQueue underflow!";
    else
    {
        cout << "\nThe elements in the queue are:";
        for (int i = q.front; i <= q.rear; i++)
            cout << " " << q.items[i];
    }
}

int main()
{
    struct PQueue q;
    q.front = 0;
    q.rear = -1;

    int ch, x;
    while (1)
    {
        cout << "\n------MENU------";
        cout << "\n1.Insert \n2.Remove \n3.Display \n4.Exit";
        cout << "\nEnter choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the element to be inserted:";
            cin >> x;
            insert(&q, x);
            break;
        case 2:
            x = remove(&q);
            cout<<"\nRemoved element: "<<x;
            break;
        case 3:
            show(q);
            break;
        case 4:
            exit(0);
        } // end of switch
    } // end of while
    return 0;
} //end of main