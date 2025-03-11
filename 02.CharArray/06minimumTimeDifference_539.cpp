#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Solution{
    public:
    int findMinDifference(vector<string> & timePoints){
        
        int subhour;
        int submin;

        vector<int> minCom;

        // int s = timePoints.size();
        // for(int i =0; i<s; i++){
        //     if(timePoints[i] == "00:00"){
        //         timePoints.push_back("24:00");
        //     }
        // }

        // for(int i=0; i<s; i++){
        //     if(stoi(timePoints[i].substr(0,2)) > 12){

        //     }
        // }

        // string hr = timePoints.substr(0,2);

        for(const auto& str : timePoints){
            subhour = stoi(str.substr(0,2));
            submin = stoi(str.substr(3,2));

            int min = subhour * 60 + submin;
            minCom.push_back(min);

            if(subhour < 12){
                subhour += 12;
                int min = subhour * 60 + submin;
                minCom.push_back(min);
            }

        }

        // AP MINCOM MEI DIFFERENCE NIKALNA HAI

        int minDiff = INT_MAX;
        int n = minCom.size();

        for(int i=0 ; i<n-1; i++){
            for(int j=i+1; j < n; j++){
                if(abs(minCom[i] - minCom[j]) < minDiff){
                    minDiff = abs(minCom[i] - minCom[j]);
                }
            }
        }

        return minDiff;

        // hours = stoi(subhour);
        // minutes = stoi(submin);

        // cout <<  hours << endl;
        // cout << minutes << endl;

    }
};

int main(){

    Solution sol = Solution();

    vector<string> time = {"02:39","10:26","21:43"};

    
    int ans = sol.findMinDifference(time);

    cout << "minimum time difference ->" << ans << endl;
    return 0;
}