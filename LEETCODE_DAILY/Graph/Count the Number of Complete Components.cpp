// MEDIUM
// LEETCODE 2192
// LEETCODE 2685


/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.


Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 
*/


#include<bits/stdc++.h>

using namespace std;

class Solution{
    vector<int> parent;
    private:

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x,  int y){
        parent[y] = x;  
    }

//dfs method

    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &v, int &e){
        visited[i] = true;
        v++;
        e = e + adj[i].size();

        for(auto &n : adj[i]){
            if(visited[n] == false){
                dfs(n, adj, visited, v, e);
            }
        }
    }


    public:

//dfs method

    int countCompleteComponents(int n, vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;

        int result = 0;


        //build graph
        for(auto &edge : edges){
            int u = edge[0];
            int  v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);

        for(int i=0; i<n ; i++){
            if(visited[i] == true){
                continue;
            }
            int v  =0 ;
            int e = 0;
            dfs(i, adj, visited, v, e);

            if((v * (v-1) / 2 ) == e/2){
                result++;
            }
        }

        return result;
    }

//my method
    int countCompleteComponents_myMethod(int n, vector<vector<int>>& edges){
        parent.resize(n);

        //initialize parent
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        //update parent using edges
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                Union(parent_u, parent_v);
            }
        }

        unordered_map<int, int>mp;
        unordered_map<int, int>edgeCount;
        // unordered_set<int> st;

        for(auto &x : parent){
            // st.insert(x);
            mp[x]++;
        }

        for(auto &x : edges){
            int u = x[0];
            int v = x[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u == parent_v){
                edgeCount[parent_u]++;
            }
        }
    }
};

int main(){

    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};


    return 0;
}