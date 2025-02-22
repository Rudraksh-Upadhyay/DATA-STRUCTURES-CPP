#include<iostream>

using namespace std;

class Heap{
    public:
        int* arr;
        int capacity;
        int index;

        Heap(int value){
            this->capacity = value;
            arr = new int[value]();
            index = 0;
        }
};

void heapify(int* arr, int n, int currIndex){
    //n->number of elements in heap
    int i = currIndex;
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



int main(){

    int arr[] = {-1, 10, 20, 30, 40, 50};
    int size = 6;

    builtHeap(arr, size);

    for(int i=1; i<=size-1; i++){
        cout << arr[i] << " " ;
    }


    return 0;
}