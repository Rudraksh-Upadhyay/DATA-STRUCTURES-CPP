/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/


#include<bits/stdc++.h>

using namespace std;


class Solution{
    private:

    void solve(int index, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev, vector<vector<int>> &dp){
        //base cases
        if(index >= nums.size()){
            if(temp.size() > result.size()){
                result = temp;
            }
            return;
        }

        
        //take
        if(prev == -1 || nums[index] % prev == 0){
            temp.push_back(nums[index]);
            solve(index + 1, nums, result, temp, nums[index], dp);
            temp.pop_back();
        }
        

        //not take
        solve(index + 1, nums, result, temp, prev, dp);
    }

    public:

    vector<int> largestDivisibleSubset(vector<int> &nums){
        sort(begin(nums), end(nums));
        vector<int> result;
        vector<int> temp;

        int prev = -1;

        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size()+ 1 , -1));

        solve(0, nums, result, temp, prev, dp);

        return result;
    }

};

int main(){

    vector<int> nums= {1, 2, 3};
    Solution sol = Solution();

    vector<int> result = sol.largestDivisibleSubset(nums);

    for(auto &x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}