#include<bits/stdc++.h>
using namespace std;

void findReverse(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());

    //if starting is '0' remove o s
    int i=0;
    while(s[i] == '0'){
        i++;
    }

    cout << s.substr(i) <<endl;
}

int main(){

    int num = 1000;

    findReverse(num);

    return 0;
}