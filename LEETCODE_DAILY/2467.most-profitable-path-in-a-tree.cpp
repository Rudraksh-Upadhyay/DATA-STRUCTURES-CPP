#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
class Solution {
public:
    int aliceIncome;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    

    bool DFSbob(int curr, vector<bool>& visited, int time){
        visited[curr] = true;
        bobMap[curr] = time;

        //base case
        if(curr == 0){ //target reached
            return true;
        }

        //agar target reach nahi hua hai
        // toh hum node ke neighbours mei traverse krenge
        for(auto &n : adj[curr]){
            if(!visited[n]){
                if(DFSbob(n, visited, time + 1) == true){
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;

    }  // iss function se aapka bobMAP hai...woh fully update ho jayega

    //ab aate hai alice pr
    void DFSalice(int curr, int time, int income, vector<bool>& visited, vector<int>& amount){
        visited[curr] = true;

        //base cases->

        //first -> agar alice joh hai woh...bob se pehle aa gayi...toh usko full amount mil jayega yah dena padega
        //yah phir... bob joh hai ...woh..alice ke node mei kabhi aaya hi nahi...toh bhi same result
        if(bobMap.find(curr) == bobMap.end() || time < bobMap[curr]){
            income += amount[curr];
        }

        //second -> agar alice aur bob ki timing same ho
        else if(time == bobMap[curr]){
            income += (amount[curr] / 2);
        }

        //third -> leaf node aa gaya
        //agar leaf node aa jaye toh yaha 2 observations hoti hai
        //observation 1-> adj list of the leaf node willl have only one element/node connected
        //observation 2-> adj list of the starting node will also have oone element/node only...so humko yeh case exclude krna hai

        if(adj[curr].size() == 1 && curr != 0){
            aliceIncome = max(income, aliceIncome);
        }



        //now neighbour mei travese krna hai
        for(auto& n : adj[curr]){
            if(!visited[n]){
                DFSalice(n, time + 1, income, visited, amount);
            }
        }
        
    }



    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //number of nodes
        int n = amount.size();
        aliceIncome = INT_MIN;
        
        //adjacency list banayenge
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);  //undirected graph diya hua hai question mei
        }

        //DFS on bob aur {NODE, TIME} map krenge BOB ka
        int time = 0;
        vector<bool> visited(n, false);
        DFSbob(bob, visited, time);

        //abhi harama BOB ka {NODE, TIME} map ban chuka hoga
        //ab alice ko traverse karaenge
        int income  = 0;
        visited.assign(n, false);
        DFSalice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};
// @lc code=end

