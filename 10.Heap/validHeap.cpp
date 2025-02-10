#include<iostream>

using namespace std;

bool solve(int* arr, int n){
    int index = 1;

    while(index <= n){
        int left = 2*index;
        int right = 2*index + 1;

        if(left <= n && arr[left] < arr[index]){
            return false;
        }
        if(right <= n && arr[right] < arr[index]){
            return false;
        }

        index++;
    }

    return true;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        arr[0] = -1;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        //Write you code to check if the arr represents a heap
        bool ans = solve(arr, n);
        // cout<< ans <<endl;
        if(ans){
            cout << "YES"<<endl;
            
        }
        else{
            cout << "NO"<<endl;
        }
    }


    return 0;
}