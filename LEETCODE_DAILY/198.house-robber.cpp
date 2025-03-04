#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:

    int solveRecurrsion(vector<int> &arr, int n, int i){
        // int n = arr.size();
        if(i>=n){
            return 0;
        }

        //include
        int includeAns = arr[i] + solveRecurrsion(arr, n, i+2);

        //exclude
        int excludeAns = 0 + solveRecurrsion(arr, n, i+1);

        return max(includeAns, excludeAns);

        
    }

    //1-D dp
    //top-down approach
    //recurrsion and memoization
    int solveTopDown(vector<int> &arr, int n, int i, vector<int> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int include  = arr[i] + solveTopDown(arr, n, i+2, dp);
        int exclude  = 0 + solveTopDown(arr, n, i+1, dp);

        dp[i] = max(include, exclude);
        return dp[i]; 

    }

    int solveBottomUp(vector<int> &arr, int n,vector<int> &dp){
        
        for(int i=n-1; i>=0; i--){
            int include  = arr[i] + dp[i+2];
            int exclude  =  0 + dp[i+1];
            dp[i]  = max(include, exclude);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        // return solveRecurrsion(nums, nums.size(), 0);
        int n = nums.size();
        vector<int> dp(n+2, 0);
        // int ans = solveTopDown(nums, n, 0, dp);
        int ans = solveBottomUp(nums, n, dp);

        return ans;

    }
};
// @lc code=end

