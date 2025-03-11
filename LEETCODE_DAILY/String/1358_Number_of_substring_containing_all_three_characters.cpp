//LEETCODE 1358
/*
SIMPLER VERSION OF LL 3306

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    bool isValid(string &s, int &index){
        if(s[index] == 'a' || s[index] == 'b' || s[index] == 'c'){
            return true;
        }
        return false;
    }
    public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;

        int ans = 0;

        unordered_map<char, int> mp;

        while(j < n){
            if(isValid(s, j)){
                mp[s[j]]++;
            }

            //check kro...size == 3 hoga toh valid hoga
            while(mp.size() == 3){
                ans += n - j;
                if(isValid(s, i)){
                    if(mp[s[i]] == 1){
                        mp.erase(s[i]);
                    }
                    else{
                        mp[s[i]]--;
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};

int main(){

    string s = "abc";
    Solution sol = Solution();
    cout << sol.numberOfSubstrings(s) <<endl;


    return 0;
}