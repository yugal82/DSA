// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:
// Insert a character,  Delete a character,  Replace a character

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int i, int j, string s, string t){
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(s[i] == t[j]) return 0 + recursion(i-1, j-1, s, t);

        int insertOpr = 1 + recursion(i, j-1, s, t);
        int deleteOpr = 1 + recursion(i-1, j, s, t);
        int replaceOpr = 1 + recursion(i-1, j-1, s, t);

        return min(insertOpr, min(deleteOpr, replaceOpr));
    }

    int memoization(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(i == 0) return j;
        if(j == 0) return i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = 0 + memoization(i-1, j-1, s, t, dp);

        int insertOpr = 1 + memoization(i, j-1, s, t, dp);
        int deleteOpr = 1 + memoization(i-1, j, s, t, dp);
        int replaceOpr = 1 + memoization(i-1, j-1, s, t, dp);

        return dp[i][j] = min(insertOpr, min(deleteOpr, replaceOpr));
    }

    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return memoization(n, m, s, t, dp);

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else{
                    int insertOpr = 1 + dp[i][j-1];
                    int deleteOpr = 1 + dp[i-1][j];
                    int replaceOpr = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insertOpr, min(deleteOpr, replaceOpr));
                }
            }
        }

        return dp[n][m];
    }
};

int main(){
    Solution obj;
    string s = "horse", t = "ros";
    cout<<obj.minDistance(s, t);
    return 0;
}
