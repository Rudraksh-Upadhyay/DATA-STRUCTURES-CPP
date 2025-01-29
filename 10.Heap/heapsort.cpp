#include<iostream>

using namespace std;

class Heap{
    public:

        int *arr;
        int capacity;
        int index;

        Heap(int value){
            this->capacity = value;
            arr = new int[value]();
            index = 0;
        }

        
};

void heapify(int* arr, int n, int currIndex){
    int i=currIndex;
    int leftIndex = 2*i;
    int rightIndex = 2*i + 1;

    int largestIndex = i;

    if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }

    if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }

    if(largestIndex != i){
        swap(arr[largestIndex], arr[i]);
        i = largestIndex;
        heapify(arr, n, i);
    }
}

void builtHeap(int* arr, int n){
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }
}


void heapSort(int* arr, int n){

    int e = n-1;

    while(e > 1){
        //delete root element, swap 
        swap(arr[1], arr[e]);
        e--;
        heapify(arr, e+1, 1);
    }

}

int main(){

    int arr[] = {-1, 10, 20, 30, 40, 50};
    int n = 6;

    builtHeap(arr, n);

    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}