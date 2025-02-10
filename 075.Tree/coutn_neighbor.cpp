#include<iostream>
#include<vector>

using namespace std;

int countNeighbors(int node, vector<vector<int>> &adj){
    return adj[node].size();
}

int main(){

    int n;
    cin >> n;

    int neighbor ;
    cin >> neighbor;

    vector<vector<int>> adj(n+1);

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    cout << countNeighbors(neighbor, adj)   ;


    return 0;
}