#include<iostream>

using namespace std;

bool checkSorted(int arr[], int n, int index){

    //base case
    if(index == n-1){
        //single element sorted hota hai
        return true;
    }

    bool currAns = false;
    bool recAns = false;

    //1 case
    if(arr[index + 1] > arr[index]){
        currAns = true;
    }

    recAns = checkSorted(arr, n, index+1);

    // if(currAns && recAns){
    //     return true;
    // }
    // else{
    //     return false;
    // }

    return (currAns && recAns);
}

int main(){

    int arr[] = {10, 20, 30, 40};
    int size = 4;

    cout << checkSorted(arr, size, 0);

    return 0;
}