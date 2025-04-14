#include<bits/stdc++.h>

using namespace std;

class Solution{
    // int count = 0;
    private:
    void merge(vector<int> &arr, int left, int mid, int right, int &count){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> l(n1), r(n2);

        for(int i=0; i<n1; i++){
            l[i] = arr[left + i];
        }
        for(int j=0; j<n2; j++){
            r[j] = arr[mid + 1 + j];
        }

        int i=0;
        int j = 0;
        int k = left;

        while( i < n1 && j < n2){
            if(l[i] <= r[j]){
                arr[k++] = l[i++];
            }
            else{
                arr[k++] = r[j++];
                count += n1 - i;
            }
        }

        while(i < n1){
            arr[k++] = l[i++];
        }
        while(j < n2){
            arr[k++] = r[j++];
        }
        

    }

    void mergeSort(vector<int> &arr, int left, int right, int &count){
        // int count= 0;
        if(left < right){
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, count);
            mergeSort(arr, mid+1, right, count);

            merge(arr, left, mid, right,count);
        }
    }


    public:


    int inversionCount_brute(vector<int> &arr){
        int n = arr.size();

        int count = 0;

        for(int i=0; i<n-1; i++){  // n^2 solution
            for(int j= i+1; j<n; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count;
    }

    int inversionCount_optimal(vector<int> &arr){
        int n = arr.size();

        int count = 0;
        mergeSort(arr, 0, n-1, count);

        return count;
    }
};

int main(){

    vector<int> arr = {5, 3, 2, 4, 1};

    Solution sol = Solution();

    cout << sol.inversionCount_optimal(arr) <<endl;

    return 0;
}