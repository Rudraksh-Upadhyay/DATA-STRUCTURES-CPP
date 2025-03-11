#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class Solution{
    public:

        void solve(int n, long long &ans){

            if(n == 1){
                ans = ans + 1;
                return;
            }
            ans = ans + (4 * (n-1));
            solve(n-1, ans);
            
        }
        long long coloredCells(int n){
            if(n == 1){
                return 1;
            }
            long long ans = 0;
            solve(n, ans);
            return ans;
        }
};

int main(){

    Solution a = Solution();
    
    cout << a.coloredCells(3) << endl;

    return 0;
}