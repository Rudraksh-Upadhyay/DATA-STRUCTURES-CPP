/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.


Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.

Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* left, TreeNode * right) : val(x), left(left), right(right){}
};

unordered_map<int, int>mp;
int maxD = 0;

void depth(TreeNode* root, int d){
    if(!root){
        return;
    }

    maxD = max(maxD, d);
    mp[root->val] = d;
    depth(root->left, d+1);
    depth(root->right, d+1);
}


TreeNode* LCA(TreeNode* root){
    if(!root || mp[root->val] == maxD){
        return root;
    }

    TreeNode* l = LCA(root->left);
    TreeNode* r = LCA(root->right);

    if(l != NULL && r != NULL){
        return root;
    }
    if(l != NULL){
        return l;
    }
    return r;
}


TreeNode* lcaDeepestLeaves(TreeNode* root){
    depth(root, 0);
    return LCA(root);

}

int main(){





    return 0;
}