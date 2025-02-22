/*
You are given a 0-indexed integer array nums, and an integer k.

In one operation, you will:

Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
    public:
    
        bool check(vector<int> &arr, int k){
            // long n = arr.size();
            for(int num : arr){
                if(num < k){
                    return false;
                }
            }
            return true;
        }
    
        void solve(vector<int> &arr){
            long long first = -1;
            long long second = -1;
    
            auto min_index = min_element(arr.begin(), arr.end());
            first = *min_index;
    
            *min_index = LONG_MAX;
    
            auto min_second_index = min_element(arr.begin(), arr.end());
            second = *min_second_index;
    
            *min_index = first;
    
            arr.erase(remove(arr.begin(), arr.end(), first), arr.end());
            arr.erase(remove(arr.begin(), arr.end(), second), arr.end());
    
            long long new_element = (min(first, second) * 2) + max(first, second);
    
            arr.push_back(new_element);
        }
    
    
        int minOperations_mine(vector<int>& nums, int k) {
            // solve(nums, k);
            int count  =0;
            while(!check(nums, k)){
                solve(nums);
                count++;
            }
            return count;
        }

        int minOperations_priority_queue(vector<int>&nums, int k){
            int count = 0;

            //CREATE MIN HEAP 
            priority_queue<long long, vector<long long>, greater<long long>> min_heap(nums.begin(), nums.end());

            while(!min_heap.empty()){
                long long min1 = min_heap.top();
                min_heap.pop();

                if(min1 >= k){
                    break;
                }

                long long min2 = min_heap.top();
                min_heap.pop();

                long long element = ((min(min1, min2) * 2) + max(min1, min2));
                min_heap.push(element);

                count++;
            }

            return count;
        }


    };
int main(){

    return 0;
}