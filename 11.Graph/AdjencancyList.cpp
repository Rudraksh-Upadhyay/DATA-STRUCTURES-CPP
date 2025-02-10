#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class graph{
    public:

        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction){
            //direction = 0 -> undirected graph
            //direction = 1 -> directed graph

            adjList[u].push_back(v);

            if(direction == 0){
                adjList[v].push_back(u);
            }
        }


        void print(){
            for(auto i:adjList){
                cout << i.first << " -> " ;

                for(auto j:i.second){
                    cout << j << ", ";
                }

                cout <<endl;
            }
        }
};


int main(){

    int n, m;
    cout << "Enter the number of Nodes->";
    cin >> n;
    cout << "Enter the number of Edges->";
    cin >> m;

    int arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0; i<m ;i++){
        cout << "Enter the source and destination->"<<endl;
        int u, v;
        cin >> u >> v;

        arr[u][v] = 1;
        arr[v][u] = 1;
    }


    cout<<"Adjencancy List->"<<endl;
    for(int i=0; i<n; i++){
        cout << i << " -> ";
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                cout << j << " ";
            }
        }
        cout <<endl;
    }
    return 0;
}