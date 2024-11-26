#include<iostream>

using namespace std;


//jab bhi tum kisi function ke ander koi answer store krne wala variable send kro toh
// jiske undre harr function call ke saath tum answer ko store krna chahte ho...answer ko track krna 
// chahte ho...toh you hove to make sure ki tum usko by reference send kro
void maxInArray(int array[], int size, int index, int &maximum){ // &maximum by reference
    if(index == size){
        return;
    }


    maximum = max(array[index], maximum);

    maxInArray(array, size, index+1, maximum);
}

int main(){

    int maximum = INT_MIN;
    int array[] = {10, 30, 50};
    int size = 3;

    maxInArray(array, size, 0, maximum);
    
    cout << "max->"<< maximum << endl;

    return 0;
}