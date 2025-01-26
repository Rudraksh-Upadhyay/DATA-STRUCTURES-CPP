#include<iostream>
#include<stack>

using namespace std;
void findMiddle(stack<int> &s, int size, int count){
    if(count == size / 2){
        cout << s.top() << endl;
        return;
    }

    //1 case hum krenge
    int topElement = s.top();
    s.pop();

    //recurssion
    findMiddle(s, size, count+1);

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

    // cout << s.size() <<endl;

    // int count = s.size() / 2;

    findMiddle(s, s.size(), 0);

    return 0;
}