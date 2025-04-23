// REMOVE K DIGITS
//LEET CODE -> 402 (MEDIUM)

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.length();

        stack<int> st;

        //push first element from num
        st.push(num[0] - '0');

        //push remaining element from num
        for(int i=1; i<n; i++){
            while(!st.empty() && st.top() > (num[i] - '0') && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }

        //remove remaining k digits
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        //convert stack to string
        string ans = "";
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }

        //reverse the string
        reverse(ans.begin(), ans.end());

        //removing the leading zeros if any
        int i=0; 
        int ans_n = ans.length();
        while(i < ans_n && ans[i] == '0'){
            i++;
        }

        return ans.substr(i);
    }
};

int main(){

    Solution sol = Solution();

    string num = "1432219";
    int k = 3;

    cout << sol.removeKdigits(num, k) << endl;


    return 0;
}