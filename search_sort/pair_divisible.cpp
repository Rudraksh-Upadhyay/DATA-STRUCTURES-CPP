#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> arr;

    for(int i=0; i<n ;i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    for(auto x : arr){
        int a = (x.first) + (x.second);
        if(a % k == 0){
            cout << "(" << x.first << ", " << x.second << ")" <<endl;
        }
    }
    return 0;
    
}