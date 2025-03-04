#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int solve(vector<int> &arr, int n, int k){
    sort(arr.begin(), arr.end());
    int arr_sum = accumulate(arr.begin(), arr.end(), 0);

    //case 1
    int son = 0;
    int son_sum = 0;
    int chef_sum  =0;


    for(int i=0; i<k; i++){
        son_sum += arr[son];
        son++;
    }

    chef_sum = arr_sum - son_sum;

    int diff1 = abs(son_sum - chef_sum);

    //case 2
    son = n-1;
    son_sum = 0;
    chef_sum = 0;

    for(int i=0 ; i<k ; i++){
        son_sum += arr[son];
        son--;
    }

    chef_sum = arr_sum - son_sum;

    int diff2 = abs(son_sum - chef_sum);

    return max(diff1, diff2);
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin>> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int ans = solve(arr, n, k);
        cout << ans <<endl;
    }


    return 0;
}