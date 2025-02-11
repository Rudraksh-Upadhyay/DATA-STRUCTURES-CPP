#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        arr.push_back(value);
    }

    bubbleSort(arr, n);

    for(int x : arr){
        cout << x <<  " ";
    }

    return 0;
}