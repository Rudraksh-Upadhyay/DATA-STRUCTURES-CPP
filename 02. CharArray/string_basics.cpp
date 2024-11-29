//minimum time difference - LEETCODE 539

#include<iostream>

using namespace std;

int main(){


    string str = "123";
    string str2 = "kahsish";

//string ko int mei convert krne ke liye aap....stoi ka use krte ho
    int num = stoi(str);

    cout << num << endl;
    cout << typeid(num).name() << endl;

    cout << str[1] << typeid(str[1]).name() <<  endl;

    // cout << str2.substr(2, 5);
    cout << "str2 ka substirng->" <<str2.substr(2, 2) << endl; 

    // cout << "00" > "01" << endl;

    return 0;
}