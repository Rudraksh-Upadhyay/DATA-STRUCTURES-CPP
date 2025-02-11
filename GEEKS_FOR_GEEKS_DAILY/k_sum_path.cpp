#include<iostream>
#include<unordered_map>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:

        void solve(Node* root, int k, int currSum, int &count, unordered_map<int, int>&mp){
            if(root == NULL){
                return;
            }

            currSum += root->data;

            if(currSum == k){
                count++;
            }

            if(mp.find(currSum - k) != mp.end()){
                count += mp[currSum - k];
            }

            mp[currSum]++;

            solve(root->left, k, currSum, count, mp);
            solve(root->right, k , currSum, count, mp);

            mp[currSum]--;

        }

        int sumK(Node* root, int k){
            unordered_map<int, int>mp;
            int count = 0;
            solve(root, k, 0, count, mp);
            return count;
        }

            
        
};


int main(){

    return 0;
}