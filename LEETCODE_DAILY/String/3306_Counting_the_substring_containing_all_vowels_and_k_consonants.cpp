// LEETCODE 3306

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:


    bool checkVowel(string& word, int& i){
        if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u'){
            return false;
        }
        return true;
    }

    long long countOfSubstrings(string word, int k){
        unordered_map<char, int> mp;
        int n = word.length();
        vector<int> nextConsIndex(n);
        int nextCons = n;
        for(int i=n-1; i>=0; i--){
            nextConsIndex[i] = nextCons;
            if(!checkVowel(word, i)){
                nextCons = i;
            }
        }

        int i = 0; 
        int j = 0;
        int consNum = 0;

        long long ans = 0;

        while(j < n){
            if(checkVowel(word, j)){
                mp[word[j]]++;
            }
            else{
                consNum++;
            }


            //agar consonants ka count > k ho gaya toh shrink krenge
            while(consNum > k){
                if(checkVowel(word, i)){
                    if(mp[word[i]] == 1){
                        mp.erase(word[i]);
                    }
                    else{
                        mp[word[i]]--;
                    }
                }
                else{
                    consNum--;
                }
 
                i++;
            }

            //agar map.size == 5 ho jaye..and ...consNum == k ho jaye toh
            // ans mei j - nextConsIndex[j] add kr do
            while(i < n && mp.size() == 5 && consNum == k){              //VALID WINDOW
                ans += nextConsIndex[j]  -  j;
                // char ch = word[i];
                if(checkVowel(word, i)){
                    if(mp[word[i]] == 1){
                        mp.erase(word[i]);
                    }
                    else{
                        mp[word[i]]--;
                    }
                }
                else{
                    consNum--;
                }
                i++;

            }

            j++;
        }

        return ans;
        
    }

};

int main(){

    string word = "aouiei";
    int k = 0;

    Solution sol = Solution();

    long long ans = sol.countOfSubstrings(word, k);

    cout << ans << endl;




    return 0;
}