#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    int solve(vector<int> &cost, int n, int i, vector<int> &dp){
        //base case
        if(i >= n){
            return 0;
        }

        //accessing and checking dp
        if(dp[i] != -1){
            return dp[i];
        }
        
        //taking one step at a time
        int ans1 = cost[i] + solve(cost, n, i+1, dp);
        
        //taking two step at a time
        int ans2 = cost[i] + solve(cost, n, i+2,dp);
        

        //storing the result in dp array
        return dp[i] = min(ans1, ans2);
    }

    public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        // int totalCost = 0;
        
        int n = cost.size();

        //dp create krengge
        vector<int> dp(n+1, -1);
        
        //do starting point honge apne pass starting mei

        //either 0 index or 1 index

        //jab index 0 se start krenge toh...joh min cost kya ayeag woh nikalenge
        //jab index 1 se start krenge toh.. min cosst kya ayega woh nikalenge
        //index 0 se min cost ka answer aur index 1 se min cost ka answer mei se minimum cost hamara answer hoga
        
        int ans = min(solve(cost, n, 0, dp), solve(cost, n, 1, dp));
        
        return ans;
    }
}; 

int main(){

    vector<int> cost = {10, 10, 10, 10, 1, 1};
    Solution sol = Solution();

    cout<< sol.minCostClimbingStairs(cost)<<endl;



    return 0;
}