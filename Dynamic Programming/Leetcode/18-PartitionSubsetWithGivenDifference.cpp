// Q] Given an array, partition it into 2 subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these 2 subsets be S1 and S2.
// Given a difference D, count the number of subsets(partitions) in which S1 >= S2 and the difference between S1 and S2 is equal to D.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod =(int)1e9+7;
    int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
            
        int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
        int taken = 0;
        if(arr[ind]<=target) taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= (notTaken + taken) % mod;
    }

    int countPartitions(int d, vector<int>& arr){
        int n = arr.size();
        int totSum = 0;
        for(int i = 0; i< arr.size(); i++) totSum += arr[i];
        
        //Checking for edge cases
        if(totSum-d < 0) return 0;
        if((totSum-d) % 2 == 1) return 0;
        
        int s2 = (totSum-d)/2;
        
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return countPartitionsUtil(n-1,s2,arr,dp);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4};
    cout<<obj.countPartitions(3, nums);
    return 0;
}