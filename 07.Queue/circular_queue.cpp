#include<iostream>

using namespace std;


class cqueue{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    cqueue(int capacity){
        arr = new int[capacity]();
        size = capacity;
        front = -1;
        rear = -1;
    }

    void push(int value){
        if(front == 0 && rear == size-1){
            cout << " overflow" << endl;
            return;
        }

        if(rear == front -1){
            cout << "overflow" <<endl;
            return;
        }

    }
};

int main(){

    return 0;
}