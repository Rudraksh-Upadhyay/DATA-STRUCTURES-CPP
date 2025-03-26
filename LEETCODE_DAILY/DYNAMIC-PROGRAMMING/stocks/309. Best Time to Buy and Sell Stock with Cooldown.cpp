//leet code - 309

// medium

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0
*/

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &prices, int day, int n , bool buy, vector<vector<int>> &dp){
    if(day >= n){
        return 0;
    }

    int profit = 0;

    if(dp[day][buy] != -1){
        return dp[day][buy];
    }

    if(buy){ //buy
        int take = solve(prices, day+1, n, false, dp) - prices[day]; // selling - buying

        int not_take = solve(prices, day+1, n, true, dp);

        profit = max({profit, take, not_take});
    }
    else{
        //sell
        int sell = solve(prices, day+2, n, true, dp) + prices[day];

        int not_sell = solve(prices, day+1, n, false, dp);

        profit = max({profit, sell, not_sell});
    }

    return dp[day][buy] = profit;
}

int maxProfit(vector<int> & prices){
    int n = prices.size();
    bool buy  =  true;

    vector<vector<int>> dp(n+1, vector<int> (2, -1));

    return solve(prices, 0, n, buy, dp);
}

int main(){

    vector<int> prices = {1};
    
    cout << maxProfit(prices) << endl;

    return 0;
}