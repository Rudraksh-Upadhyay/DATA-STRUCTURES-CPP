#include<bits/stdc++.h>

using namespace std;

vector<int> findMajority(vector<int> &arr){
    int n = arr.size();

    vector<int> result;

    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto& it: mp){
        if(it.second > n/3){
            result.push_back(it.first);
        }
    }

    return result;
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans = findMajority(arr);
    sort(ans.begin(), ans.end());
    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}