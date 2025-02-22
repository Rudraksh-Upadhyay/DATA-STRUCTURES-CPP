#include<iostream>
#include<vector>

using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;
        while(j >= 0){
            if (arr[j] > key){
                swap(arr[j], arr[i]);
                i = j;
                j--;
            }
            else{
                break;
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main(){

    int arr[] = {10, 5, 8, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);
    

    return 0;
}