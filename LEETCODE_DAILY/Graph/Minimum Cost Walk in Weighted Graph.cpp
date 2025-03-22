//HARD LEETCODE 3108

/*
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

Example 1:

Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

Output: [1,-1]

To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).

In the second query, there is no walk between nodes 3 and 4, so the answer is -1.

Example 2:

Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

Output: [0]
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

    void Union(int x, int y){
        parent[y] = x;
    }

    public:

    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>>&query){
        parent.resize(n);

        vector<int> cost(n);

        //initializing parent
        for(int i=0; i<n; i++){
            parent[i] = i;
            cost[i] = -1;
        }

        for(auto &edge  :  edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                Union(parent_u, parent_v); // means dono different compoenent mei hai...toh union kr denge
                cost[parent_u] &= cost[parent_v];
            }

            cost[parent_u] &= w;
        }


        //query ko prrocess krna hai
        vector<int> result;
        for(auto &q : query){
            int s = q[0];
            int t = q[1];

            int parent_s = find(s);
            int parent_t = find(t);

            if(s == t){
                //source aur targeet dono same hai...toh kuch walk krna hi nahi hai
                result.push_back(0);
            }
            else if(parent_s != parent_t){ //source aur target different compoenent mei hai
                result.push_back(-1);
            }
            else{
                //dono same componenet mei hai
                result.push_back(cost[parent_s]); 
            }
        }

        return result;
    }

};

int main(){

    Solution sol = Solution();

    int n = 5;
    vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
    vector<vector<int>> query = {{0, 3}, {3, 4}};

    vector<int> ans = sol.minimumCost(n, edges, query);

    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}