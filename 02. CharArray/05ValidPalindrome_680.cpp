//LEET CODE 680

#include<iostream>

using namespace std;

class Solution{

    public:

    bool checkPalindrome(string str, int s, int e){

        while(s <= e){
            if(str[s] != str[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        }
        return true;

    }

    bool validPalindrome(string str){
        int len = str.length();
        int s = 0;
        int e = len-1;

        while(s <= e){
            if (str[s] == str[e]){
                s++;
                e--;
            }

            else{
                //isme hamare pass do case bante hai
                //1 option
                // agar mei 's' element ko delete krta hu

                bool ans1 = checkPalindrome(str, s+1, e);

                //2 option
                // agar mei 'e' element ko delete krta hu
                bool ans2 = checkPalindrome(str, s, e-1);

                bool finalAns = ans1 || ans2;

                return finalAns;
            }
        }

        return true;

    }
};

int main(){

    Solution sol = Solution();
    string str = "allah";
    string str2 = "anu";

    bool ans = sol.validPalindrome(str);
    bool ans2 = sol.validPalindrome(str2);

    cout << "first ans->" << ans << endl;
    cout << "second \"anu\"->" << ans2 << endl;
    return 0;
}