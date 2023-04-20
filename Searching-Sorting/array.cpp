#include<iostream>
#include<conio.h>
#define MAX 10
using namespace std;

int main()
{
    int i,n;
    int x[MAX];
    cout<<"\n Enter the range: ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cout<<"Enter element to be inserted: ";
        cin>>x[i];
    }

    cout<<"\nThe elements in the array are:";
    for(i=0; i<n; i++)
        cout<<" "<<x[i];
    
    return 0;
}