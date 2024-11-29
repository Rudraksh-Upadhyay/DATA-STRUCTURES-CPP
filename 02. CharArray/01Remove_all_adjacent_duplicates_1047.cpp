//LEETCODE 1047

#include<iostream>

using namespace std;

class Solution{
    public:

    string removeAllAdjacentDuplicates(string s){
        string str = "";
        int n = s.length();

        if(n==0){
            return str;  //agar empty string hai toh
        }

        str += s[0];
        for(int i=1; i<n; i++){
            //pehle check kr lo ki...str empty hai ki nahi
            //warna out of bound wala error aa sakta hai
            if(!str.empty() && s[i] == str.back()){
                str.pop_back();
            }
            else{
                str.push_back(s[i]);
            }
        }
        return str;
    }
};

int main(){
    Solution sol = Solution();
    string str = "abbaca";
    string ans = sol.removeAllAdjacentDuplicates(str);
    cout << "string after removing duplicates->" << ans << endl;
    return 0;
}