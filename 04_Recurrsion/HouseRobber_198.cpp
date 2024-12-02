//LEETCODE 198
//HOUSE ROBBER

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    // vector<int> robbingSequence(int arr[], int index, int n, vector<int>&ans){
    //     //base case
    //     if(index == n){
            
    //         return ans;
    //     }

    //     //INCLUSION
    //     int m = arr[index];
    //     ans.push_back(m);
    //     robbingSequence(arr, index+2, n, ans);

    //     //EXCLUSION
    //     robbingSequence(arr, index+1, n, ans);

    //     return ans;

        
    // }

    int solve(vector<int> &nums, int n, int i){
        //base case
        if(i >= n){
            return 0;
        }

        //include
        int includeAns = nums[i] + solve(nums, n, i+2);

        //exclude
        int excludeAns = 0 + solve(nums, n, i+1);

        return max(includeAns, excludeAns);
    }

    int rob(vector<int>& nums){

        int index = 0;

       
        int ans = solve(nums, nums.size(), index);
        return ans;

    }
};  

int main(){

    // vector<int> ans;
    vector<int>nums = {1, 2, 3, 1};
    // int size = 4;

    Solution sol = Solution();
    cout << sol.rob(nums) << endl;

    return 0;
}