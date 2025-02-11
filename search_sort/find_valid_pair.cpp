/*Find Valid Pair
Write a program that reads an integer n followed by n pairs of integers. Given two additional integers left and right, the program should print all pairs whose sum and product fall within the inclusive range [left, right].

Input Format
The first line contains an integer n, representing the number of pairs.
The next n lines each contain two integers, representing a pair of elements.
The next line contains two integers left and right, defining the inclusive range for the sum and product of the pairs.

Output Format
Print each pair of integers (a, b) on a new line if both the sum and the product of a and b are within the range [left, right].

*/


#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int, int>> p;

    for(int i=0;i <n ; i++){
        int u, v;
        cin >> u >> v;
        p.push_back({u,v});

    }

    int start, end;
    cin >> start  >> end;

    for(auto x : p){
        int sum = x.first + x.second;
        int product = x.first * x.second;

        if(sum >= start && sum <= end && product >= start && product <= end){
            cout << x.first << " " << x.second << endl;
        }
    }


    return 0;
}