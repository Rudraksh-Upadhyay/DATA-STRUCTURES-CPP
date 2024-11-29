#include<iostream>
#include<unordered_map>
#include<vector>


using namespace std;


class Solution{
    public:

    int countCommonChild(string s1, string s2){
        int count = 0;
        unordered_map<char, int> mp;
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){

                if(s1[i]  == s2[j]){
                    mp[s1[i]]++;
                }
            }

        }

        for(auto each:mp){
            if(each.second > 0){
                count++;
            }
        }

        return count ;
    }

    int LargestCommonChild(string s1, string s2){
        // int count = 0;
        unordered_map<string, int> mp;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<string> s1subs;
        

        for(int i=0 ; i<n1; i++){
            for(int j=i; j<n1; j++){
                string subs = s1.substr(i, j-i+1);
                // mp[subs] = subs.size();
                s1subs.push_back(subs);
            }
        }
        for(int i=0 ; i<n2; i++){
            for(int j=i; j<n2; j++){
                string subs = s2.substr(i, j-i+1);

                for(int i=0 ; i<s1subs.size(); i++){
                    if(subs == s1subs[i]){
                        mp[subs] = subs.size();
                    }
                }
                
                // mp[subs] = subs.size();

            }
        }

        int maxi = INT_MIN;

        for(auto each:mp){
            int lenEach = each.second;
            maxi = max(lenEach, maxi);
        }
        

        return maxi;
    }
};

int main(){

    Solution sol = Solution();

    string s1 = "HARRY";
    string s2 = "SALLY";

    int ans = sol.LargestCommonChild(s1, s2);

    cout << ans <<endl;

    return 0;
}