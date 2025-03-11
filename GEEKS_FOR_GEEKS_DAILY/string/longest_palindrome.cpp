#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.length();
        int longest = 0;
        
        //max string ka prev index aur next index save krna hoga
        
        int startIndex, endIndex;
        
        //odd case
        for(int i=0 ; i<n-1; i++){
            int prev = i-1;
            int next = i+1;
            int strLength = 1;
            while(prev >= 0 && next < n && s[prev] == s[next]){
                prev--;
                next++;
                strLength += 2;
            }
            
            if(strLength > longest){
                longest = strLength;
                startIndex = prev;
                endIndex = next;
            }
        }

        //even case
        for(int i=0; i<n-1; i++){
            //isme middle element do honge
            int mid = i;
            int nextmid = i+1;
            int strLength = 0;
            while(mid >= 0 && nextmid < n && s[mid] == s[nextmid]){
                mid--;
                nextmid++;
                strLength += 2;
            }
            if(strLength > longest){
                longest = max(longest, strLength);
                startIndex = mid;
                endIndex = nextmid;
            }
        }

        //returning substring from start to end
        return s.substr(startIndex+1, longest);
    }
};

int main(){

    string s = "abc";

    Solution sol = Solution();

    cout << sol.longestPalindrome(s) << endl;

    return 0;
}