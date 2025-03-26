#include<bits/stdc++.h>

/*IDEA
for(int &num : vect){
    if(num % x != target % x){
        return -1;
    }
    result += abs(target - num) / x;
}
return result;
}*/

using namespace std;

int minOperations(vector<vector<int>> &grid, int x){
    int m = grid.size();
    int n = grid[0].size();

    vector<int> vec;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            vec.push_back(grid[i][j]);
        }
    }

    int result = 0;

    int gridSize = m * n; 
    sort(vec.begin(), vec.end());
    int target = vec[gridSize / 2];

    for(int &num : vec){
        if(num%x != target%x){
            return -1;
        }
        result += abs(target-num) / x;
    }

    return result;
}


int main()
{

    return 0;
}