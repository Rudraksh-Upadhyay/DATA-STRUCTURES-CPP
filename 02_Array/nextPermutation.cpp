#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &nums){
    int n = nums.size();

    //find the gola
    int gola_index = -1;

    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            gola_index = i;
            break;
        }
    }

    if(gola_index == -1){
        reverse(nums.begin(), nums.end());
    }
    else{
        //find the next greater element than gola element
        int greater_index = -1;
        int nextGreater = INT_MAX;
        for(int i=n-1; i>gola_index; i--){
            if(nums[i] > nums[gola_index] && nums[i] < nextGreater){
                nextGreater = nums[i];
                greater_index = i;
            }
        }

        swap(nums[gola_index], nums[greater_index]);
        reverse(nums.begin()+gola_index+1, nums.end());
    }
}

void printArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){

    vector<int> nums = {3, 2, 1};

    nextPermutation(nums);

    printArray(nums);

    return 0;
}