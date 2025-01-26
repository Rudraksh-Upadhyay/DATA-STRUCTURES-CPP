#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<int> s;

//push
    s.push(1);
    s.push(2);
    s.push(3);

//pop
    s.pop();

//size
    cout<< s.size() << endl;

//top-> peek krne ke liye
    cout << "s.top()->" << s.top() << endl;

//empty -> s.empty() use krte hai...joh...batata hai ki...stack empty hai ki nahi

    cout << s.empty() << endl;

    return 0;
}