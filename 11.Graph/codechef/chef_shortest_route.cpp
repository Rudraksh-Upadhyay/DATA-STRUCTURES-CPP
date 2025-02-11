#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int start, int end, vector<vector<int>> &adj, vector<bool> &visited, int &ans, vector<int> &answers){
    visited[start] = true;
    ans += 1;

    if(start == end){
        // cout << ans <<endl;
        answers.push_back(ans);

        ans--;
        visited[start] = false;
        return;
    }

    for(int i=0; i<adj[start].size(); i++){
        if(!visited[adj[start][i]]){
            solve(adj[start][i], end, adj, visited, ans, answers);
        }
    }

    ans--;
    visited[start] = false;
    return;

}

int main(){

    int n, m;
    cin >> n >> m;


    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    // int ans = 1;

    // visited[1] = true;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;

    vector<int> answers;

    solve(1, n, adj, visited, ans, answers);

    cout << *(min_element(answers.begin(), answers.end())) <<endl;

    return 0;
}