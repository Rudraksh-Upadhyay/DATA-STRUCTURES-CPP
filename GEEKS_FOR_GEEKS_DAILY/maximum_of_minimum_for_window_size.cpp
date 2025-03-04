//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
    
    vector<int> prevSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> left(n, -1);
        stack<int> s;
        
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        }
        
        return left;
    }
    
    vector<int> nextSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> right(n, n);
        stack<int> s;
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }
        
        return right;
    }
    
    
  public:
 
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> ans(n);
        
        vector<int> leftsmall = prevSmaller(arr);
        vector<int> rightsmall = nextSmaller(arr);
        
        for(int i =0; i < n; i++) {
            int len = rightsmall[i] - leftsmall[i] - 1;
            
            int num = max(ans[len-1], arr[i]);
            ans[len-1] = num;
        }
        
        for(int i= n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends