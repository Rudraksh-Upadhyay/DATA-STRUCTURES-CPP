/*
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 
Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.

Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

//BFS SOLUTION - TLE
class Solution_bfs{

    private:
    int bfs(vector<vector<int>> &grid, int value, int m , int n){
    
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
    
        int points = 0;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto [i, j] = q.front();
                q.pop();

                if(grid[i][j] >= value){
                    continue;
                }

                points++;

                for(auto &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < value){
                        q.push({i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
        }

        return points;
    }
    
    public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries){
        int m = grid.size();
        int n = grid[0].size();
    
        int Q = queries.size();
    
        vector<int> result(Q,0);
    
        for(int i=0; i<Q; i++){
            result[i] = bfs(grid, queries[i], m, n);
        }
        return result;
    }
};

//DFS SOLUTION - TLE

class Solution_dfs{
    private:
    int dfs(vector<vector<int>> &grid, int i, int j, int value, vector<vector<bool>> &visited, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= value){
            return 0;
        }

        visited[i][j] = true;
        int points = 1;

        for(auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            points += dfs(grid, i_, j_, value, visited, m, n);
        }
        return points;
    }

    public:

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries){
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();

        vector<int> result (Q, 0);
        vector<vector<bool>> visited (m, vector<bool> (n, false));

        for(int i=0; i<Q; i++){
            result[i] = dfs(grid, 0, 0, queries[i],  visited, m, n);
        }

        return result;
    }
};


//OPTIMAL SOLUTION

class Solution_optimal{

    public:

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries){
        int m = grid.size();
        int n = grid[0].size();
        int q_size = queries.size();

        vector<int> result(q_size, 0);

        vector<pair<int, int>> sortedQ;

        for(int i=0; i<q_size; i++){
            sortedQ.push_back({queries[i], i});
        }

        sort(sortedQ.begin(), sortedQ.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        for(int i=0; i<q_size; i++){
            int value = sortedQ[i].first;
            int index = sortedQ[i].second;

            while(!pq.empty() && pq.top()[0] < value){
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && visited[i_][j_] == false){
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[index] = points;
        }

        return result;
    }


};

int main(){


    vector<vector<int>> grid = {{1, 2, 3}, {2, 5 ,7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};

    // Solution_bfs solbfs = Solution_bfs();
    Solution_optimal soloptimal = Solution_optimal();

    // vector<int> result = solbfs.maxPoints(grid, queries);
    vector<int> result = soloptimal.maxPoints(grid, queries);

    for(auto &i : result){
        cout<< i << " ";
    }
    cout<< endl;



    return 0;
}