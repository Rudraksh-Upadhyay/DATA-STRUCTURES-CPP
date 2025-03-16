//LEETCODE 875

#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:

    bool isPossible(vector<int>& piles, int mid, int h){
        int n = piles.size();
        int hours = 0;

        for(int i=0; i<n; i++){
            // hours += ceil(piles[i] / mid);
            // if(hours > h) return false;

            hours += piles[i]/mid;

            if(piles[i] % mid > 0){
                hours++;
            }
        }

        return hours <= h;
    }

    public:

    int minEatingSpeed(vector<int> &piles, int h){
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        int result = -1;

        while(l <= r){
            int mid = l + (r-l)/2; //bananas per hours per pile

            if(isPossible(piles, mid, h)){
                result = mid;
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }

        return result;
    }
};

int main(){


    vector<int> piles {30,11,23,4,20};
    int h = 5;

    Solution sol = Solution();

    cout << sol.minEatingSpeed(piles, h)<<endl;

    return 0;
}