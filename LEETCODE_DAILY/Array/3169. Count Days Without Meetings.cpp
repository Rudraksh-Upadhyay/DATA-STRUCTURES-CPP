/* MERGING INTERVALS */


#include<bits/stdc++.h>

using namespace std;

int countDays(int days, vector<vector<int>> &meetings){
    int n = meetings.size();
    sort(meetings.begin(), meetings.end());

    /*
    (1, 3) (5, 7)  ---->sorted meetings
    starting = 5
    ending = 3
    daysoff = starting - ending - 1
            = 5 - 3 - 1
            = 1 ----> (4)
    */

    int daysoff = 0;
    int ending = 0;

    for(int i=0; i<n; i++){
        if(meetings[i][0] > ending){
            daysoff += meetings[i][0] - ending - 1;
            // ending = max(ending, meetings[i][1]);
        }
        ending = max(ending, meetings[i][1]);
    }

    if(ending < days){
        daysoff += days - ending;
    }

    return daysoff;

}

int main(){

    int days = 5;
    vector<vector<int>> meetings = {{2,4}, {1, 3}};

    int ans = countDays(days, meetings);

    cout << ans <<endl;

    return 0;
}