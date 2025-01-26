#include<iostream>

using namespace std;

class Stack{
    public:

    int *arr;
    int top;
    int size;

    Stack(int capacity){
        arr = new int[capacity]();
        size = capacity;
        top = -1;
    }

    void push(int val){
        if(top == size-1){
            //stack is already full
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }
    void pop(){
        if(top == -1){
            //stack is already empty
            cout << "Stack Underflow" << endl;
        }
        else{
            arr[top] = 0;
            top--;
        }

    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    int getSize(){
        return top+1;
    }

    int getTop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }


    void printStack(){
        cout << "Printing Stack"<< endl;
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Stack s(5);
    
    s.printStack();

    s.push(1);
    s.push(2);

    s.printStack();

    cout << "top->" << s.getTop()<<endl;

    s.push(3);
    s.push(4);
    s.push(5);
    
    s.printStack();

    s.push(6);

    s.printStack();

//-------------------------------------------------//
    s.pop();

    s.printStack();


    cout << "size of stack->" << s.getSize()<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.printStack();
    s.pop();

    return 0;
}