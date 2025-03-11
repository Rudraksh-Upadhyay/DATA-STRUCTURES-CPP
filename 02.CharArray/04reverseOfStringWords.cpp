// LEETCODE 151

#include<iostream>
#include<vector>
#include<iterator>
#include<string>

using namespace std;

class Solution {
public:
    string removeExtraSpace(string s){
        string newString;
        // int n = s.length();
        auto starting = s.begin();
        auto ending = s.end();
        while(*ending == ' '){
            s.pop_back();
        }

        while(*starting == ' '){
            starting++;
        }

        for(auto it = starting; it != ending+1; it++){
            newString.push_back(*it);
        }


        return newString;
    }

    string reverseWords(string str) {

        string newString = "";
        string s = removeExtraSpace(str);
        int n = s.length();
        // cout << "initial length= "<<n<<endl;

        for(int i = n-1; i>=0 ; i--){
            if(s[i] == ' '){
                for(int m = i+1; m < n; m++){
                    newString.push_back(s[m]);
                }
                for(int q = n-1; q > i; q--){
                    s.pop_back();
                }
                newString.push_back(s[i]);
                s.pop_back();
                
                n = s.length();
                // cout << "after poping-> length = " << n<< endl;
            }

        }
        for(int i  = 0; i< n; i++){
            newString.push_back(s[i]);
        }

        return newString;
    }
};

int main(){
    
    Solution S = Solution();
    string s = "the sky is blue";
    // string ans = s.reverseWords(s);
    string ans = S.reverseWords(s);
    cout << "ans->" << ans << endl;
    return 0;
}