#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

void solve(vector<int> &nums, int start, int end, int& ans){

    if(start == end){
        ans = max(ans, nums[start]);
        return;
    }

    // int sum= accumulate(nums.begin() + start, nums.begin() + end + 1, 0);
    int sum =0 ;
    for(int i=start; i<=end; i++){
        sum += nums[i];
    }


    ans = max(ans, abs(sum));

    solve(nums, start+1, end, ans);
    solve(nums, start, end-1, ans);

}

int maxAbsoluteSum(vector<int>& nums) {
    
    int n = nums.size();
    int maxsum =0 ;
    int current =0;

    for(int i=0; i<n; i++){
        current = max((nums[i]), (current + nums[i]));
        maxsum = max(maxsum, current);
    }

    return maxsum;
}

int minAbsoluteSum(vector<int>&nums){
    int n = nums.size();
    int minsum =0;
    int current = 0;

    for(int i=0; i<n; i++){
        current = min(nums[i], current + nums[i]);
        minsum = min(minsum, current);
    }
    return minsum;
}

int main(){

    vector<int> nums = {2, -5, 1, -4, 3, -2};
    // int ans = 0;

    // solve(nums, 0, nums.size()-1, ans);
    int maxi = maxAbsoluteSum(nums);
    int mini = minAbsoluteSum(nums);
    

    cout << max(abs(maxi), abs(mini)) <<endl;

    return 0;

}