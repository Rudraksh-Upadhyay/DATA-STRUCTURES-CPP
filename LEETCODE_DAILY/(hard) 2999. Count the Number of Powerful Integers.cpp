#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:

    long long solve(string &num, string &suffix, int limit){
        //base case
        if(num.length() < suffix.length()){
            return 0;
        }
        int n = num.length();
        long long count = 0;

        string trailString = num.substr(n - suffix.length());

        int remainL = num.length() - suffix.length();

        for(int i=0; i<remainL; i++){
            int digit = num[i] - '0';
            if(digit <= limit){
                count += digit * pow(limit + 1, remainL - i - 1);
            }
            else{
                count += pow(limit + 1, remainL - i);
                return count;
            }
        }

        if(trailString >= suffix){
            count += 1;
        }


        return count;

    }

    public:

    long long numberOFPowerfulInt(long long start, long long finish, int limit, string s){
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};  

int main(){
    
    return 0;
}