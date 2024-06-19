// Given two strings s and t, return the number of distinct subsequences of s which equals t. The test cases are generated so that the answer fits on a 32-bit signed integer.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int i, int j, string s, string t){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]) return recursion(i-1, j-1, s, t) + recursion(i-1, j, s, t);
        else return recursion(i-1, j, s, t);
    }

    int memoize(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = memoize(i-1, j-1, s, t, dp) + memoize(i-1, j, s, t, dp);
        else return dp[i][j] = memoize(i-1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        // return memoize(n, m, s, t, dp);

        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int j = 1; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};

int main(){
    Solution obj;
    string s = "rabbbit", t = "rabbit";
    cout<<obj.numDistinct(s, t);
    return 0;
}