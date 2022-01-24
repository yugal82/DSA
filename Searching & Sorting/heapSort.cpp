#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void heapUp(int heap[], int newnode)
{
    int parent, temp;
    if (newnode > 0)
    {
        parent = (newnode - 1) / 2;

        if (heap[newnode] > heap[parent])
        {
            temp = heap[newnode];
            heap[newnode] = heap[parent];
            heap[parent] = temp;

            heapUp(heap, parent);
        }
    }
}

void heapDown(int heap[], int root, int lastIndex)
{
    int leftChild, rightChild, maxChild, temp;
    leftChild = (root * 2) + 1;
    rightChild = (root * 2) + 2;
    if (leftChild <= lastIndex)
    {
        if (rightChild <= lastIndex)
        {
            if (heap[leftChild] > heap[rightChild])
                maxChild = leftChild;
            else
                maxChild = rightChild;
        }
        else
            maxChild = leftChild;

        if (heap[root] < heap[maxChild])
        {
            temp = heap[root];
            heap[root] = heap[maxChild];
            heap[maxChild] = temp;

            heapDown(heap, maxChild, lastIndex);
        }
    }
}

void heapSort(int x[], int n)
{
    int i, temp;
    for (i = 1; i < n; i++)
        heapUp(x, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = x[0];
        x[0] = x[i];
        x[i] = temp;

        heapDown(x, 0, i - 1);
    }
}

int main()
{
    int i, n;
    int x[MAX];
    cout << "\n Enter the range: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter element to be inserted: ";
        cin >> x[i];
    }

    cout << "\nThe unsorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    heapSort(x, n);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    return 0;
}