/*
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: word = "aabbccdd", k = 7

Output: 5

Explanation:

The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".

Example 2:

Input: word = "aabbccdd", k = 8

Output: 1

Explanation:

The only possible string is "aabbccdd".

Example 3:

Input: word = "aaabbb", k = 3

Output: 8*/

#include<bits/stdc++.h>

using namespace std;

class Solution1{
    private:
        int M  = 1e9 + 7;
        vector<vector<int>> t;
        int solve(int i, int count, vector<int> &freq, int k){
            if( i >= freq.size() ){
                if(count < k){
                    return 1;
                }
                return 0;
            }

            if(t[i][count] != -1){
                return t[i][count];
            }

            long long result =0;

            for(int take = 1; take <= freq[i]; take++){
                if(count + take < k){
                    result = (result + solve(i + 1, count + take, freq, k)) % M;
                }
                else{
                    break;
                }
            }

            return t[i][count] =  result; 
        }
    public:
        int possibleStringCount(string word, int k){
            
            if(k > word.length()){
                return 0;
            }

            vector<int> freq;
            int count = 1;

            for(int i=1; i<word.length(); i++){
                if(word[i] == word[i - 1]){
                    count++;

                }
                else{
                    freq.push_back(count);
                    count = 1;
                }
            }
            freq.push_back(count);


            int p = 1; //total possible strings
            for(int &f : freq){
                p = (p * f) % M;
            }

            if(freq.size() >= k){
                return p;
            }


            int n = freq.size();
            t.assign(n + 1, vector<int> (k + 1, -1));

            //we have to count the number of invalid strings
            long long invalidCount = solve(0, 0, freq, k);

            return (p - invalidCount);
        }
};

int main(){


    return 0;
}