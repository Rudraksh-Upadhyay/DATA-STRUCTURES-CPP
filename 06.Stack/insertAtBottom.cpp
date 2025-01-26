#include<iostream>
#include<stack>

using namespace std;


void insertAtBottom(stack<int> &s, int value){
    if(s.empty()){
        s.push(value);
        return;
    }

    //1 case hum solve krenge 
    int topElement = s.top();
    s.pop();

    //baaki recurrsion
    insertAtBottom(s, value);


    //backtrack
    s.push(topElement);

}

int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }


    int value = 100;

    insertAtBottom(s, value);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}