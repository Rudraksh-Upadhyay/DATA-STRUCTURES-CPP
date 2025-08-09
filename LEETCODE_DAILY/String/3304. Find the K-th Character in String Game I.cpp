#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){
            string ap = "";
            for(auto x : word){
                char b = (x + 1) % 'z';
                ap += b;
            }
            word += ap;
            cout << word << endl;
        }
        return word[k];
    }
};

int main(){

    Solution sol = Solution();

    int k = 5;

    cout << sol.kthCharacter(k) << endl;


    return 0;
}