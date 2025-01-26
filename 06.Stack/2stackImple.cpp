#include<iostream>

using namespace std;


class Stack{

    public:

    int* arr;
    int top1;
    int top2;
    int size;

    Stack(int capacity){
        arr = new int[capacity]();
        size = capacity;
        top1 = -1;
        top2 = size;
    }

    void push1(int value){
        if(top1 == top2-1){
            cout << "Stack Overflow" << endl;
        }
        else{
            top1++;
            arr[top1] = value;
        }
    }

    void push2(int value){

        if(top1 == top2-1){
            cout << "Stack Overflow" << endl;

        }
        else{
            top2--;
            arr[top2] = value;
        }

    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack Underflow" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout << "Stack Underflow" << endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }

    }

    void peek1(){
        cout<< arr[top1] << endl;
    }

    void peek2(){
        cout << arr[top2] << endl;

    }

    void print(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main(){

    Stack s(5);

    s.push1(1);
    s.push1(2);

    s.print();

    s.push2(3);
    s.print();

    s.push2(4);
    s.print();

    s.push2(5);
    s.print();

    s.push2(6);
    s.print();

//-------------------------------------//

    s.pop1();
    s.print();

    s.pop2();
    s.print();

    s.peek1();
    s.peek2();


    return 0;
}