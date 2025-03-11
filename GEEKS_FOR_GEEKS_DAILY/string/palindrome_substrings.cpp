#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    int countPS(string &s){
        int n = s.length();
        int count = 0;

        //even case-> two elements will be there in the middle of palindrome
        for(int i=0; i<n-1; i++){
            int mid = i;
            int midNext = i+1;
            while(mid >= 0 && midNext < n && s[mid] == s[midNext]){
                count++;
                mid--;
                midNext++;
            }
        }
        

        //odd case-> one element will be there in the middle of palindrome
        for(int i=1; i<n-1; i++){
            int prev = i-1;
            int next = i+1;
            while(prev >= 0 && next < n && s[prev] == s[next]){
                count++;
                prev--;
                next++;
            }
        }

        return count;
    }
};

int main(){

    string s = "abbaeae";
    Solution sol = Solution();
    cout << sol.countPS(s);


    return 0;
}