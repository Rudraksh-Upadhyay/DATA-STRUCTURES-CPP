#include<iostream>

using namespace std;

bool searchElement(int array[], int index, int target, int size){
    if(index >= size){
        return false;
    }

    if(array[index] == target){
        return true;
    }
    
    bool ans =  searchElement(array, index+1, target, size);

    return ans;
    
}

int main(){

    int arr[] = {10, 30, 40, 50};
    int n = 4;
    int target = 40;

    cout << "target found? " << searchElement(arr, 0, target, n) << endl;

    return 0;
}