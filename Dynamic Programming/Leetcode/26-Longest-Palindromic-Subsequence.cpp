// Given a string s, find the longest palindromic subsequence's length in s. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void recursion(int idx, string s, string subsequence, vector<string> &subsets){
    //     if(idx == s.size()) {
    //         subsets.push_back(subsequence);
    //         return;
    //     }

    //     // take the character in the subsequence
    //     subsequence.push_back(s[idx]);
    //     recursion(idx+1, s, subsequence, subsets);

    //     // do not take the character in the subsequence
    //     subsequence.pop_back();
    //     recursion(idx+1, s, subsequence, subsets);
    // }

    int f(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f(s1, s2, i-1, j-1, dp);
        return dp[i][j] = max(f(s1, s2, i-1, j, dp), f(s1, s2, i, j-1, dp));
    }


    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return f(s, t, n, m, dp);


        // tabulation code
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};

int main(){
    Solution obj;
    string s = "bbbab";
    cout<<obj.longestPalindromeSubseq(s);
    return 0;
}