#include<bits/stdc++.h>

using namespace std;

int solve(string s, int k){

    unordered_map<char, int> mp;

    for(auto x : s){
        mp[x]++;
    }

    vector< pair<char, int> > vec(mp.begin(), mp.end());

    // sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
    //     return a.second > b.second;
    // });

    int i =0;

    while(k--){
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
        if(vec[i].second == 0){
            i++;
            k++;
        }
        vec[i].second--;
    }

    int ans = 0;
    for(auto x : vec){
        ans += x.second * x.second;
    }

    return ans;
}

int main(){

    string s= "ccbcbd";
    int k = 3;

    cout << solve(s, k) <<endl;

    return 0;
}