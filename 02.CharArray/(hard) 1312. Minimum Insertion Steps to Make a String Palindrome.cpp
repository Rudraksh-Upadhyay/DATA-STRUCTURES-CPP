/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:

    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if( s[i] == s[j] ){
            return dp[i][j] =  solve(s, i+1, j-1, dp);
        }

        return dp[i][j] = 1 + min(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
    }
public:
    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve(s, 0, n-1, dp);
    }
};

int main(){

    Solution sol = Solution();

    string s = "aacecaaaa";

    cout << sol.minInsertions(s) << endl;

    return 0;
}