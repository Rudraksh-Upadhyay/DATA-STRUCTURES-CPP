#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    int hIndex(vector<int> &citations){
        //descending order mei sort krenge
        sort(citations.begin(), citations.end(), greater<int>());

        int n = citations.size();

        int h_index = 0;

        for(int i=0; i<n; i++){
            if(citations[i] >= i+1){
                h_index++;
            }
        }
        return h_index;

    }
};

int main(){

    Solution sol = Solution();

    vector<int> arr = {5, 1, 2, 4, 1};

    cout << sol.hIndex(arr) << endl;
    

    return 0;
}