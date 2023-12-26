// Question - Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(string digits, int idx, string mapping[], string &combinations, vector<string> &ans){
        // base condition
        if(idx == digits.size()){
            ans.push_back(combinations);
            return;
        }

        int digit = digits[idx] - '0';
        string letters = mapping[digit];

        for(int i = 0; i < letters.size(); i++){
            combinations.push_back(letters[i]);
            solve(digits, idx+1, mapping, combinations, ans);
            combinations.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string combinations = "";
        solve(digits, 0, mapping, combinations, ans);

        return ans;
    }
};

int main(){
    string digits = "23";
    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    return 0;
}