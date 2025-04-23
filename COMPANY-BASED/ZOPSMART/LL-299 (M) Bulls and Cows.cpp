#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int goats = 0;
        int sheeps = 0;

        int n = secret.length();

        vector<int> secretCount(10, 0);
        vector<int> guessCount(10, 0);

        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]){
                goats++;
            }
            else{
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }

        for(int i=0; i<10; i++){
            sheeps += min(secretCount[i], guessCount[i]);
        }
        return to_string(goats) + "G" + to_string(sheeps) + "S";
    }
};

int main(){

    string secret = "1807";
    string guess = "7810";

    Solution sol = Solution();

    cout << sol.getHint(secret, guess) << endl;

    return 0;
}