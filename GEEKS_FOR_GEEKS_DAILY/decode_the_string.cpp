//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include<stack>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void solve(string &s, string &ans){
        int n = s.length();
        stack<char> str;
        stack<char> num;

        for(int i = 0; i < n; i++){
            if(s[i] == '['){
                str.push(s[i]);
                num.push(s[i]);
            }
            if(isdigit(s[i])){
                num.push(s[i]);
            }
            else if(s[i] == ']'){

                string temp = ans;
                while(!str.empty() && str.top() != '['){
                    temp = temp + str.top();
                    str.pop();
                }

                
                if(!str.empty() && str.top() == '['){
                    str.pop();
                }

                //extracting the number

                string numStr = "";
                num.pop(); //because top mei '[' hoga
                while(!num.empty() && num.top() != '['){
                    numStr += num.top();
                    num.pop();
                }

                reverse(numStr.begin(), numStr.end());
                int k = stoi(numStr);

                for(int i=0; i<k-1; i++){
                    ans = ans + temp;
                }
            }
            else{
                str.push(s[i]);
            }
        }

        reverse(ans.begin(), ans.end());
    }
    string decodedString(string &s) {
        // code here
        string ans = "";
        solve(s, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends