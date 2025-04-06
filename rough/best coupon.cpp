/*
Chef is ordering food online (instead of cooking) and the bill comes out to be Rs. 
X
X. Chef can use one of the following two coupons to avail a discount.

Get 
10
10 percent off on the bill amount
Get a flat discount of Rs. 
100
100 on the bill amount
What is the maximum discount Chef can avail?
*/
#include<bits/stdc++.h>

using namespace std;

int main(){


    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;

        int d1 = x * 0.1;  // 10% discount
        int d2 = 100;      // flat discount of Rs. 100

        cout << max(d1, d2) << endl;
    }

    return 0;
}