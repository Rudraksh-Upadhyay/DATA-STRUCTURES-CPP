#include<bits/stdc++.h>
// #include<cmath.h>
#include<math.h>

using namespace std;

class Solution {
    public:
        bool solve(int n, int x){
            if(n==0){
                return true;
            }
            if(x < 0 && n > 0){
                return false;
            }
    
            if(x > -1 && pow(3, x) <= n){
                int m = pow(3, x);
                return solve(n-m, x-1);
            }       
            if(x > -1 && pow(3, x) > n){
                return solve(n, x-1);
            }
    
            return false;
    
        }
        bool checkPowersOfThree(int n) {
            int x = 0;
            int count = 0;
            while(pow(3, x) <= n){
                count++;
                x++;
            }
            x = count-1;
            return solve(n, x);
        }
    };

int main(){

    int n = 12;
    int x = 0;
    int count = 0;

    while(pow(3, x) <= n){
        count++;
        x++;
    }

    cout << count<<endl;
    
    return 0;
}