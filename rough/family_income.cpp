#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<int> net_worth;
int max_diff = 0;

// DFS to calculate max difference
void dfs(int node, int min_val, int max_val) {
    // Update the maximum difference using the current node
    max_diff = max(max_diff, abs(net_worth[node] - min_val));
    max_diff = max(max_diff, abs(net_worth[node] - max_val));
    
    // Update the min and max values for the current path
    min_val = min(min_val, net_worth[node]);
    max_val = max(max_val, net_worth[node]);
    
    // Continue DFS on children
    for (int child : tree[node]) {
        dfs(child, min_val, max_val);
    }
}

int main() {
    int n;
    cin >> n;
    
    net_worth.resize(n + 1);
    vector<int> parent(n + 1);
    tree.resize(n + 1);
    
    // Input net worth
    for (int i = 1; i <= n; i++) {
        cin >> net_worth[i];
    }
    
    // Input parent array and construct tree
    int root = -1;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) {
            root = i;
        } else {
            tree[parent[i]].push_back(i);
        }
    }
    
    // Edge case: Single node
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Perform DFS from root to calculate max difference
    dfs(root, net_worth[root], net_worth[root]);
    
    // Output the maximum difference
    cout << max_diff << endl;
    
    return 0;
}
