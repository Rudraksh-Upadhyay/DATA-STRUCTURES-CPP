#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &arr){
    int n = arr.size();

    int currMaxSum = arr[0];
    int maxSum = arr[0];

    for(int i=1; i<n; i++){
        currMaxSum = max(arr[i], currMaxSum + arr[i]);
        maxSum = max(maxSum, currMaxSum);
    }

    return maxSum;
}

int main(){

    vector<int> arr  = {2, 3, -8, 7, -1, 2, 3};

    cout << maxSubarraySum(arr) << endl;

    return 0;
}