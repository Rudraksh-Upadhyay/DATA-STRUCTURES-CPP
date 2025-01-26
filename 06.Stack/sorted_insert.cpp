#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> &s, int x){
    if(s.empty() ||s.top() < x){

        s.push(x);
        return;

    }

    int ele = s.top();
    s.pop();

    sortedInsert(s, x);

    s.push(ele);
}


void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }cout << endl;
}

int main(){


    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);


    int x = 35;
    print(s);

    sortedInsert(s, x);

    print(s);

    return 0;
}