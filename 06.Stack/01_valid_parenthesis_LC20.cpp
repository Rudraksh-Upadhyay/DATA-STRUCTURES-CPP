#include<iostream>
#include<stack>

using namespace std;

class Solution{
    public:

    bool isValid (string s){
        
        stack<char> st;
        int size = s.length();

        for(int i=0; i<size; i++){
            char ch = s[i];

            //ch -> open/close bracket
            // open -> push into the stack
            // close -> pop from the stack-> check krta hu ki same type ka open hai ki nahi

            //open
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }

            //close
            //main stack ke top mei check krunga
            //ke mujhe same type ka close bracket mila ki nahi

            else{

                if(ch == ')' && !st.empty() && st.top() == '('){
                    st.pop();
                }

                else if(ch == ']' && !st.empty() && st.top() == '['){
                    st.pop();
                }

                else if(ch == '}' && !st.empty() && st.top() == '{'){
                    st.pop();
                }

                else{
                    return false;
                }
            }
        } 
        
        return st.empty();
    }
};


int main(){

    Solution sol = Solution();
    
    string s = "(){}";

    cout << sol.isValid(s) << endl;


    return 0;
}