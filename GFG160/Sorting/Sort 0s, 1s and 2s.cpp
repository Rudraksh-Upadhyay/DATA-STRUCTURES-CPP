#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:

    void merge(vector<int> &arr, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> l(n1), r(n2);

        for(int i=0; i<n1; i++){
            l[i] = arr[left + i];
        }
        for(int j=0; j<n2; j++){
            r[j] = arr[mid + 1 + j];
        }

        int i =0, j = 0, k = left;

        while(i < n1 && j < n2){
            if(l[i] <= r[j]){
                arr[k++] = l[i++];
            }
            else{
                arr[k++] = r[j++]; 
            }
        }
        //bache hue bhi dalne hote hai
        while(i < n1){
            arr[k++] = l[i++];
        }
        while(j < n2){
            arr[k++] = r[j++];
        }
    }

    void mergeSort(vector<int> &arr, int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;
            
            //first aur second half ko sort krenge
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            //merge kr denge dono sorted left aur right array ko
            merge(arr, left, mid, right);
        }
    }
    public:

    void sort012(vector<int> &arr){
        int n =arr.size();
        mergeSort(arr, 0, n-1);
    }

    void printArray(vector<int> &arr){
        for(auto &x : arr){
            cout << x << " ";
        }
        cout << endl;
    }
};

int main(){

    vector<int> arr = {0, 1, 2, 0, 1, 2};

    Solution sol = Solution();

    sol.sort012(arr);
    sol.printArray(arr);

    return 0;
}