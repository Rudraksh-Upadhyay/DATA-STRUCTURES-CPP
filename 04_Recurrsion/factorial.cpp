#include<iostream>

using namespace std;

int getFactorial(int n){

    // base case
    if(n ==0){
        return 1;
    }

    int ans = n * getFactorial(n-1);

    return ans;
}

int main(){

    cout << "Enter the number->" ;
    int n;
    cin >> n;

    cout << "Factorial of the entered number->" << getFactorial(n)<<endl;

    return 0;
}