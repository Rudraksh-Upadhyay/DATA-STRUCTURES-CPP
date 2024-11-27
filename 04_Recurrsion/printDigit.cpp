#include<iostream>

using namespace std;

void printDigit(int n){
    if(n==0){
        return ;
    }

    int newNumber = n / 10;
    printDigit(newNumber);

    int digit = n % 10;
    cout << digit << " ";
}

int main(){

    int n = 123;
    printDigit(n);
    
    return 0;
}