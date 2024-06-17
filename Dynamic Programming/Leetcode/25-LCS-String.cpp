// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0. A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde". A common subsequence of two strings is a subsequence that is common to both strings.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i-1] == text2[j-1])
            return dp[i][j] = 1 + recursion(i-1, j-1, text1, text2, dp);

        return dp[i][j] = max(recursion(i-1, j, text1, text2, dp), recursion(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recursion(n, m, text1, text2, dp);
    }

    int longestCommonSubsequenceTabulation(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        // tabulation
        // base case conversion
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};

int main(){
    Solution obj;
    string text1 = "abcde", text2 = "ace";
    cout<<obj.longestCommonSubsequence(text1, text2);
    cout<<obj.longestCommonSubsequenceTabulation(text1, text2);
    return 0;
}