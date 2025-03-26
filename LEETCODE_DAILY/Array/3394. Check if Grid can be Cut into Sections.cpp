/* MERGING INTERVALS Q2 */

/*
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
*/


#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){
    int n = intervals.size();

    //sabse pehle ... intervals ko sort krenge
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for(int i=1; i<n; i++){
        if(result.back()[1] > intervals[i][0]){
            //overlapping
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

bool checkValidCuts(int n , vector<vector<int>> & rectangles){
    //x - axis
    vector<vector<int>> hor;

    //y-axis
    vector<vector<int>> ver;


    for(auto &coord : rectangles){
        int x1 = coord[0]; //bottom left
        int y1 = coord[1];
        int x2 = coord[2];  //top right
        int y2 = coord[3];

        hor.push_back({x1, x2});
        ver.push_back({y1, y2});
    }

    vector<vector<int>> horMerged = merge(hor);
    vector<vector<int>> verMerged = merge(ver);

    bool ans = false;

    int horSize = horMerged.size();
    int verSize = verMerged.size();

    if(horSize >= 3 || verSize >= 3){
        ans = true;
    }

    return ans;
}

int main(){

    // Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    // Output: true
    // int n = 5;
    // vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};

    // Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
    // output = true;

    // int n = 4;
    // vector<vector<int>> rectangles = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};

    //Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
    //Output: false;

    int n = 4;
    vector<vector<int>> rectangles = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};

    cout << checkValidCuts(n, rectangles) << endl;


    return 0;
}