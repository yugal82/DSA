// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool recursion(int i, int j, string &s, string &p){
        if(i < 0 && j < 0) return 1;
        if(i < 0 && j >= 0) return 0;
        if(j < 0 && i >= 0){
            for(int k = 0; k <= i; k++)
                if(p[k] != '*') return 0;
            return 1;
        }

        if(p[i] == s[j] || p[i] == '?') return recursion(i-1, j-1, s, p);
        if(p[i] == '*') return recursion(i-1, j, s, p) || recursion(i, j-1, s, p);

        return 0;
    }

    bool memoization(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i == 0 && j > 0) return 0;
        if(j == 0 && i > 0){
            for(int k = 1; k <= i; k++)
                if(p[k-1] != '*') return 0;
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if(p[i-1] == s[j-1] || p[i-1] == '?') return dp[i][j] = memoization(i-1, j-1, s, p, dp);
        if(p[i-1] == '*') return dp[i][j] = memoization(i-1, j, s, p, dp) || memoization(i, j-1, s, p, dp);

        return dp[i][j] = 0;
    }
    
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        // return memoization(n, m, s, p, dp);
        
        dp[0][0] = true;
        for(int j = 1; j <= m; j++) dp[0][j] = false;
        for(int i = 1; i <= n; i++){
            bool flag = true;
            for(int k = 1; k <= i; k++) {
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

int main(){
    Solution obj;
    string s = "cb", p = "?a";
    cout<<obj.isMatch(s, p);
    return 0;
}
