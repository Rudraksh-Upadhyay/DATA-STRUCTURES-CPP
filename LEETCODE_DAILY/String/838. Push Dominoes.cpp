#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> leftSeRightPush(n, -1);
        vector<int> rightSeLeftPush(n, -1);

        //left se closest right push ko update krnege
        int m = -1;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                leftSeRightPush[i] = i;
                m = i;
            }
            if(dominoes[i] == 'L'){
                leftSeRightPush[i] = -1;
                m = -1;
            }
            else{
                leftSeRightPush[i] = m;
            }
        }

        //right se closest left push ko update krenge
        m = -1;
        for(int i=n-1; i>=0 ; i--){
            if(dominoes[i] == 'L'){
                rightSeLeftPush[i] = i;
                m = i;
            }
            if(dominoes[i] == 'R'){
                rightSeLeftPush[i] = -1;
                m = -1;
            }
            else{
                rightSeLeftPush[i] = m;
            }
        }

        string ans = "";

        for(int i=0; i<n; i++){
            if(dominoes[i] == '.'){
                if(leftSeRightPush[i] == -1 && rightSeLeftPush[i] == -1){
                    ans += '.';
                }
                else if(leftSeRightPush[i] != -1 && rightSeLeftPush[i] == -1){
                    ans += 'R';
                }
                else if(leftSeRightPush[i] == -1 && rightSeLeftPush[i] != -1){
                    ans += 'L';
                }
                else if(leftSeRightPush[i] != -1 && rightSeLeftPush[i] != -1){
                    int leftDiff = abs(i - leftSeRightPush[i]);
                    int rightDiff = abs(i - rightSeLeftPush[i]);

                    if(leftDiff < rightDiff){
                        ans += 'R';
                    }
                    else if(leftDiff > rightDiff){
                        ans += 'L';
                    }
                    else{
                        ans += '.';
                    }
                }
                else{
                    ans += '.';
                }
            }
            else{
                ans += dominoes[i];
            }
        }
        return ans;
    }
};

int main(){

    string dominoes = ".L.R...LR..L..";
    Solution sol = Solution();

    cout << sol.pushDominoes(dominoes) << endl;


    return 0;
}