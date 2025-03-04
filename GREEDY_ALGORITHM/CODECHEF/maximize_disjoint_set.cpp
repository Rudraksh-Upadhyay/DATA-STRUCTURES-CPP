#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int solve(vector<long long> &arr, long long n, long long d){

    sort(arr.rbegin(), arr.rend());

    long long i = 0;
    // int j = i + 1;
    long long sum =0 ;

    while(i < n-1){
        if(abs(arr[i] - arr[i+1]) < d){
            sum += arr[i] + arr[i+1];
            
            i += 2;
        }
        else{
            i++;
            
        }
    }

    return sum;
}

int main(){

    int t;
    cin>> t;

    while(t--){
        long long n, d;
        cin >> n >> d;

        vector<long long> arr(n);
        for(long long i=0; i<n; i++){
            cin >> arr[i];
        }

        cout << solve(arr, n, d)<<endl;
    }


    return 0;
}