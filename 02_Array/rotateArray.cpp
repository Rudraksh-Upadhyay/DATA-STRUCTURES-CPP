#include<bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, int k){
    
    // int n = arr.size();

    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k , arr.end());
    reverse(arr.begin(), arr.end());

}
void print(vector<int> &arr){
    for(auto x : arr){
        cout << x << " ";
    }
    cout<< endl;
}

int main(){

    vector<int> arr = {1, 2, 3, 4};
    rotate(arr, 3);
    print(arr);


    return 0;
}