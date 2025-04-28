/*
ALGORITHM

1. PUSH(X)

*/


#include<bits/stdc++.h>

using namespace std;

class StackUsingQueue{
    private:

    queue<int> queue1;
    queue<int> queue2;

    public:

    void push(int x){
        queue1.push(x);
    }


    int pop(){
        if(queue1.empty()){
            throw out_of_range("Stack is empty");
        }

        while(queue1.size() > 1){
            queue2.push(queue1.front());
            queue1.pop();
        }// iske baar...queue1 mei sirf ek hi element bachega

        int top = queue1.front();
        queue1.pop();

        //top mil gaya...ab queue1 aur queue2 ko swap kr denge
        swap(queue1, queue2);

        return top;

    }

    int top(){
        if(queue1.empty()){
            throw out_of_range("Stack is empty");
        }

        while(queue1.size() > 1){
            queue2.push(queue1.front());
            queue1.pop();
        }

        int top = queue1.front();
        queue2.push(top);
        queue1.pop();

        swap(queue1, queue2);

        return top;
    }

    bool Is_Empty(){
        return queue1.empty();
    }
};

int main(){

    StackUsingQueue stack  = StackUsingQueue();

    //ADDING ELEMENT IN STACK
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);


    //DISPLAY STACK
    while(!stack.Is_Empty()){
        cout << stack.top() << endl;
        stack.pop();
    }


    return 0;
}