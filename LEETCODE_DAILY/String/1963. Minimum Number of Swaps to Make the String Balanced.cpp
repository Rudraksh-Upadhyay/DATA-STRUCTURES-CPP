#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int i = 0;

        int n = s.length();

        int count = 0;

        while(i < n){
            if(s[i] == '['){
                //open bracket means -> balance krna hai
                count++;
                
            }
            else if(s[i] == ']' && count > 0){ 
                count--; //means balanced ho gaya
            }
            i++;
        }
        return (count + 1) / 2;
    }
};

int main(){

    string s= "] ] ] ] [ ] [ [ [ [";

    Solution sol = Solution();

    cout << sol.minSwaps(s) << endl;

    return 0;
}