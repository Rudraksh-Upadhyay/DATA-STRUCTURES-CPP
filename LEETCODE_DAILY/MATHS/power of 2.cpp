#include<bits/stdc++.h>

using namespace std;

int main(){

    int n = 16;

    for(int i=0; i<(n/2); i++){
        if(pow(2, i) == n){
            cout << "true";
        }
    }
    cout << "false" << endl;

    return 0;
}