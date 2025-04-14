#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<vector<int>> arr = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    });

    for(auto &x : arr){
        cout << "{";
        for(auto &y : x){
            cout << y << ", " ;
        }
        cout << "}" << "  ";
    }

    return 0;
}