// WAP in C++ to sort the array in ascending order by using Selection sort with the help of Pull down method

#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void selectionSort(int x[], int n)
{
    int i, j, small, index;
    for (i = 0; i < n - 1; i++)
    {
        index = i;
        small = x[i];
        for (j = n - 1; j > i; j--)
        {
            if (small > x[j])
            {
                small = x[j];
                index = j;
            }
        }
        x[index] = x[i];
        x[i] = small;
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

    selectionSort(x, n);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    return 0;
}
