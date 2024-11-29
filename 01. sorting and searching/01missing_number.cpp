#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int missingNumber(vector<int> arr){
    sort(arr.begin(), arr.end()); 
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(mid+1 < n && arr[mid+1] - arr[mid] != 1){
            return arr[mid] + 1;
        }
        if(mid-1 >= 0 && arr[mid] - arr[mid-1] != 1){
            return arr[mid] - 1;
        }
        if(arr[mid] - mid == 0){
            s = mid+1;
        }
        if(arr[mid] - mid != 1){
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){

    vector<int> arr{1,2,3,5,6};
    int ans = missingNumber(arr);
    cout << "missing number->" << ans << endl;
    return 0;
}