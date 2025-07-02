#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    int solve(int i, int j, int n, vector<vector<int>> &mat){
        //base case
        if(i < 0 || j < 0 || i > 3 || j > 2 || mat[i][j] == -1){
            return 0;
        }
        if(n == 0) return 1;
        
        //recursive case
        
        
        int ans = solve(i, j, n-1, mat) +
                    solve(i+1, j, n-1, mat) +
                    solve(i-1, j, n-1, mat) +
                    solve(i, j+1, n-1, mat) +
                    solve(i, j-1, n-1, mat) ;
        return ans;
    }
    int solve_dp(int i, int j, int n, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp){
        //base case
        if(i < 0 || j < 0 || i > 3 || j > 2 || mat[i][j] == -1){
            return 0;
        }
        if(n == 0) return 1;
        

        //dp
        if(dp[i][j][n] != -1) return dp[i][j][n];
        
        //recursive case
        
        
        int ans = solve_dp(i, j, n-1, mat, dp) +
                    solve_dp(i+1, j, n-1, mat, dp) +
                    solve_dp(i-1, j, n-1, mat, dp) +
                    solve_dp(i, j+1, n-1, mat, dp) +
                    solve_dp(i, j-1, n-1, mat, dp) ;
        return dp[i][j][n] =  ans;
    }

    
  public:
  
    int getCount(int n) {
        // code here
        vector<vector<int>> mat {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {-1, 1, -1}
        };
        
        int count = 0;

        //dp
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(mat[i][j] != -1){
                    
                    count += solve_dp(i, j, n-1, mat, dp);
                }
            }
        }
        return count;
    }
};

int main(){


    return 0;
}