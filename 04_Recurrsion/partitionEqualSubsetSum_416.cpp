//LEETCODE 416

//PARTITION EQUAL SUBSET SUM

#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:

    bool solve(vector<int> &nums, int size, int index, int target){
        //BASE CASE
        if(index == size){
            return false;
        }

        if(target < 0){
            return false;
        }
        
        if(nums[index] == target){
            return true;
        }
        

        //RECURSSION
        //inclusion
        bool incAns = solve(nums, size, index+1, target - nums[index]);

        //exclusion
        bool excAns = solve(nums, size, index+1, target);

        return (incAns || excAns);
    }

    bool canPartition(vector<int> &nums){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];

        }


        if(sum % 2 != 0){
            return false;
        }

        int target = sum/2;
        bool ans = solve(nums, n, 0, target);

        return ans;
    }
};

int main(){

    Solution sol = Solution();
    vector<int> nums = {1, 2, 3, 5};
    

    cout << sol.canPartition(nums) << endl;
    

    return 0;
}