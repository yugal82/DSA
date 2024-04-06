#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> &dp){
        // base case
        if(n <= 1) return n;

        // check if the subproblem is already solved. If yes, return the value of the subproblem, else compute the value of subproblem.
        if(dp[n] != -1) return dp[n];
        else return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int fib(int n) {
        // memoization technique
        // TC - O(n) ----- SC - O(n)
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

int main(){
    Solution obj;
    cout<<obj.fib(5);

    return 0;
}