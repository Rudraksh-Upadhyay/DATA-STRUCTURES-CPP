#include<bits/stdc++.h>

using namespace std;

string addBinary(string& s1, string& s2){
    int s1_size = s1.size();
    int s2_size = s2.size();

    
    if(s1_size != s2_size){
        int diff = abs(s1_size - s2_size);
        if(s1_size < s2_size){
            for(int i=0; i<diff; i++){
                s1 = "0" + s1;
            }
        }
        else{
            for(int i=0; i<diff; i++){
                s2 = "0" + s2;
            }
        }
    }
    
    s1_size = s1.size();
    s2_size = s2.size();
    
    int i = s1_size-1;
    int j = s2_size-1;
    int carry = 0;

    string ans = "";

    while(i >= 0 && j >= 0){
        int bit1 = s1[i] - '0';
        int bit2 = s2[j] - '0';
        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        ans = char(sum % 2 + '0') + ans;

        i--; j--;
    }

    if(carry){
        ans = '1' + ans;
    }

    int k = 0;
    while(ans[k] == '0'){
        ans = ans.substr(k+1, ans.size() - 1);
    }

    return ans;
}

int main(){

    string s1 = "00100";
    string s2 = "010";

    string ans = addBinary(s1, s2);

    cout << ans << endl;

    return 0;
}