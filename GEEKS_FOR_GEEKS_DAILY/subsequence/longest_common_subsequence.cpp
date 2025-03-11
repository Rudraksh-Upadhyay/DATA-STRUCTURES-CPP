#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s1, string &s2, int i, int j){
        //base case
        int len1 = s1.size();
        int len2 = s2.size();
        if(i==len1 || j==len2){
            return 0;
        }

        //checking dp
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //recurrsion
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(s1, s2, i+1, j+1);
        }
        else{
            return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
        }

    }
    int lcs(string &s1, string &s2) {
        // code here
        int len1 = s1.size();
        int len2 = s2.size();

        dp.resize(len1, vector<int>(len2, -1));

        int ans = solve(s1, s2, 0, 0);
        
        return ans;
        
    }
};

int main(){

    string s1, s2;
    cout<< "Enter the first string->";
    cin >> s1;
    cout << endl;
    cout << "Enter the second string->";
    cin >> s2;
    
    Solution sol = Solution();
    
    cout << sol.lcs(s1,s2);


    return 0;
}