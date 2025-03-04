#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int solve(vector<long int> &arr, int n, int d){

    long int i = 0;
    long int j = i + 1;
    long int count = 0;  

    while(j < n){
        if((arr[i] - arr[j]) <= d){
            count++;
            i = j + 1;
        }
        else{
            i = i + 1;
        }
        j = i + 1;
    }

    return count;

}

int main(){

    long int n, k;
    cin >> n >> k;

    vector<long int> arr(n);
    for(long int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long int ans = solve(arr, n, k);

    cout << ans <<endl;

    return 0;
}