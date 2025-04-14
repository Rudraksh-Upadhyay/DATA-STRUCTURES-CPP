/*
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.

Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    int minRemoval(vector<vector<int>> &intervals){
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(ans.back()[1] > intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return n - ans.size();

    }
};

int main(){

    // vector<vector<int>> intervals = {{1,2}, {2, 3}, {3, 4}, {1, 3}};
    // vector<vector<int>> intervals = {{1, 3}, {1, 3}, {1, 3}};
    vector<vector<int>> intervals = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};


    Solution sol = Solution();

    cout << sol.minRemoval(intervals) <<endl;

    return 0;
}