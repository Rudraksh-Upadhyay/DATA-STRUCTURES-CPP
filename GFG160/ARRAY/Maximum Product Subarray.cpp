#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &arr){
    int n = arr.size();
    int minProd = arr[0];
    int maxProd = arr[0];
    int result = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] < 0) swap(maxProd, minProd);
        minProd = min(arr[i], minProd * arr[i]);
        maxProd = max(arr[i], maxProd * arr[i]);

        result = max(result, maxProd);
    }

    return result;
}

int main(){

    vector<int> arr = {-2, 6, -3, -10, 0, 2};

    cout << maxProduct(arr) << endl;

    return 0;
}