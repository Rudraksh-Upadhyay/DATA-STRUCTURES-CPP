#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingNumber(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ansIndex = -1;
    while(s <= e){
        int number = arr[mid];
        int index = mid;
        int diff = number - index;

        if (diff  == 0){
            s = mid+1;
        }

        if (diff == 1){
            ansIndex = index;
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    if(ansIndex == -1){
        return n;
    }
    return ansIndex;
}

int main(){

    vector<int> arr{0,1};
    int ans = missingNumber(arr);
    cout << "missing number->" << ans << endl;
    return 0;
}