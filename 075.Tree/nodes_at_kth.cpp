#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void printKthLevel(int node, vector<vector<int>> &adj, int kth, vector<int> &visited, vector<int> &ans){

    
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    int level = 0;

    while(!q.empty()){
        int size = q.size();

        if(level == kth){
            //
            while(!q.empty()){
                // cout << q.front() << " ";
                ans.push_back(q.front());
                q.pop();
            }
            return ;
        }

        for(int i=0; i<size; i++){
            int front = q.front();
            q.pop();

            for(int child : adj[front]){
                if(visited[child] != 1){

                    q.push(child);
                    visited[child] = 1;
                }

            }
        }
        level++;
    }
}

int main(){

    int vertices;
    cin >> vertices;

    int kth;
    cin  >> kth;

    vector<int> visited(vertices + 1, 0);

    vector<vector<int>> adj(vertices + 1);

    int edges = vertices - 1;

    for(int i=0; i<edges; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;

    printKthLevel(1, adj, kth, visited, ans);

    sort(ans.begin(), ans.end());

    for(int x : ans){
        cout << x << " ";
    }
    

    return 0;
}