#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = n-1;

        int mid = (s+e)/2;

        while(s <= e){
            if(target == nums[mid]){
                return mid;
            }
            if(target < mid){
                e = mid-1;
            }
            if(target > mid){
                s = mid + 1;
            }
            mid = (s+e)/2;
        }

        // if(target < nums[n-1]){
        //     return 1;
        // }
        if(target > nums[n-1]){
            int diff = target - nums[n-1];
            return ((n-1) + diff);
        }
        
        return 1;
    }
};

int main(){
    
    Solution sol = Solution();

    vector<int> nums = {1,3,5,6};
    int target = 7;

    cout << sol.searchInsert(nums, target);

    return 0;
}