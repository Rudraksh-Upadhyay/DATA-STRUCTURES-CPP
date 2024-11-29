//LEETCODE 1910

#include<iostream>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string pattern) {
        
        while(s.find(pattern) != string::npos){
            //s string mei se pattern erase kr do
            s.erase(s.find(pattern), pattern.length());
        }
        return s;
    }


    string newRemoveOccurrences(string s, string pattern){
        int findPatterIndex = s.find(pattern);
        // yeh apko...pattern ke occurence ka first index return kr dega

        while(findPatterIndex != -1){
            s.erase(findPatterIndex, pattern.length());
            findPatterIndex = s.find(pattern);
        }

        return s;

    }
};

int main(){
    Solution sol = Solution();
    string s = "kashish";
    string pattern = "ash";
    string ans = sol.newRemoveOccurrences(s, pattern);
    cout<<ans<<endl;
    return 0;
}