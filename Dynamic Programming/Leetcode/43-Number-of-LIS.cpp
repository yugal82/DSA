// Q] Given an integer array nums, return the number of longest increasing subsequences. Notice that the sequence has to be strictly increasing.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), count(nums.size(), 1);
        int maxi = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int prevIdx = 0; prevIdx < i; prevIdx++){
                if(nums[prevIdx] < nums[i] && (1 + dp[prevIdx]) > dp[i]){
                    dp[i] = 1 + dp[prevIdx];
                    count[i] = count[prevIdx];
                } else if(nums[prevIdx] < nums[i] && 1+dp[prevIdx] == dp[i]) {
                    count[i] += count[prevIdx];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int numOfLIS = 0;
        for(int i = 0; i < count.size(); i++){
            if(dp[i] == maxi) numOfLIS += count[i];
        }
        return numOfLIS;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,4,8};
    cout<<obj.findNumberOfLIS(nums);
    return 0;
}