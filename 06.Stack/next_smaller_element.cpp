/*
[2, 1, 4, 3]

[1, -1, 3, -1]*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){

        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);

    }

    return ans;
    
}
