#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
class Solution {
public:
    int M = 1e9 + 7;
    
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i=1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        int even = 1;
        int odd = 0;

        for(int i=0; i<n; i++){
            if(prefix[i]%2 == 0){
                //odd + even = odd 
                count = (count + odd) % M;
                even++;
            }
            else{//even + odd  = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};
// @lc code=end

