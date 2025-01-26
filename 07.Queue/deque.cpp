#include<iostream>
// #include<deque>
#include<queue>

using namespace std;

int main(){

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.push_front(5);
    dq.push_front(15);

    cout << dq.front() << endl;

   // printing
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }




    return 0;
}