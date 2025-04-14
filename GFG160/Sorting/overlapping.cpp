#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    vector<vector<int>> overlapping (vector<vector<int>> &arr){
        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        ans.push_back(arr[0]);

        for(int i=1; i<n; i++){
            if(ans.back()[1] >= arr[i][0]){
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

int main(){

    vector<vector<int>> arr = {{6,8}, {1,9}, {2,4}, {4, 7}};

    Solution sol = Solution();

    vector<vector<int>> ans = sol.overlapping(arr);

    for(auto &x : ans){
        for(auto &y : x){
            cout << y << " " ;
        }
    }
    cout << endl;


    return 0;
}