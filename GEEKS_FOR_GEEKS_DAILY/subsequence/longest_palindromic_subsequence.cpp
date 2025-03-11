#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;

    int solve(string &s1, string &s2, int i, int j){
        int len1 = s1.size();
        int len2 = s2.size();

        if(i == len1 || j == len2){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }

        else{
            return dp[i][j] = 0 + max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
        }
    }

    int lcs(string &s1, string &s2){
        int len1 = s1.size();
        int len2 = s2.size();
        dp.resize(len1, vector<int>(len2, -1));

        return solve(s1, s2, 0, 0);
    }


public:

    int longestPalinSubseq(string &s) {
        // code here
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return lcs(s1, s2);
        
    }
};

int main(){

    string s;
    cout<< "Enter the string->";
    cin >> s;

    Solution sol = Solution();
    cout << sol.longestPalinSubseq(s)<<endl;

    return 0;
}