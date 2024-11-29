//LEET CODE 1781

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    int beautySum(string s){
        int beautySum  = 0;
        unordered_map<char, int>mp;
        int size = s.size();
        
        //find all substrings
        for(int i=0; i<size; i++){
            mp.clear();
            for(int j=i; j<size; j++){
                
                char &ch = s[j];
                mp[ch]++; //freq update of the char

                int mini = INT_MAX;
                int maxi = INT_MIN;

                //find most the least freq char from the map
                for(auto each:mp){
                    maxi =  max(maxi, each.second);
                    mini = min(mini, each.second);
                }

                int diff = abs(maxi-mini);
                if(diff!=0){
                    beautySum++;
                }
            }
            
        }
        
        return beautySum;
    }
};

int main(){

    Solution sol = Solution();

    string str = "aabcb";

    int ans = sol.beautySum(str);

    cout << "beauty->" << ans << endl;



    return 0;
}