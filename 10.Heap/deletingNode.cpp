#include<iostream>
#include<vector>

using namespace std;

void printHeap(vector<int>& arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(vector<int> &arr,int n,  int i){
    // int n = arr.size();
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr,n, largest);
    }

}

void builtHeap(vector<int> &arr){
    int n = arr.size();

    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }
}

void deleteRoot(vector<int> &arr, int& n){
    arr[1] = arr[n-1];
    arr.pop_back();
    n--;
    heapify(arr,n, 1);
}

void deleteKElements(vector<int> &arr, int k){
    int n = arr.size();

    while(k--){
        cout << "deleting root->" <<arr[1]<<endl;
        deleteRoot(arr, n);
    }
}





int main(){

    vector<int> arr = {-1, 3, 5 , 9 , 6 , 8, 20};
    int k = 3;

    builtHeap(arr);
    printHeap(arr);

    deleteKElements(arr, k);

    printHeap(arr);


    return 0;
}