#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    string s;
    cin >> s;

    char k;
    cin >> k;

    int t;
    cin >> t;

    int index = 0;

    bool found = false;

    // while(t--){
    //     for(int i=0; i<s.length(); i++){
    //         if(s[i] == k){
    //             index = i;
    //             found = true;
    //         }
    //     }
    // }
    for(int i=0; i<s.length(); i++){
        if(s[i] == k){
            t--;
            if(t==0){
                index = i;
                found = true;
                break;
            }
            else{
                continue;
            }
        }
    }

    if(found){
        cout << index <<endl;
    }
    else{
        cout << -1 <<endl;
    }

    return 0;
}