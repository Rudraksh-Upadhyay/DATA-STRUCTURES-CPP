//LEETCODE - 1976

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/

/*
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
*/


#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, int> P;
const int M = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads){


    unordered_map<int, vector<pair<int, int>>> adj;

    for(auto &road : roads){
        int u = road[0];
        int v = road[1];
        int time = road[2];

        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<long long> result(n, LLONG_MAX);
    vector<int> pathCount(n, 0);

    result[0] = 0;
    pathCount[0] = 1;

    pq.push({0, 0});  //time , node

    while(!pq.empty()){
        long long currTime  = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();


        for(auto &vec : adj[currNode]){
            int nextNode = vec.first;
            int nextTime = vec.second;


            if(currTime + nextTime < result[nextNode]){
                result[nextNode] = currTime + nextTime;
                pathCount[nextNode] = pathCount[currNode];
                pq.push({result[nextNode], nextNode});
            }

            else if (currTime + nextTime == result[nextNode]){
                pathCount[nextNode] = (pathCount[nextNode] + pathCount[currNode])   %  M ;
            }
        }
    }

    return pathCount[n-1];
}

int main(){

    return 0;
}