#include<bits/stdc++.h>

using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {

    int ans = 0;

    vector<int> newColors = colors;
    for(int i=0; i<k-1; i++){
        newColors.push_back(colors[i]);
    }

    int i = 0;
    int j = i + 1;

    while( j < newColors.size()){
        if(newColors[j] != newColors[j-1]){
            int size = j - i + 1;
            if(size == k){
                ans++;
                i++;
            }
            
            j++;
        }
        else{
            i = j;
            j = i+1;
        }   
    }

    return ans;
    
}

int main(){

    vector<int> arr {1,2,3};

    vector<int> ans = arr;

    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}