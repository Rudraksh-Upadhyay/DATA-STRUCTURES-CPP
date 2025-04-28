#include<bits/stdc++.h>

using namespace std;

string nearestSquareAscii(string s){
    string result = "";

    for(auto &c : s){
        int ascii_value = (int)c;
        int sqrt_value = round(sqrt(ascii_value));
        int nearest_square_value = sqrt_value * sqrt_value;
        
        char new_char = (char)nearest_square_value;
        result += new_char;
    }
    return result;
}

int main(){

    string s = "ZOPSMART";
    cout << nearestSquareAscii(s) << endl;  


    return 0;
}