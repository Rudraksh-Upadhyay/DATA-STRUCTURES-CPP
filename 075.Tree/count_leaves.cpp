#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// int count = 0;


void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
    visited[node] = 1;
    //base case
    int adjsize = adj[node].size();
    if(adjsize == 0){
        // count++;
        // cout << node << " ";
        ans.push_back(node);
        return;
    }
    
    
    for(int n : adj[node]){
        if(!visited[n]){
            // cout << "going to "<< n<<endl;
            dfs(n, adj, visited, ans);
        }
    }
}



int main(){

    int nodes;
    cin >> nodes;

    vector<int> visited(nodes+1, 0);

    vector<vector<int>> adj(nodes+1);

    for(int i=0; i<nodes-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> ans;

    dfs(0, adj, visited, ans);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}