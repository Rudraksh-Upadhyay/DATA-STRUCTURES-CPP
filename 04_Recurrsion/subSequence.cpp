#include<iostream>

using namespace std;

void printSubsequence(string str, int index, string output){
    //base case
    if(index == str.length()){
        cout << output << endl;
        return;
    }

    //1 case
    char ch = str[index];
    //INCLUDE
    // output.push_back(ch);
    printSubsequence(str, index+1, output + ch);
    //EXCLUDE
    printSubsequence(str, index+1, output);
    //baaki recurrsion
}   

int main(){

    string str = "abc";
    string output = "";

    return 0;
}