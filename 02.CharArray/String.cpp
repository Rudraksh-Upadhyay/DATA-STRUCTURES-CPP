#include<iostream>

using namespace std;

int main(){

    // string str;

    // str.push_back('k');
    // str.push_back('a');
    // str.push_back('s');
    // str.push_back('h');
    // str.push_back('i');
    // str.pop_back();
    

    // cout << str << endl;


    // string str2 = "kashish upadhyay";

    // cout << str2[0] << endl;
    // cout << str2.at(0)<< endl;
    // cout << str2.front() <<endl;
    // cout << str2.back() << endl;
    // cout << str2.length() << endl;


//ITERATOR

    // auto it  = str2.begin();

    // while(it != str2.end()){
    //     cout << *it << " ";
    //     it++;
    // }

    // cout << endl;


//CONCATENATION

    // string fname = "kashish";
    // string lname = "upadhyay";

    // cout << fname + " " + lname << endl;
    // cout << fname.append(lname) << endl;

//SUBSTRING

    // string name = "kashish is the best";
    // cout << name.substr(0, 5);

//FIND
    string name2 = "kashish";
    // string word = "ishu";
    int ans = name2.find("ash");
    cout << "find->" << ans<< endl;

    // if(name2.find(word) != string::npos){
    //     cout<<"found";
    // }
    // else{
    //     cout<<"Not found";
    // }


//COMPARE

    // string s1 = "xashish";
    // string s2 = "kashish";

    //cout << s1.compare(s2) << endl;   // yeh 0 dega....hence same hai
                                        // negative dega agar s1 lexographically chota hoga toh
                                        // positive hoga agar s2 lexographically bada hoga

    // if(s1[1] == s2[0]){
    //     cout << "found";
    // }




//PRACTICE
    // string a = "kashihh";
    
    // auto it = a.end();

    // if(*(it-1) == *(it-2)){
    //     cout<<"same"<<endl;
    // }
    // else{
    //     cout<<"not same"<<endl;
    // }


    return 0;
}