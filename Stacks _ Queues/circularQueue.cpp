#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define QS 7
#define INF -32768

using namespace std;

struct CQueue
{
    int items[QS];
    int front, rear, count;
};

int isFull(struct CQueue q)
{
    if (q.count == QS)
        return 1;
    return 0;
}

int isEmpty(struct CQueue q)
{
    if (q.count == 0)
        return 1;
    return 0;
}

void insert(struct CQueue *pq, int x)
{
    if (isFull(*pq))
        cout << "\nQueue Overflow!";
    else
    {
        if (pq->rear == QS - 1)
            pq->rear = 0;
        else
            pq->rear++;

        pq->items[pq->rear] = x;
        pq->count++;
    }
}

int remove(struct CQueue *pq)
{
    int temp;
    if (isEmpty(*pq))
    {
        cout << "\nQueue underflow!";
        return INF;
    }
    temp = pq->items[pq->front];
    if (pq->front == QS - 1)
        pq->front = 0;
    else
        pq->front++;

    pq->count--;
    return temp;
}

void show(struct CQueue q)
{
    int i;
    if (isEmpty(q))
        cout << "\nThe queue is already empty!";
    else
    {
        cout << "\nQueue Elements: ";
        if (q.front <= q.rear)
        {
            for (i = q.front; i <= q.rear; i++)
                cout << " " << q.items[i];
        }
        else
        {
            for (i = q.front; i <= QS - 1; i++)
                cout << " " << q.items[i];

            for (i = 0; i <= q.rear; i++)
                cout << " " << q.items[i];
        }
    }
}

int main()
{
    struct CQueue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;

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
            cout << "\nRemoved element: " << x;
            break;
        case 3:
            show(q);
            break;
        case 4:
            exit(0);
        } // end of switch
    }     // end of while
    return 0;
} //end of main