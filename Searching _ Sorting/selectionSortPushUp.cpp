// WAP in C++ to sort the array in ascending order by using Selection sort with the help of Push up method

#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void selectionSort(int x[], int n)
{
    int i, j, large, index;
    for (i = n-1; i > 0; i--)
    {
        index = 0;
        large = x[index];
        for (j = 0; j <= i; j++)
        {
            if (large < x[j])
            {
                large = x[j];
                index = j;
            }
        }
        x[index] = x[i];
        x[i] = large;
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
