#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solveRecurrsion(vector<int> arr, int n, int i, int sum){

    if(i >= n){
        return sum;
    }

    // return max(solveRecurrsion(arr, n, i+1, sum), solveRecurrsion(arr, n, i+2, sum + arr[i]));
    
    //inclusion
    int includeAns = solveRecurrsion(arr, n, i+2, sum + arr[i]);


    //exclusion
    int excludeAns = solveRecurrsion(arr, n, i+1, sum);

    return max(includeAns, excludeAns);
}

int solveTopDown(vector<int> arr, int n, int i, int sum, vector<vector<int>> &dp){

    if(i >= n){
        return sum;
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    // return max(solveRecurrsion(arr, n, i+1, sum), solveRecurrsion(arr, n, i+2, sum + arr[i]));
    
    //inclusion
    int includeAns = solveTopDown(arr, n, i+2, sum + arr[i], dp);


    //exclusion
    int excludeAns = solveTopDown(arr, n, i+1, sum, dp);



    dp[i][sum] = max(includeAns, excludeAns);
    return dp[i][sum];
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

   
    //dp creation
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    // int ans = solveRecurrsion(arr, n, 0, 0);
    int ans = solveTopDown(arr, n, 0, 0, dp);
    cout << ans <<endl;

    return 0;
}