#include<iostream>

using namespace std;

int binarySearch(int arr[], int s, int e, int size, int target){
    if(s > e){
        return -1;
    }

    //1 case mai sambhalunga
    //baaki recursion krega
    int mid = (s+e)/2;

    if (arr[mid] == target){
        return mid;
    }

    //recurrsion
    else if(target < arr[mid]){
        return binarySearch(arr, s, mid-1, size, target);
    }
    else if(target > arr[mid]){
        return binarySearch(arr,mid+1, e, size, target);
    }
    
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int target = 20;
    cout << binarySearch(arr, 0, 5, size, target);

    return 0;
}