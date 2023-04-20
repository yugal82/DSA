// WAP in C++ to sort the array in ascending order by using Insertion Sort.

#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void insertionSort(int x[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = x[i];
        for (j = i - 1; j >= 0 && temp < x[j]; j--)
        {
            x[j + 1] = x[j];
            x[j] = temp;
        } //end of nested for loop
    } //end of for loop
} //end of insertionSort()

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
        cout << " " << x[i] << endl;

    insertionSort(x, n);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i] << endl;

    return 0;
}
