#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval){
        intervals.push_back(newInterval);
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;

            
    }
};

int main(){

    vector<vector<int>> intervals = {{1, 2}, {3,5 }, {6, 7}, {8, 10}, {12, 16}};;
    vector<int> newInterval = {4, 9};

    Solution sol = Solution();

    vector<vector<int>> ans = sol.insertInterval(intervals, newInterval);

    for(auto &x : ans){
        for(auto &y : x){
            cout << y << " " ;
        }
    }
    cout << endl;

    return 0;
}