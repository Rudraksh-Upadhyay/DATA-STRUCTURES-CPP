#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    int minOperations(vector<int> &arr, int k){
        int n = arr.size();
        //2 cheeje dekhenge
        unordered_set<int> st;

        //arr[i] < k nahi hona chahiye
        for(int i=0; i<n; i++){
            
            if(arr[i] < k){
                return -1;
            }

            if(arr[i] > k){
                st.insert(arr[i]);
            }
        }

        //set size count return kr denge
        return st.size();

    }

};

int main(){

    Solution sol = Solution();

    vector<int> arr = {9,7,5,3};

    int k = 1;

    cout << sol.minOperations(arr, k) <<endl;


    return 0;
}