#include<bits/stdc++.h>

using namespace std;

class Solution{


    int n;
    int q;

    private:
    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>> & queries, int k){
        vector<int> diff(n, 0);

        for(int i=0; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];

            diff[l] += v;
            if(r+1 < n){
                diff[r+1] -= v;
            }
        }

        int cumSum = 0;
        for(int i=0; i<n; i++){
            cumSum += diff[i];
            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0){
                return false;
            }
        }
        return true;
    }
    
    public:
    int minZeroArray(vector<int>& nums, vector<vector<int>> & queries){
        n = nums.size();
        q = queries.size();

        auto lambda = [](int x){
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lambda)){
            return 0;
        }

        // time complexity-> O(q * (q + n))
        // for(int i= 0; i < q; i++){  
        //     if(checkWithDifferenceArrayTeq(nums, queries, i) == true){
        //         return i+1;
        //     }
        // }

        //OPTIMIZE WAY -> BINARY SEARCH IMPLEMENTAION
        int l = 0;
        int r = q-1;

        int k = -1; // result index

        while(l <= r){
            int mid = l + (r-l)/2;

            if(checkWithDifferenceArrayTeq(nums, queries, mid) == true){
                k = mid+1; //possible answer
                r = mid-1; //left shift ...for better answer
            }
            else{
                l = mid + 1;
            }
        }

        return k;
    }
};

int main(){

    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

    Solution sol = Solution();

    cout << sol.minZeroArray(nums, queries)<<endl;

    return 0;
}