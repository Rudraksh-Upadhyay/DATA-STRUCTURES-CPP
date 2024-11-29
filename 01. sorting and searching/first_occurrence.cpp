#include<iostream>

using namespace std;

void firstOccurence(int arr[], int n, int target, int &ans){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e){
        
        if (arr[mid] == target){
            // means-> first occurence ho bhi sakta hai nahi bhi
            ans = mid;
            e = mid-1;
        }

        if (target < arr[mid]){
            e = mid-1;
        }
        if(target > arr[mid]){
            s = mid+1;
        }

        mid = s + (e-s)/2;
    }


}

int main(){
    int arr[] = {10, 20 , 20, 20, 30, 40, 50};
    int n = 7;
    int target = 20;
    int ans = -1;

    firstOccurence(arr, n, target, ans);

    cout << "first occurence of target element->" << ans << endl;
    return 0;
}