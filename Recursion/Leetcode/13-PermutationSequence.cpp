// Question - The set [1, 2, 3, ..., n] contains a total of n! unique permutations. By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    // TLE
    // void solve(int n, int &k, string &p, vector<string> &permutations, int isVisited[]){
    //     // base case
    //     if(p.size() == n){
    //         k--;
    //         permutations.push_back(p);
    //         return;
    //     }

    //     for(int i = 1; i <= n; i++){
    //         if(k == 0) break;
    //         if(!isVisited[i]){
    //             isVisited[i] = 1;
    //             char c = '0' + i;
    //             p.push_back(c);

    //             solve(n, k, p, permutations, isVisited);
                
    //             isVisited[i] = 0;
    //             p.pop_back();
    //         }
    //     }
    // }

    // string getPermutation(int n, int k) {
    //     vector<string> permutations;
    //     string p;
    //     int isVisited[n+1];
    //     for(int i = 0; i <= n; i++) isVisited[i] = 0;
    //     solve(n, k, p, permutations, isVisited);

    //     return permutations[k-1];

    // }


    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        int fact = 1;
        for(int i = 1; i < n; i++){
            fact = fact*i;
            nums.push_back(i);
        }
        // in the above loop, the last number is not pushed in the nums vector, so we do that below
        nums.push_back(n);

        // since vector is 0 based indexing, we reduce k by 1. Eg - k = 17, we need 16th element from the vector as it starts from 0
        k = k - 1;

        while(true){
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);

            if(nums.size() == 0) break;

            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;

        // if don't understand the code, please refer to the following youtube link - https://youtu.be/wT7gcXLYoao?si=a-TwqWWe2pq_tWuv
    }
};

int main(){
    int n, k;
    n = 3, k = 3;
    Solution obj;
    cout << obj.getPermutation(n, k) << endl;
    return 0;
}