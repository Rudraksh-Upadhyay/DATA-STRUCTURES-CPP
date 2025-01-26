#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<char> s;

    string name = "kashish";
    int size = name.length();

    for(int i=0; i<size; i++){
        char ch = name[i];
        s.push(ch);
    }

    //retreival from the stack
    
    // for(int i=0; i<name.length(); i++){
    //     char ch = s.top();
    //     cout << ch << " " ;
    //     s.pop();
    // }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}