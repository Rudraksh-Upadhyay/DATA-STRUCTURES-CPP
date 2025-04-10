/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

vInput: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.

Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.

Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
*/

#include<bits/stdc++.h>

using namespace std;

bool areRotations(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    int n = s1.length();
    while(n--){
        s1 = s1.substr(1) + s1[0];
        if(s1 == s2){
            return true;
        }
    }
    return false;
}

bool areRotations_optimal(string s1, string s2){
    string temp = s1 + s1;

    return temp.find(s2) != string::npos;
}

class Solution{
    private:
    void computeLPS(string &pat, vector<int> &lps){
        int n = pat.length();
        int length = 0;
        lps[0] = 0;
        int i=1;

        while( i < n){
            if(pat[i] == pat[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = lps[length-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool kmp(string pat, string txt){
        int m = pat.length();
        int n = txt.length();
        vector<int> lps(m, 0);
        computeLPS(pat, lps);

        int i =0; 
        int j =0 ;

        while (i < n){
            if(pat[j] == txt[i]){
                j++;
                i++;
            }
            if(j == m){
                return true;
            }
            else if(pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
    public:
    bool areRotations(string s1, string s2){
        string temp = s1 + s1;
        return kmp(s2, temp);
    }
};

int main(){

    string s1 = "abcd", s2 = "cdab";

    Solution sol = Solution();

    cout << sol.areRotations(s1, s2) << endl;


    return 0;
}