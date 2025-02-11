#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void bfs(int start, vector<bool> &visited, vector<vector<int>> &adjList){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        

        for(int x : adjList[node]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<int>> adjList(numNodes + 1);

    for(int i = 0; i < numEdges; i++){
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(numNodes + 1, false);
    cout << "BFS TRAVERSAL->" ;
    bfs(1, visited, adjList);

    return 0;
}