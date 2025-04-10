/*
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

*/

#include<bits/stdc++.h>

using namespace std;

void computeLPS(string &str, vector<int> &lps){
    int n= str.length();
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while( i < n){
        if(str[i] == str[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else{
            if(length!=0){
                length = lps[length-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minCharToMakePalindrome(string str){
    string rev = str;
    reverse(rev.begin(), rev.end());
    string temp = str + "#" + rev;

    vector<int> lps(temp.length(), 0);

    for(int i =1; i < temp.length(); i++){
        int len = lps[i-1];
        while(len > 0 && temp[i] != temp[len]){
            len = lps[len-1];
        }
        if(temp[i] == temp[len]) len++;
        lps[i] = len;
    }

    return str.length() - lps.back();
}

int main(){

    string str = "aacecaaaa";

    cout << minCharToMakePalindrome(str) << endl;

    return 0;
}