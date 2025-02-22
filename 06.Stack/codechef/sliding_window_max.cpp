#include<iostream>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

int main(){

    priority_queue<pair<int, int>> maxHeap;

    vector<int> arr = {1, 3, -1, -3, 5};

    int n = arr.size();

    for(int i=0;i<n ; i++){
        maxHeap.push({arr[i], i});
    }

    

    // while(!maxHeap.empty()){
    //     pair<int, int> top = maxHeap.top();
    //     cout << "{" << top.first << ", " << top.second << "}" << endl;
    //     maxHeap.pop();
    // }

    return 0;
}