#include<bits/stdc++.h>

using namespace std;

bool areAnagrams(string &s1, string &s2){
    if(s1.size() != s2.size()){
        return false;
    }

    unordered_map<char, int> f;
    unordered_map<char, int> s;

    for(auto &x : s1){
        f[x]++;
    }
    for(auto &x : s2){
        s[x]++;
    }

    for(auto &d : f){
        if(d.second != s[d.first]){
            return false;
        }
    }
    return true;
}

int main(){

    string s1 = "allergy";
    string s2 = "allergic";

    cout << areAnagrams(s1, s2) <<endl;

    return 0;
}