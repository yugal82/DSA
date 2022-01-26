#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define QS 8
#define INF -32768

using namespace std;

struct Queue
{
    int items[QS];
    int front;
    int rear;
};

int isEmpty(struct Queue q)
{
    if (q.front > q.rear)
        return 1;
    return 0;
}
int isFull(struct Queue q)
{
    if (q.rear == QS - 1)
        return 1;
    return 0;
}

void insert(struct Queue *pq, int x)
{
    if (isFull(*pq))
        cout << "\nQueue Overflow!";
    else
    {
        pq->rear++;
        pq->items[pq->rear] = x;
    }
}

int remove(struct Queue *pq)
{
    int temp;
    if (isEmpty(*pq))
    {
        cout << "\nQueue is already empty!";
        return INF;
    }
    else
    {
        temp = pq->items[pq->front];
        pq->front++;

        if (isEmpty(*pq))
        {
            pq->rear = -1;
            pq->front = 0;
        }
        return temp;
    }
}

void show(struct Queue q)
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
    struct Queue q;
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
            remove(&q);
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