#include<bits/stdc++.h>

using namespace std;

int parent[10000];
int power[10000];
vector<pair<int, int>> tree[10000];


void dfs(int node, int par, int pwr) {
    parent[node] = par;
    power[node] = pwr;
    for (auto [child, p] : tree[node]) {
        if (child != par) {
            dfs(child, node, p);
        }
    }
}


int climbTree(int u, long long H) {
    while (u != 1) { // Stop if we reach the root
        if (H < power[u]) return u; // Stop if the hero can't defeat the monster
        H -= power[u];  // Lose health
        u = parent[u];  // Move to parent
    }
    return 1; // If reached the root
}



void solve() {
    int n;
    cin >> n;
    
    // Construct the tree
    for (int i = 1; i < n; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        tree[u].push_back({v, p});
        tree[v].push_back({u, p});
    }
    
    // Precompute parent and power using DFS
    dfs(1, -1, 0);

    int q;
    cin >> q;
    
    while (q--) {
        int u;
        long long H;
        cin >> u >> H;
        cout << climbTree(u, H) << endl;
    }
}

int main(){

    


    return 0;
}