#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void sumofN(int n, int N, int &sum){
    if(n > N) return;

    sum = sum + n;
    n++;
    sumofN(n, N, sum);
}

int sumOfN(int n){
    if(n <= 0) return 0;

    return n + sumOfN(n-1);
}

int factorial(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return n * factorial(n-1);
}

int main(){
    int sum = 0;
    // sumofN(1,10,sum);
    // cout<<"The sum is: "<<sum;

    // cout<<sumOfN(5);

    cout<<factorial(5);
    return 0;
}