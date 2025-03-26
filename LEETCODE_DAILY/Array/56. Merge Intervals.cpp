#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> & intervals){
    int n = intervals.size();
    //sabse pehle..intervals ko sort krenge
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    //pehle toh first element ko push krdo
    result.push_back(intervals[0]);

    for(int i=1; i<n; i++){
        if(result.back()[1] >= intervals[i][0]){
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main(){

    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = merge(arr);

    for(auto &x : ans){
        for(auto &y : x){
            cout << y << ", ";
        }
        cout<< " ";
    }
    cout << endl;

    return 0;
}