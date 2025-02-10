#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<queue>
#include<vector>


using namespace std;


void prepAdjList(unordered_map<int, list<int> > &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontnode into answer
        ans.push_back(frontNode);

        //traverse all neighbours of front
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i); 
                visited[i] = true;
            }
        }
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>>edges){
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepAdjList(adjList, edges);

    //sare components check krene hai
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}



int main(){

    int numberOfEdges ;
    cin >> numberOfEdges;

    vector<pair<int, int>> edges;

    cout << "Enter the edges ->"<<endl;
    for(int i=0; i<numberOfEdges; i++){
        int u, v;
        cin>> u >> v;
        edges.push_back({u, v});
    }

    //printing
    for(auto i : edges){
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}