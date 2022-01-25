//WAP in C++ to sort the array using merge sort

#include <iostream>
#include <conio.h>
#define MAX 100

using namespace std;

void merge(int x[], int lb1, int ub1, int ub2)
{
    int i, j, k, temp[MAX];
    i = lb1;
    j = ub1 + 1;
    k = 0;

    while (i <= ub1 && j <= ub2)
    {
        if (x[i] < x[j])
        {
            temp[k] = x[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = x[j];
            k++;
            j++;
        }
    }
    while (i <= ub1)
    {
        temp[k] = x[i];
        k++;
        i++;
    }
    while (j <= ub2)
    {
        temp[k] = x[j];
        k++;
        j++;
    }
    for (i = lb1, k = 0; i <= ub2; i++, k++)
        x[i] = temp[k];
}

void mergeSort(int x[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(x, lb, mid);     // tootna process for left sub-array
        mergeSort(x, mid + 1, ub); // tootna process for right sub-array

        merge(x, lb, mid, ub);
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

    mergeSort(x, 0, n - 1);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    return 0;
}
