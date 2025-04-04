#include<bits/stdc++.h>

using namespace std;

void print(vector<int> &arr){
    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int maxSubarraySumCircular(vector<int>& nums) {
    
    int n = nums.size();

    int minSum = INT_MAX;
    int maxSum = INT_MIN;

    int currMax = nums[0];
    int currMin = nums[0];

    int totalSum = nums[0];

    for(int i=1; i<n; i++){
        totalSum += nums[i];
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum , currMax);

        currMin = min(nums[i], currMin +  nums[i]);
        minSum = min(minSum, currMin);
    }

    return max(maxSum, totalSum - minSum);
    
}

int main(){

    vector<int> nums = {10, -3, -4, 7, 6, 5, -4, -1};

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}
