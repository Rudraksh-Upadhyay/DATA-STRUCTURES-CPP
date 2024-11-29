//LEETCODE 1209

#include<iostream>

using namespace std;

class Solution{
    public:

    string removeDuplicate(string s, int k){
        string str = "";
        int count = 1;
        int n = s.length();
        str.push_back(s[0]);
        int i = 1;
        while(i < n){
            str.push_back(s[i]);
            cout<<str<<endl;
            // int l = str.length();
            for(int j=1; j<str.length(); j++){
                if(str[j] == str[j-1]){
                    count++;
                    cout<<str[j]<<","<<str[j-1]<<"are equal"<<endl;
                    cout<<"count->"<<count<<endl;
                    if(count == k){
                        for(int i=0; i<k; i++){
                            str.pop_back();
                        }
                        cout<<"poped->"<<str<<endl;
                        count = 1;
                    }
                }
                if(str[j] != str[j-1]){
                    count = 1;
                }
                
            }
            count = 1;
            i++;
        }
        return str;
    }
};


int main(){
    Solution sol = Solution();
    string s = "deeedbbcccbdaa";
    int k = 3;
    string ans  = sol.removeDuplicate(s, k);
    cout << ans <<endl;
    return 0;
}