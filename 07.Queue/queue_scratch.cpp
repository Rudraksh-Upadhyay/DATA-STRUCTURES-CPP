#include<iostream>

using namespace std;

class queue{
    private:
    int *arr;
    int front;
    int rear;
    int size;

    public:
    queue(int size){
        this->size = size;
        arr = new int[size]();
        front = -1;
        rear = -1;
    }

    void push(int val){
        if(rear == size-1){
            cout << "Queue Overflow" << endl;
        }
        else{
            
            //do case
            //1. first element insertion
            if(front == -1 && rear == -1){
                front = 0; 
                rear = 0;
                arr[rear] = val;
            }
            //2. other element insertion

            else{
                rear++;
                arr[rear] = val;
            }
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout << "Queue UnderFlow" << endl;
        }

        else{
            if(front == rear){
                arr[front] = 0;
                front = -1;
                rear = -1;
            }
            else{

                arr[front] = 0;
                front++;
            }
        }

    }

    int getFront(){

        if(front == -1){
            cout << "Queue UnderFlow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }

    }

    int getRear(){
        if(rear == -1){
            cout << "Queue UnderFlow" << endl;
            return -1;
        }

        else{
            return arr[rear];
        }

    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }

        return rear-front+1;

    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }

    }


    void print(){
        if(front == -1 && rear == -1){
            cout << "Empty" << endl;
            return;
        }
        int dfront = front;
        while(dfront <= rear){
            cout << arr[dfront] << " ";

            dfront++;
        }
        cout << endl;
    }
};

int main(){

    queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);


    q.print();

    q.pop();

    q.print();


    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    cout << "pop->" << endl;

    q.print();
    q.pop();

    q.print();

    q.pop();

    q.print();
    q.pop();

    

    return 0;
}