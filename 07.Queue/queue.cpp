#include<iostream>
#include<queue>

using namespace std;

int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.back() << endl;

    cout << q.size() << endl;

    //removal
    q.pop();
    cout << q.front() << endl;

    //empty
    cout << q.empty() << endl;

    //printing
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}