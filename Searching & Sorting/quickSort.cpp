#include<iostream>
#include<conio.h>
#define MAX 10

using namespace std;

int partition(int x[], int lb, int ub)
{
    int pivot,down,up,temp;
    pivot = x[lb];
    down = lb;
    up = ub;
    

    while(down < up)
    {
        while(x[down]<=pivot && down <= up)
            down++;

        while (x[up] > pivot)
            up--;

        if(down < up)
        {
            temp = x[down];
            x[down]=x[up];
            x[up]=temp;
        }
    }
    x[lb]=x[up];
    x[up]=pivot;
    return up;
}

void quickSort(int x[],int lb,int ub)
{
    int index;
    if(lb>=ub)
        return;
    
    index = partition(x,lb,ub);
    quickSort(x,lb,index-1); //for left sub-array.
    quickSort(x,index+1,ub); // for right sub-array.
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

    quickSort(x,0,n-1);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    return 0;
}
