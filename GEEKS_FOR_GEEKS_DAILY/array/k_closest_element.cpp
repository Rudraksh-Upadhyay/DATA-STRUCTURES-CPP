#include<bits/stdc++.h>
using namespace std;

vector<int> printKClosest(vector<int> arr, int k, int x){
    int n = arr.size();
    vector<int> diffArray(n, 0);

    for(int i=0; i<n; i++){
        diffArray[i] = abs(arr[i] - x);
    }

    unordered_map<int , int> mp;

    for(int i=0; i<n; i++){
        if(mp.find(diffArray[i]) != mp.end() && mp[diffArray[i]] > arr[i]){
            mp.erase(diffArray[i]);
        }
        mp[diffArray[i]] = arr[i];
    }

    priority_queue<pair<int, int>> pq;
}

int main(){


    return 0;
}