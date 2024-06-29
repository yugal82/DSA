// Q] You are given an array of words where each word consists of lowercase English letters. wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad". A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1. Return the length of the longest possible word chain with words chosen from the given list of words.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPossible(string &s, string &t){
        if(s.size() != t.size()+1) return false;
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            } 
            else i++;
        }

        if(i == s.size() && j == t.size()) return true;
        return false;
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        vector<int> dp(words.size(), 1);
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int prevIdx = 0; prevIdx < i; prevIdx++){
                if(checkIfPossible(words[i], words[prevIdx]) && (1 + dp[prevIdx]) > dp[i]){
                    dp[i] = 1 + dp[prevIdx];
                }
            }
            if(dp[i] > ans) ans = dp[i];
        }

        return ans;
    }
};

int main(){
    Solution obj;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout<<obj.longestStrChain(words);
    return 0;
}