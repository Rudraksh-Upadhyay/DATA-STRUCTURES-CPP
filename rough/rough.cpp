#include<bits/stdc++.h>

using namespace std;


vector<int> sumInRanges(vector<int> &arr, vector<vector<long long>> &queries) {
    // Write your code here
    vector<int> ans;
    for(auto x : queries){
        int left = x[0] - 1 ;
        int right = x[1] - 1;

        int sum = 0;

        int n = arr.size();

        int i = left;

        while(i <= right){
            int index = i % n;
            sum += arr[index];
            i++;
        }

        ans.push_back(sum);


    }
    return ans;
}

int main(){

    vector<int> arr = {5, 2, 6, 9};
    vector<vector<long long>> queries = {{1, 5}, {10, 13}, {7, 11}};

    vector<int> ans = sumInRanges(arr, queries);

    for(auto x : ans){
        cout << x << " ";
    }

    return 0;

}