#include<iostream>
#include<vector>

using namespace std;


class Heap{

    public:


    vector<int> v;
    int index = 0;

    Heap(){
        v.push_back(-1);
    }


    void print(){
        for(int i=1; i<=index; i++){
            cout << v[i] << " ";
        }

        cout<<endl;
    }


    void insert(int value){
        v.push_back(value);
        index++;

        int i=index;

        while(i > 1){
            int parentIndex = i/2;

            if(v[i] < v[parentIndex]){
                swap(v[i], v[parentIndex]);
                i = parentIndex;
            }

            else{
                break;
            }
        }
    }

    void heapify(int currIndex){
        int i = currIndex;
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;

        int smallestIndex = i;

        if(leftIndex <= index && v[leftIndex] < v[smallestIndex]){
            // smallestIndex = leftIndex;
            swap(v[leftIndex], v[smallestIndex]);
            heapify(leftIndex);
        }
        if(rightIndex <= index && v[rightIndex] < v[smallestIndex]){
            // smallestIndex = rightIndex;
            swap(v[rightIndex], v[smallestIndex]);
            heapify(rightIndex);
        }

        // if (smallestIndex != i){
        //     swap(v[smallestIndex], v[i]);   
        //     // i = smallestIndex;
        //     heapify(smallestIndex);
        // }
    }


    void deleteHeap(){
        if(index == 0){
            return ;
        }


        swap(v[1], v[index]);
        
        v.pop_back();
        index--;

        // heapify(v, index, 1);
        if(index > 0){
            heapify(1);
        }

    }
};

int main(){

    Heap* h = new Heap();    

    h->insert(8);
    h->insert(3);
    h->insert(4);
    h->insert(1);
    h->insert(18);


    h->print();

    h->deleteHeap();

    h->print();

    h->deleteHeap();

    h->print();



    return 0;
}