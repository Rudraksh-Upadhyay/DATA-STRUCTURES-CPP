#include<iostream>

using namespace std;

class Heap{
    public:

        int* arr;
        int capacity;
        int index;

        Heap(int n){
            this->capacity = n;
            arr = new int[n]();
            index = 0;
        }

        void printHeap(){
            for(int i=0; i<capacity; i++){
                cout << arr[i] << " ";
            }

            cout <<endl;
        }


        void insert(int value){
            if(index == capacity - 1 ){
                cout << "Overflow" <<endl;
            }

            //agar jagah hai toh -> NORMAL INSERTION
            index++;
            arr[index]  = value;

            //not put value at right position
            //by comparing with parent node
            // [x, 10, 6, 7, 2, 3, 5]

            //HEAPIFY

            int i = index;

            while(i > 1){
                int parentIndex = i / 2;

                if(arr[i] > arr[parentIndex]){
                    swap(arr[i], arr[parentIndex]);
                    i = parentIndex;
                }
                else{

                    //parent already bada hai
                    break;
                }

            }
        }

        void deleteHeap(){

            //replace
            swap(arr[1], arr[index]);

            //size decrease
            index--;    

            //heapify
            heapify(arr, index, 1);

        }

        void heapify(int* arr, int n, int currIndex){
            // n->number of elements in heap
            int i = currIndex;
            int leftIndex = 2*i;
            int rightIndex  = 2*i + 1;

            int largestKaIndex = i;
            //assuming i pr sabse bdi value hai
            //ho sakta hai ki badi value left yah right mei ho

            //check left
            if(leftIndex < n &&  arr[leftIndex] > arr[largestKaIndex]){
                largestKaIndex = leftIndex;
            }

            if(rightIndex < n && arr[rightIndex] > arr[largestKaIndex]){
                largestKaIndex = rightIndex;
            }

            //yaha apke pass sabke badi value ka index hoga
            

            //largest value still i hi hai ....toh no need to do anything
            //agar largestvalue left yah right mei se koi hai toh...swap
            if(largestKaIndex != i){
                swap(arr[largestKaIndex], arr[i]);
                i = largestKaIndex; //isme i ko neeche le aye...phir heapify krenge

                heapify(arr, n, i);
            }

        }
};

int main(){

    Heap pq(10);

    pq.insert(10);
    pq.printHeap();

    pq.insert(20);
    pq.printHeap();

    pq.insert(30);
    pq.printHeap();

    return 0;
}