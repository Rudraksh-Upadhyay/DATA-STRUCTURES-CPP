/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of 
s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "". 
*/

#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t){
    int  n = s.length();
    int m = t.length();

    if(m > n){
        return "";
    }
    unordered_map<char, int> mp;
    for(char ch : t){
        mp[ch]++;
    }

    int reqCount = t.length();

    int i=0, j =0;

    int minWinSize = INT_MAX;
    int start_i = 0;

    while(j < n){
        char c = s[j];

        if(mp[c] > 0){  //means c is present in t hence required
            reqCount--;
        }
        mp[c]--;

        while(reqCount == 0){
            int currWinSize = j - i + 1;

            if(minWinSize > currWinSize){
                minWinSize = currWinSize;
                start_i = i;
            }

            char ch= s[i];

            mp[ch]++;

            if(mp[ch] > 0){
                reqCount++;
            }
            i++;
        }
        j++;

    }

    return minWinSize == INT_MAX ? "" : s.substr(start_i, minWinSize);

}

int main(){

    string s= "ADOBECODEBANC";
    string t = "ABC";

    string ans = minWindow(s, t);

    cout << ans << endl;
    return 0;
}