#include<bits/stdc++.h>

using namespace std;

int findUnique(vector<int> &arr){
    int n = arr.size();
    int result = 0;

    for(int i=0; i<n; i++){
        result ^= arr[i];
    }

    return result;
}

unordered_map<int, int> mp;

void makeSet(vector<int> &arr){
    // int n = arr.size();

    for(int &x : arr){
        mp[x]++;
    }
}


bool canMakePairs(){

    for(auto x : mp){
        if(x.second%2 != 0){
            return false;
        }
    }
    return true;
}


int main(){

    vector<int> arr{9,9,19,10,9,12,2,12,3,3,11,5,8,4,13,6,2,11,9,19,11,15,9,17,15,12,5,14,12,16,18,16,10,3,8,9,16,20,2,4,16,12,11,14,20,16,2,18,17,20,3,13,16,17,1,1,11,20,20,4};

    // cout << findUnique(arr)<<endl;

    makeSet(arr);

    // for(auto x : mp){
    //     cout << x.first << " " << x.second << endl;
    // }

    bool ans = canMakePairs();

    cout <<ans;

    return 0;
}