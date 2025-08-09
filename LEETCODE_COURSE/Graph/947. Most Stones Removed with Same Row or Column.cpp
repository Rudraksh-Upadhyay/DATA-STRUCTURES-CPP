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

    int removeStones(vector<vector<int>> &stones){

        int n = stones.size();
        
        parent.resize(n, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                   
                    int parent_u = find(i);
                    int parent_v = find(j);

                    parent[parent_v] = parent_u;
                }
                
            }
        }


        int grps = 0;

        for(int i=0; i<n ;i++){
            if(parent[i] == i){
                grps++;
            }
        }
        return n - grps;
    }
};

int main(){

    Solution sol = Solution();

    vector<vector<int>> stones = {{0, 1}, {0, 2}, {4, 3}, {2, 4}, {0, 3}, {1,1}};

    cout << sol.removeStones(stones) << endl;

    return 0;
}