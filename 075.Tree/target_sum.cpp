#include<iostream>
#include<vector>


using namespace std;

bool isSumPossible(int target, int node, vector<vector<int>> &adj, vector<int> &visited, int sum){
    visited[node] = 1;
    sum += node;

    if(sum == target){
        return true;
    }
    if(sum < target){
        for(int child : adj[node]){
            if(!visited[child]){
                bool result = isSumPossible(target, child, adj, visited, sum);
                if(result){
                    return true;
                }
            }
        }
    }


    return false;    
}

int main(){


    int vertices;
    cin >> vertices;

    int target;
    cin >> target;

    int edges = vertices - 1;

    vector<vector<int>> adj(vertices + 1);

    vector<int> visited(vertices + 1, 0);

    for(int i=0 ; i<edges; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    bool p = isSumPossible(target, 1, adj, visited, 0);

    if(p){
        cout<<"YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}