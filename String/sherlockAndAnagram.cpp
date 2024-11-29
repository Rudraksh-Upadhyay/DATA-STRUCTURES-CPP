//HACKER RANK - SHERLOCK AND ANAGRAM

#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:

    int sherlockAnagram(string s){
        int anagrams = 0;
        unordered_map <string, int> mp;
        int n = s.size();


        //find all substrings
        for(int i=0; i<n; i++){
            for(int j=i; j<n;j++){
                string subs = s.substr(i, j-i+1);
                sort(subs.begin(), subs.end());
                mp[subs]++;
            }
        }

        for(auto each:mp){
            if(each.second > 1){
                anagrams += (each.second * ( each.second - 1)) /2;
            }
        }
        return anagrams;
    }
};

int main(){

    Solution sol = Solution();

    string str = "abba";

    int ans = sol.sherlockAnagram(str);

    cout << ans << endl;

    return 0;
}