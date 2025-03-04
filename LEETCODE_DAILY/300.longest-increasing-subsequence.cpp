#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int solveRecurrsion(vector<int> &arr, int lastIndex, int i){
        //base case
        if(i >= arr.size()){
            return 0;
        }

        //jab current element..last element se bada honge toh include krenge
        int curr = arr[i];
        int inc = 0;
        if(lastIndex == -1 || curr > arr[lastIndex]){
            inc  = 1 + solveRecurrsion(arr, i, i+1);
        }
        int exc  = 0 + solveRecurrsion(arr, lastIndex , i+1);

        return max(inc, exc);
    }

    int solveTopDown(vector<int> &arr, int lastIndex, int i, vector<vector<int>> &dp){
        if(i >= arr.size()){
            return 0;
        }

        //step 3-> check if ans already existd in dp
        if(dp[lastIndex+1][i] != -1){
            return dp[lastIndex+1][i];
        }



        int curr = arr[i];
        int inc = 0;

        if(lastIndex == -1 || curr > arr[lastIndex]){
            inc = 1 + solveTopDown(arr, i, i+1, dp);
        }
        int exc = 0 + solveTopDown(arr, lastIndex, i+1, dp);

        //step 2
        dp[lastIndex+1][i]  = max(inc, exc);

        return dp[lastIndex+1][i];    

    }
    int lengthOfLIS(vector<int>& nums) {
        int lastIndex = -1;
        // int ans = solveRecurrsion(nums, lastIndex, 0);
        int n = nums.size();

        //2-D dp array create kregnge kyuki...isme hamarap 'i' aur 'lastindex' change ho raha hai

        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));

        int ans = solveTopDown(nums, lastIndex, 0, dp);
        return ans;
    }
};
// @lc code=end

