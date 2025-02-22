/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return ans;

        int maxLength = INT_MAX;
        for(auto x : strs){
            if(x.length() < maxLength) maxLength = x.length();
        }

        for(int i=0; i<maxLength; i++){
            char current = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != current){
                    return ans;
                }
            }
            ans += current;
        }

        return ans;


    }
};
// @lc code=end

