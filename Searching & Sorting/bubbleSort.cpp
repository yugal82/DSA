// WAP in C++ to sort the array in descending order by using Bubble Sort.

#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void bubbleSort(int x[], int n)
{
    int i, j, temp;
    int counter = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            counter++;
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            } // end of if
        } //end of nested for loop
    } //end of for loop
    cout << counter;
} //end of bubbleSort

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

    bubbleSort(x, n);

    cout << "\nThe sorted elements in the array are:";
    for (i = 0; i < n; i++)
        cout << " " << x[i];

    return 0;
}

/* 
When j = n-1 is the condition of nested for loop, the loop(as counter is set to 0 and incremented   everytime the nested for loop runs) runs for 49 times. And when the condition of nested for loop is changed to j = n-1-i, the loop only runs for 28 times. This saves time and the time complexity of the algorithm is reduced. We use condition j=n-1-i because we dont have to compare the last numbers in the array which are sorted.
*/


/*
For array which is already sorted, we can set a flag = 1 and check whether the array is sorted and break out of the loop if flag = 0. (Not included in the program)
*/