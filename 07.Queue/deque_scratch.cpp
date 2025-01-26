#include<iostream>

using namespace std;

class Deque{
    private:
        int *arr;
        int size;
        int front; 
        int rear;
    
    public:
        Deque(int capacity){
            arr = new int[capacity]();
            size = capacity;
            front = -1;
            rear = -1;
        }


        void push_front(int value){

            if(front == 0){
                //iska matlb mere pass left side mei jagah hi nahia hi
                cout << "Overflow"<< endl;

            }

            else{
                if(front == -1 && rear == -1){
                    front = 1;
                    rear = 1;

                    arr[front] = value;

                }
                else{
                    front--;
                    arr[front] = value; 
                }
            }

        }

        void push_back(int value){
            if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
                arr[rear]= value;
            }
            else{
                if(rear < size-1){
                    rear++;
                    arr[rear] = value;
                }
                else{
                    cout << "Queue Overflow" << endl;
                }
            }
        }


        void pop_back(){
            if(front == -1 && rear == -1){
                cout << "Underflow" <<endl;
            }
            else if(front == rear){
                //means...ek hi element hai 
                arr[rear] = 0;
                front= -1;
                rear = -1;
            }
            else{
                arr[rear] = 0;
                rear--;
            }
        }
};

int main(){

    return 0;
}