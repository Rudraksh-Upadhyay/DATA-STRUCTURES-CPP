#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution{

    private:
        vector<int> nextSmallestElement(vector<int> & arr, int n){
            stack<int>st;
            st.push(-1);

            vector<int> ans(n);

            for(int i=n-1 ; i>=0; i--){
                while(st.top() != -1 && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                ans[i] = st.top();
                st.push(i);
            }

            return ans;
        }

        vector<int> prevSmallestElement(vector<int> & arr, int n){
            stack<int> st;
            st.push(-1);
            vector<int> ans(n);

            for(int i=0 ; i<=n-1; i++){
                while(st.top() != -1 && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }

            return ans; 
        }

    public:

        int largestRectangleArea(vector<int> & heights){
            int n = heights.size();

            vector<int> next;
            next = nextSmallestElement(heights, n);

            vector<int> prev;
            prev = prevSmallestElement(heights, n);

            int area = INT_MIN;

            for(int i=0; i<n; i++){
                int l = heights[i];
                if(next[i] == -1){
                    next[i] = n;
                }
                int b = next[i] - prev[i] - 1;

                area = max(area, l*b);
            }

            return area;
        }
};

int main(){

    vector<int> heights = {2, 2, 2};
    Solution sol = Solution();
    
    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}