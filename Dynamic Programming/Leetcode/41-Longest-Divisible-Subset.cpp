// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies: answer[i] % answer[j] == 0, or answer[j] % answer[i] == 0 
// If there are multiple solutions, return any of them.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), hash(nums.size());
        int ans = 0;
        int lastIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            hash[i] = i;
            for(int prevIdx = 0; prevIdx < i; prevIdx++){
                if(nums[i] % nums[prevIdx] == 0 && 1 + dp[prevIdx] > dp[i]){
                    dp[i] = 1 + dp[prevIdx];
                    hash[i] = prevIdx;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
                lastIdx = i;
            }
        }

        vector<int> v;
        v.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            v.push_back(nums[lastIdx]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,4,8};
    obj.largestDivisibleSubset(nums);
    return 0;
}