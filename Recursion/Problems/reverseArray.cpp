#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void reverse(int i, int j, vector<int> &arr){
    if(i > j) return;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
    
    reverse(i, j, arr);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout<<"before reversing: ";
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    
    int i = 0, j = arr.size()-1;
    reverse(i, j, arr);

    cout<<endl<<"after reversing: ";
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";

    return 0;
}