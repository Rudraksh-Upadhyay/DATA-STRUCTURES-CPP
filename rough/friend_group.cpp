#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <limits>
using namespace std;

// Function to perform BFS and calculate shortest distances from a start node
vector<int> bfs(int start, int n, vector<vector<int>>& graph) {
    vector<int> distances(n + 1, -1);
    queue<int> q;
    q.push(start);
    distances[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (distances[neighbor] == -1) {  // Not visited
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}

int main() {
    int numGroups;
    cin >> numGroups;
    
    while (numGroups--) {
        int n;
        cin >> n;
        
        vector<vector<int>> graph(n + 1);
        
        // Reading the friend lists
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int friendId;
                cin >> friendId;
                graph[i].push_back(friendId);
                graph[friendId].push_back(i);  // Since friendship is mutual
            }
        }
        
        double minNotoriety = numeric_limits<double>::max();
        int mostPopular = -1;
        
        // Calculate notoriety for each friend
        for (int i = 1; i <= n; ++i) {
            vector<int> distances = bfs(i, n, graph);
            double totalDistance = 0;
            
            for (int j = 1; j <= n; ++j) {
                totalDistance += distances[j];
            }
            
            double notoriety = totalDistance / n;
            
            if (notoriety < minNotoriety) {
                minNotoriety = notoriety;
                mostPopular = i;
            } else if (notoriety == minNotoriety && i < mostPopular) {
                mostPopular = i;
            }
        }
        
        // Output result for the current group
        cout << mostPopular << " " << fixed << setprecision(6) << minNotoriety << endl;
    }
    
    return 0;
}
