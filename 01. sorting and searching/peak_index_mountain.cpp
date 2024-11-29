#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int peakIndexInMountainArray(vector<int> &arr){
        int s  = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s < e){
            if(arr[mid] < arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }

            mid = s + (e-s)/2;
        }
        return s;
    }

};

int main(){

    Solution a = Solution();
    vector<int> arr{10,20,30,40,25,15};

    int ans = a.peakIndexInMountainArray(arr);
    cout<< "peak element index->" << ans << endl;   

    return 0;
}