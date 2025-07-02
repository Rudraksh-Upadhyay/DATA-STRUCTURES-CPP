#include<bits/stdc++.h>

using namespace std;

int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();
    int total = 1<<n;
    int count = 0;

    for(int mask = 0; mask < total; mask++){
        vector<int> subs;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                subs.push_back(nums[i]);
            }
        }
        if(subs.empty()) continue;
        int minValue = *min_element(subs.begin(), subs.end());
        int maxValue = *max_element(subs.begin(), subs.end());
        if (minValue + maxValue <= target) count++;

    }
    return count;
}

int main(){

    vector<int> nums= {3, 3, 6, 8};
    int target = 10;

    cout << numSubseq(nums, target) << endl;


    return 0;
}