#include<bits/stdc++.h>

using namespace std;

class Solution{
    typedef long long ll;
    private:

    bool isPossible(vector<int>&ranks, ll mid, int cars){
        int n = ranks.size();
        ll carsRepaired = 0;

        for(int i=0; i<n ;i++){
            carsRepaired += sqrt(mid/ ranks[i]);
            if(carsRepaired >= cars) return true; //early return
        }

        return carsRepaired >= cars;
    }

    public:

    long long repairCars(vector<int> &ranks, int cars){
        // int n = ranks.size();

        ll l = 1;
        ll maxR = *max_element(begin(ranks), end(ranks));
        ll r = maxR * cars * cars ;  // time taken to repair a car by a mechanic-> r * (n)^2

        ll result = -1;

        while(l <= r){
            ll mid = l + (r-l)/2 ;

            if(isPossible(ranks, mid, cars)){
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

    vector<int> ranks{5, 1, 8};
    int cars = 6;

    Solution sol = Solution();

    cout << sol.repairCars(ranks, cars)<<endl;


    return 0;
}