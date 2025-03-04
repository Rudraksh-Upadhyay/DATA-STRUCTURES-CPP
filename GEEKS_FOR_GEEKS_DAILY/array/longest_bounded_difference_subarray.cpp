//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        vector<int> ans;
        
        
        int s = 0;
        int e = 0;
        
        int startans = 0;
        int endans = 0;
        
        deque<int> minq;
        deque<int> maxq;
        
        while(e < n){
            while(!maxq.empty() && arr[e] > arr[maxq.back()]){
                maxq.pop_back();
            }
            while(!minq.empty() && arr[e] < arr[minq.back()]){
                minq.pop_back();
            }
            maxq.push_back(e);
            minq.push_back(e);
            
            while(abs(arr[maxq.front()] - arr[minq.front()]) > x){
                if(s == maxq.front()){
                    maxq.pop_front();
                }
                if(s == minq.front()){
                    minq.pop_front();
                }
                s++;
            }
            
            if(e-s > endans - startans){
                endans = e;
                startans = s;
            }
            e++;
        }
        for(int i = startans; i<=endans; i++){
            ans.push_back(arr[i]);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends