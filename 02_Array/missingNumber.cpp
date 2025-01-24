#include<iostream>
#include<vector>
#include<numeric>

using namespace std;


class Solution{
    public:

    int findSumOfNaturalNumbers(int n){
        return (n*(n+1))/2;
    }

    int findMaxElement(vector<int> &nums){
        int max = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }

        return max;
    }

    int missingNumberInArray(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            if(nums[0] == 1){

                return nums[0] +1;
            }
            else{
                return nums[0] -1;
            }
        }
        int maxElement = findMaxElement(nums);
        

//EXPECTED SUM
        int sumOfNaturalNumber = findSumOfNaturalNumbers(maxElement);

//ACTUAL SUM
        // for(int i=0; i<n;i++){
        //     arraySum += nums[i];
        // }

        int arraySum = accumulate(nums.begin(), nums.end(), 0);

        int result = abs(sumOfNaturalNumber - arraySum);

        if(result == 0){
            return maxElement + 1;
        }

        return result;
    }



    int missingNumber2(vector<int> &nums){
        int n = nums.size();
        vector<int> a(n+1, 0);

        for(int i=0; i<n; i++){
            if(nums[i] <= n+1){
                a[nums[i]] = 1;
            }
        }

        for(int i=0; i<n; i++){
            if(a[i] == 0){
                return i;
            }
        }

        return n+1;
    }

};

int main(){

    Solution sol = Solution();

    vector<int> nums = {2, 1};
    cout << sol.missingNumberInArray(nums) << endl;

  
    return 0;
}