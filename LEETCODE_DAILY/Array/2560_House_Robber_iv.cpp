/*
LEETCODE 2560
There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

 
Example 1:

Input: nums = [2,3,5,9], k = 2
Output: 5
Explanation: 
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.

Example 2:

Input: nums = [2,7,9,3,1], k = 2
Output: 2
Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.







    Minimize the maximum OR Maximize the minimum -> Binary Search on Answer
*/




#include<bits/stdc++.h>

using namespace std;


class Solution{

    
    private:

//BRUTE FORCE
    int solve_bruteForce(vector<int> &arr, int k, int i, int n){
        //base case
        if(k == 0){
            return 0;
        }

        if(i >= n){//invalid path
            return INT_MAX;
        }

        //include
        int inc = max(arr[i], solve_bruteForce(arr, k-1, i+2, n));

        //exclude
        int exc  = solve_bruteForce(arr, i+1, k , n);

        return min(inc, exc);

    }

    int solve_opt(vector<int> &arr, int k, int i, int n, vector<vector<int>> &dp){
        //base cases
        if (k==0){
            return 0;
        }

        if(i >= n){
            return INT_MAX;
        }

        //checking the dp array
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        //include
        int inc = max(arr[i], solve_opt(arr, k-1, i+2, n, dp));


        //exclude
        int exc = solve_opt(arr, k, i+1, n, dp);

        //storing the result in dp
        return dp[i][k] = min(inc, exc);
    }

    bool isPossible(vector<int> &arr, int mid, int k, int n){
        int house = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= mid){
                //means...capability banne layak hai yeh
                house += 1;
                i++;
            }
        }

        return house >= k; // we managed to rob at least k houses
    }


    public:


    int rob(vector<int> &nums, int k ){

        //recurrsion method
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        // int ans = solve_bruteForce(nums, k, 0, n);
        int ans=  solve_opt(nums, k, 0, n, dp);

        return ans;
    }

    int minCapability(vector<int> &nums, int k){
        int n = nums.size();
        int l  = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int result = r;


        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(nums, mid, k, n)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
    }
    

};

int main(){

    vector<int> nums = {2,7,9,3,1};
    int k = 2;

    Solution sol = Solution();

    cout << sol.rob(nums, k)<<endl;

    return 0;
}