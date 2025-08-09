#include<bits/stdc++.h>

using namespace std;

class Solution{

    vector<int> parent;
    
    private:

    

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = find(parent[x]);
        }
    }


    public:

    int findCircleNum(vector<vector<int>> &isConnected){
        vector<vector<int>> edges;

        int n = isConnected.size();

        parent.resize(n + 1, 0);

        for(int i=0;i <n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    edges.push_back({i, j});
                }
            }
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                parent[parent_v] = parent_u;
            }
        }

        unordered_set<int> st;

        for(auto x : parent){
            st.insert(x);
        }

        return st.size();
    }
};

int main(){

    vector<vector<int>> isConnected  = {{1,0, 0}, {0,1,0}, {0,0,1}};

    Solution sol = Solution();

    cout << sol.findCircleNum(isConnected) << endl;


    return 0;
}