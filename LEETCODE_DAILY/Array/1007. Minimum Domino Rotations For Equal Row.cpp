#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int>mp;
        int n = tops.size();
        for(int i=0; i<n; i++){
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }

        vector<pair<int, int>> arr(mp.begin(), mp.end());
        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        int target = arr[0].first;
        int TopCount = 0;
        int BottomCount = 0;

        for(int i=0; i<n; i++){
            if(tops[i] != target && bottoms[i] != target){
                return -1;
            }
            else if(tops[i] == target && bottoms[i] == target){
                continue;
            }
            else if(tops[i] == target){
                TopCount++;
            }
            else{
                BottomCount++;
            }

        }

        return min(TopCount, BottomCount);
        
    }
};

int main(){

    Solution sol = Solution();

    vector<int> tops = {1,2,1,1,1,2,2,2};
    vector<int> bottoms = {2,1,2,2,2,2,2,2};

    cout << sol.minDominoRotations(tops, bottoms) << endl;

    return 0;
}