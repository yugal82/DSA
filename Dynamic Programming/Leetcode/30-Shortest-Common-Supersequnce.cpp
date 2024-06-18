// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans.push_back(s[i-1]);
                i--;
            }
            else{
                ans.push_back(t[j-1]);
                j--;
            }
        }

        while(i > 0){
            ans.push_back(s[i-1]);
            i--;
        }
        while(j > 0){
            ans.push_back(t[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    string s = "brute";
    string t = "groot";
    cout<<obj.shortestCommonSupersequence(s, t);
    return 0;
}