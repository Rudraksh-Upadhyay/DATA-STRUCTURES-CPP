/*
Stack Sort
You have an array 
A
A of integers of size 
N
N, an array 
B
B ( initially empty ) and a stack 
S
S ( initially empty ). You are allowed to do the following operations :

Take the first element of array 
A
A and push it into 
S
S and remove it from 
A
A.
Take the top element from stack 
S
S, append it to the end of array 
B
B and remove it from 
S
S.
You have to tell if it possible to move all the elements of array 
A
A to array 
B
B using the above operations such that finally the array 
B
B is sorted in ascending order*/


#include<iostream>
#include<vector>
#include<stack>


using namespace std;

bool isSorted(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

void AtoS(vector<int> &arr, stack<int> &s, int i){
    s.push(arr[i]);
}

void StoB(vector<int> &brr, stack<int> &s){
    brr.push_back(s.top());
    s.pop();
}

bool checkSorted(vector<int> &arr, int n){
    stack<int> s;
    vector<int> brr;

    for(int i=0; i<n; i++){
        AtoS(arr, s, i);
        
        // while(!s.empty() && (brr.size() == 0 || s.top() >= brr[brr.size() - 1])){
        //     StoB(brr, s);
        // }
        if(arr[i+1] < s.top()){
            continue;
        }

        if (!s.empty() && (brr.size() == 0 || s.top() >= brr[brr.size() - 1])){
            StoB(brr, s);

          
        }


    }

    while(!s.empty()){
        StoB(brr, s);
    }

    return isSorted(brr);
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        bool result = checkSorted(arr, n);
        if(result){
            cout << "YES"<<endl;

        }

        else{
            cout << "NO"<<endl;
        }
    }

    return 0;
}