// LEETCODE 33

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int PivotInRotatedArray(vector<int> &arr){
        int s = 0;
        int e = arr.size();
        int mid = s + (e-s)/2;

        while(s < e){
            if(mid+1 < e && arr[mid] < arr[mid+1] && arr[mid] >= arr[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return mid;
    }

    int binarySearch(int s, int e, int target, vector<int> arr){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] == target){
                return mid; 
            }
            if(target > arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return -1;

    }

    int SearchInRotatedArray(vector<int> &arr, int target){

        int pivot = PivotInRotatedArray(arr);

        int n = arr.size();

        // LINE A
        if(target >= arr[0] && target <= arr[pivot]){

            int ans = binarySearch(0, pivot, target, arr);
            return ans;
        }
        
        // LINE B
        if(pivot+1 < n && target >= arr[pivot+1] && target <= arr[pivot]){

            int ans = binarySearch(pivot+1, n-1, target, arr);
            return ans;
        }

        
        return -1;
    }
};

int main(){
    vector<int> arr{50, 60, 70, 10, 20, 30};
    int target = 20;
    Solution sol = Solution();
    // int ans = sol.PivotInRotatedArray(arr);
    // cout<<"index->" << ans<<endl;

    int index = sol.SearchInRotatedArray(arr, target);
    cout << "index-> " << index << endl;

    return 0;
}