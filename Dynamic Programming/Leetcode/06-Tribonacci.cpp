// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    // int solve(int n, vector<int> &dp){
    //     if(n == 0) return 0;
    //     if(n == 1 || n == 2) return 1;

    //     if(dp[n] != -1) return dp[n];
    //     else return dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
    // }
    // int tribonacci(int n) {
    //     vector<int> dp(n+1, -1);
    //     return solve(n, dp);
    // }

    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int zero = 0, first = 1, second = 1;

        for(int i = 2; i < n; i++){
            int curr = zero + first + second;
            zero = first;
            first = second;
            second = curr;
        }

        return second;
    }
};

int main(){
    Solution obj;
    cout<<"The Nth Tribonacci number is: "<<obj.tribonacci(10);
    return 0;
}