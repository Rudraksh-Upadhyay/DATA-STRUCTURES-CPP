#include<iostream>

using namespace std;

class Solution{
    public:

        string clearDigits(string s){
            string res;
            for(char x : s){
                if(x >= '0' && x <= '9'){
                    res.pop_back();
                }
                else{
                    res.push_back(x);
                }
            }

            return res;
        }
};

int main(){


    Solution sol = Solution();
    string s = "abc12";
    string ans = sol.clearDigits(s);
    cout << ans << endl;


    return 0;
}