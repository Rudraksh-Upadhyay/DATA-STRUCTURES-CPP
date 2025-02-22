#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minPath(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = mat[0][0];

    //row
    for(int j=1; j<m; j++){
        dp[0][j] = dp[0][j-1] + mat[0][j];
    }
    //col 1
    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }

    ///baaki ke bache hua fill krenge
    for(int i = 1; i<n; i++){
        for(int j= 1 ; j<m; j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + mat[i][j];
        }
    }

    return dp[n-1][m-1];
}

int main(){

    int rows, cols;
    cin >> rows >>cols;


    vector<vector<int>>matrix (rows, vector<int>(cols));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> matrix[i][j];
        }
    }


    cout << minPath(matrix) <<endl;

    return 0;
}