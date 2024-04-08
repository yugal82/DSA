// Q] There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // MEMOIZATION
    // int solve(int n, vector<int> &h, vector<int> &dp){
    //     if(n == 0) return 0;

    //     if(dp[n] != -1) return dp[n];
    //     else {
    //         int left = solve(n-1, h, dp) + abs(h[n] - h[n-1]);
    //         int right = INT_MAX;
    //         if(n > 1) right = solve(n-2, h, dp) + abs(h[n-1] - h[n-2]);
    //     }

    //     return min(left, right);
    // }

    // int frogJump(int n, vector<int> &h){
    //     vector<int> dp(n+1, -1);
    //     return solve(n, h, dp);
    // }

    int frogJump(int n, vector<int> &h){
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++){        
            int left = dp[i-1] + abs(h[i] - h[i-1]);
            int right = INT_MAX;
            if(i > 1) right = dp[i-2] + abs(h[i] - h[i-2]);

            dp[i] = min(left, right);
        }

        return dp[n-1];
    }
};

int main(){
    Solution obj;
    vector<int> h = {10,20,30,10};
    obj.frogJump(h.size(), h);
    return 0;
}