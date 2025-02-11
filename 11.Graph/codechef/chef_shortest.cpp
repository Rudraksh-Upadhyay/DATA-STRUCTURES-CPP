#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void solve(vector<vector<int>> &adj, vector<int> &distance){
    queue<int> q;
    q.push(1);
    distance[1] = 0;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for(int x : adj[node]){
            if(distance[node] + 1 < distance[x]){
                distance[x] = 1 + distance[node];
                q.push(x);
            }
        }
    }
}

int main(){


    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distance(n + 1, INT_MAX);
    // distance[1] = 0;


    solve(adj, distance);

    cout << 1 + distance[n];
    return 0;
}