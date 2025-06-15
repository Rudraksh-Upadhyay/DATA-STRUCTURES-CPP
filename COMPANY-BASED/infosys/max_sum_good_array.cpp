#include<bits/stdc++.h>

using namespace std;

int maxGoodArraySum( vector<int> &arr, int k){
    int n = arr.size();
    int maxSum = 0;
    int currSum = 0;

    int l  = 0;

    unordered_map<int, int> freq;


    for(int r =0; r<n; r++){
        freq[arr[r]]++;
        currSum += arr[r];

        while(freq.size() > k){
            freq[arr[l]]--;
            currSum -= arr[l];

            if(freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }
            l++;
        }

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    
    int k = 2;

    vector<int> arr = {1, 2, 2, 3, 2, 3, 5, 1, 2, 1, 1};

    cout << maxGoodArraySum(arr, k) << endl;


    return 0;
}