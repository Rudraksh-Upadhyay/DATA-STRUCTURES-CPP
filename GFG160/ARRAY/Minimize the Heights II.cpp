/*
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.
*/

#include<bits/stdc++.h>

using namespace std;

int getMinDiff(vector<int> &arr, int k){
    int n = arr.size();
    sort(arr.begin(), arr.begin());

    int longest = arr[n-1];
    int shortest = arr[0];

    //initial ans....isko update krna hai
    int ans = longest - shortest;

    //ek ek ko mid mark krenge...
    //mid se right mei 'k' minus kr denge
    //mid ke left mei 'k' plus kr denge
    // phir longest aur shortest ko update kr denge and ans ko update kr denge

    for(int i=1; i<n; i++){
        int mid = i;

        longest = max(arr[n-1] - k, arr[mid - 1] + k);
        shortest = min(arr[0] + k, arr[mid] - k);

        //shortest -ve nahi hona cahhiye
        if(shortest < 0){
            continue;
        }

        ans = min(ans, longest - shortest);
    }

    return ans;


}

int main(){

    vector<int> arr = {3, 9, 12, 16, 20};
    int k = 3;

    cout << getMinDiff(arr, k) << endl;


    return 0;
}