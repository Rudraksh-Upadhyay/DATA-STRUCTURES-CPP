#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
public:

    int solveRecurrsion(vector<int> arr, int j, int k, unordered_map<int, int> mp, int n){
        int target = arr[k] - arr[j];

        if(mp.count(target) && mp[target] < j){  // i < j < k
            int i = mp[target];
            return solveRecurrsion(arr, i, k, mp, n) + 1;
        }

        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        //harr element ko uske index se map kr denge
        for(int i=0;i <n; i++){
            mp[arr[i]] = i;     /// element -> index
        }

        int max_length = 0;

        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                int length = solveRecurrsion(arr, j, k, mp, n);
                if(length >= 3){
                    max_length = max(max_length, length);
                }
            }
        }

        return max_length;


    }
};
// @lc code=end

