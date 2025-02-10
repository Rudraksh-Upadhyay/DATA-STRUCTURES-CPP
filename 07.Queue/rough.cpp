#include<iostream>
#include<string>

using namespace std;

int main(){

    
    string s = "hello123";

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch>='0' && ch<='9'){
            cout << ch << endl;
        }
    }


    return 0;
}