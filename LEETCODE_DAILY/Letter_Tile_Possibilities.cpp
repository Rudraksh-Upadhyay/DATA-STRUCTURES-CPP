#include<iostream>
#include<vector>

using namespace std;

int factorial(int n){
    int fact = 1;

    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}

void combination(string s, int r,  int* ans){
    
}

void solve(string s, string current, int* ans){

    if(s.length() == 0){
        return;
    }

    for(int r = 1; r<= s.length(); r++){
        combination(s, r, ans);
    }
}

int main(){

    string a = "AAB";
    int ans = 0;
    solve(a, "", ans);


    return 0;
}