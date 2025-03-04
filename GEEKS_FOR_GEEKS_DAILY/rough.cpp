#include<bits/stdc++.h>

using namespace std;

int main(){
    
    stack<int> num;
    string a = "1kash";

    for(int i=0; i<a.length(); i++){
        if(isdigit(a[i])){
            num.push(a[i] - '0');
        }
    }

    int temp = num.top();
    num.pop();
    cout << temp <<endl;
    return 0;
}