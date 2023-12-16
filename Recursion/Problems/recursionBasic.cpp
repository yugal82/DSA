#include <bits/stdc++.h>
#include<iostream>

using namespace std;

// Question 1 - Print name 5 times.
void ans1(int count){
    if(count > 4) return;

    cout<<"Name"<<endl;
    count++;

    ans1(count);
}

// Question 2 - Print linearly from 1 to N
void ans2(int n, int N){
    if(n > N) return;

    cout<<n<<endl;
    n++;

    ans2(n, N);
}

// Question 3 - Print linearly from N to 1
void ans3(int n, int N){
    if(n < N) return;

    cout<<n<<endl;
    n--;

    ans3(n, N);
}

int main(){
    // ans1(0);
    // ans2(1, 5);
    // ans3(5, 1);
    return 0;
}