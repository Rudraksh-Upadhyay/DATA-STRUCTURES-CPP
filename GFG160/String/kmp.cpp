#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:

    void computeLPS(string &pat, vector<int> &lps, int patsize){
        int length = 0;
        lps[0] = 0;

        int i = 1;
        
        while(i < patsize){
            if(pat[i] == pat[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = lps[length - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    public:
    
    vector<int> search(string &pat, string &txt){
        int txtsize = txt.size();
        int patsize = pat.size();

        vector<int> ans;

        vector<int> lps(patsize, 0);
        computeLPS(pat, lps, patsize);

        //apply KMP
        int i = 0;
        int j = 0;

        while(i < txtsize){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == patsize){
                ans.push_back(i - j + 1);
                j = lps[j-1];
            }else if (i < txtsize && txt[i] != pat[j]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;    
                }
            }
        }

        return ans;
    }

};

int main(){

    string txt = "abcab";
    string pat = "ab";

    Solution sol = Solution();

    vector<int> ans = sol.search(pat, txt);

    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}