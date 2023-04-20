#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;

int binarySearch(int x[], int n, int ele)
{
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x[mid] == ele)
            return mid;
        else if (x[mid] < ele)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int i, n, ele, index;
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

    index = binarySearch(x, n, ele);

    if (index < 0)
        cout << "\nElement not found!";
    else
        cout << "\nElement found at index:" << index;

    return 0;
}

/*Reccursive method

int binarySearch(int x[],int low,int high,int ele)
{
    int mid;
    while(low<=hgih)
    {
        mid=(low+high)/2;

        if(x[mid]==ele)
            return mid;
        else if(x[mid]<ele)
            binarySearch(x,mid+1,high,ele);
        else
            binarySearch(x,low,mid-1,ele);
    }
}

int main()
{
    binarySearch(x,0,n-1,ele);
}


*/