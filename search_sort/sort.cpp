#include<iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin >> n;
    
    vector<int> arr;
    for(int i=0;i<n; i++){
            int value;
            cin >> value;
            arr.push_back(value);
    }
    
    vector<int> res;
    
    for(int i=0;i<n-1; i++){
            int max_ele = -1;
            int x = 1;
            while(x--){

                for(int j=i+1; j<n; j++){
                        if(arr[j] > max_ele){
                                max_ele = arr[j];
                        }
                        // break;
                }
            }
            res.push_back(max_ele);
    }
    
    res.push_back(-1);
    
    for(int x : res){
            cout << x << " ";
    }
    return 0;
}
