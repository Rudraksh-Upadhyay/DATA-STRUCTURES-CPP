#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adjList){
    visited[node] = true;

    cout << node << " ";

    for(int i=0; i<adjList[node].size(); i++){
        if(!visited[adjList[node][i]]){
            dfs(adjList[node][i], visited, adjList);
        }
    }
}

void performDFS(int numNodes, vector<vector<int>> &adjList){
    vector<bool> visited(numNodes+1, false);

    for(int i=1; i<=numNodes; i++){
        if(!visited[i]){
            dfs(i, visited, adjList);
        }
    }
}

int main(){

    int numNode, numEdge;
    cin >> numNode >> numEdge;

    vector<vector<int>> adjList(numNode + 1);

    for(int i = 0; i < numEdge; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "DFS traversal: ";
    performDFS(numNode, adjList);


    return 0;
}