#include<bits/stdc++.h>

using namespace std;

class solution{
    private:

    void getSubset(int index, vector<int> &arr, vector<int> &current, vector<vector<int>> &subsets){
        int n = arr.size();
        if(index == n){
            subsets.push_back(current);
            return;
        }

        //include
        current.push_back(arr[index]);
        getSubset(index+1, arr, current, subsets);

        //exclude
        current.pop_back();
        getSubset(index+1, arr, current, subsets);
    }

    public:
    
    int subsetXORSum(vector<int>& nums){
        vector<int> current;
        vector<vector<int>> subsets;
        getSubset(0, nums, current, subsets);
        
        int n = subsets.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(auto x : subsets[i]){
                sum ^= x;
            }

            ans += sum;
        }

        return ans;
    }

};

int main(){

    vector<int> nums = {1, 3};

    solution sol = solution();

    cout << sol.subsetXORSum(nums) << endl;

    return 0;
}