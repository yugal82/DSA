//WAP in C++ to search an element in a given array

#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

void linearSearch(int x[], int n, int ele)
{
    int i, flag=0;
    for (i = 0; i < n; i++)
    {
        if (x[i] == ele)
        {
            flag=1;
            cout<<"\nThe element is present at index: "<<i;
        }
    }
    if(flag==0)
        cout<<"\nThe element is not present!";
}

int main()
{
    int i, n, ele;
    int x[MAX];
    cout << "\n Enter the range: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter element to be inserted: ";
        cin >> x[i];
    }
    cout << "\nEnter element to be searched:";
    cin >> ele;

    linearSearch(x, n, ele);

    return 0;
}


/*
-This program is to return the number of times the element is present in the array
-And the above program is used to search the duplicate elements in the array and also display the index at     which it is stored


int linearSearch(int x[], int n, int ele)
{
    int i, c=0;
    for (i = 0; i < n; i++)
    {
        if (x[i] == ele)
            c++;
    }
    return c;
}

int main()
{
    int i, n, ele,index;
    int x[MAX];
    cout << "\n Enter the range: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter element to be inserted: ";
        cin >> x[i];
    }
    cout << "\nEnter element to be searched:";
    cin >> ele;

    index = linearSearch(x, n, ele);
    if(index>0)
        cout<<"\nThe element is present "<<index<<" times";
    else   
        cout<<"\nThe element is not present!";
    return 0;
}

*/