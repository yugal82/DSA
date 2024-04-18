//  Q] Ninja is planning this 'n' day training schedule. Each day, he can perform only 1 of 3(A, B, C) training activities. Each activity has some profit on each day associated with it. Ninja cannot do the same training activities for 2 consecutive days. Find out the way in which Ninja can earn the max profit.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
        // base case
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(maxi, points[0][i]);
            }
            return maxi;
        }

        if(dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                int point = points[day][i] + f(day-1, i, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points){
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(n-1, 3, points, dp);
    }
};

int main(){
    Solution obj;
    vector<vector<int>> points = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
    obj.ninjaTraining(3, points);
    return 0;
}