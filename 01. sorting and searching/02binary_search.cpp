#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int target = 30;

    bool ans = binary_search(arr, arr+size, target);

    cout << ans << endl;
    return 0;
}