#include<iostream>
#include<vector>

using namespace std;

int heightOfTree(int node, vector<vector<int>> &adj, vector<int> &visited){
        visited[node] = 1;
        int maxDepth  = 0;

        for(int child : adj[node]){
            if(!visited[child]){
                maxDepth = max(maxDepth, heightOfTree(child, adj, visited));
            }
        }

        return maxDepth + 1;
    
}

// int heightOfTree(vector<vector<int>> adj, vector<int> &visited, int &height){
    
// }

int main(){

    int vertices;
    cin >> vertices;

    int edges = vertices -1;

    vector<vector<int>> adj(vertices+1);
    vector<int> visited(vertices+1, 0);


    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    int height = heightOfTree(1, adj, visited);

    cout << "Height = "<< height - 1<<endl;
    

    return 0;
}