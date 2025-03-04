#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:

    int solveTopDown(int n, vector<int> &dp){ //TOP-DOWN APPROACH

        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        //step 3-> dp array mei check kro ki dp[n] value already present hai ki nahi
        //agar hai toh return kr do....recurrsion ke time bach jayega
        if(dp[n] != -1){
            return dp[n];
        }

        //step 2-> dp array mei result store kr do and return kr do
        dp[n] = solveTopDown(n-1, dp) + solveTopDown(n-2, dp);
        return dp[n];
        
    }

    int solveBottomUp(int n,vector<int> &dp){ // BOTTOM-UP APPROACH
        //step 2-> update the dp by analysing the base cases
        dp[0] = 0;
        //agar n = 0 ho toh...iske baad hum dp[1] ko excess krne ki koshish kr rhe hai
        // uss case mei yeh code fatt jayega
        if(n==0){
            return 0;
        }
        dp[1] = 1;

        //step 3-> update kro baaki ke khaane ko
        for(int i=2; i<=n ;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int spaceOptimization(int n, vector<int> &dp){
        dp[0] = 0;
        if(n==0){
            return 0;
        }
        dp[1] = 1;

        for(int i=2; i<=n ;i++){
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[1];
    }
    int fib(int n) {

        //total 3 steps

        //step 1->
        //select and create n-D array
        //in this situation only 'n' is changing so 1-D array will be required
        //create krne ke baad...function ke ander pass kr dena

        // vector<int> dp(n+1, -1);
        // int ans = solveDp(n, dp);


        // int ans = solveBottomUp(n, dp);

        vector<int> dp(3, -1);
        int ans = spaceOptimization(n, dp);

        return ans;
    }
};
// @lc code=end

