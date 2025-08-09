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

    public:

    vector<int> findRedundantConnection(vector<vector<int>> &edges){
        int n = edges.size();

        parent.resize(n + 1, 0);

        // for(int i=0; i<n; i++){
        //     parent[i] = i;
        // }
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u == parent_v){
                return edge;
            }
            else{
                parent[parent_v] = parent_u;
            }
        }
        return {};
    }
};
int main(){

    Solution sol = Solution();

    vector<vector<int>> arr = {{1, 2}, {2, 3}, {3, 4}, {1,4 }, {1, 5}};

    vector<int> ans = sol.findRedundantConnection(arr);

    cout << ans[0] << " " << ans[1] << endl;


    return 0;
}