#include<bits/stdc++.h>

using namespace std;

int trap(string s){
    int n = s.length();
    if(n== 0) return 0;

    vector<int> heights(n, 0);

    for(int i=0; i< n ; i++){
        heights[i] = int(s[i]);
    }

    vector<int> leftMax(n), rightMax(n);


    //pehle leftMax calculate krenge harr character ka
    leftMax[0] = heights[0];

    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], heights[i]);
    }

    //then rightMax calculate krenge harr character ka
    rightMax[n-1] = heights[n-1];

    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], heights[i]);
    }

    int ans = 0;
    for(int i=0; i<n ; i++){
        ans += min(leftMax[i], rightMax[i]) - heights[i];
    }

    return ans;

}

int main(){

    string s = "ZOPSMART";

    cout << trap(s) << endl;

    return 0;
}