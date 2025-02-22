/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    TreeNode* solve(string s, int& i, int depth, int n){
        if(i >= n) return NULL;

        // dash calculate krenge
        int j = i;
        while(j < n && s[j] == '-') j++;

        int dash = j - i;

        // dash aur depth same hona chahiye
        // agar dash aur depth same hoga tabhi hum node create aur add krenge
        // warna NULL return krenge

        if(dash != depth){
            return NULL;
        }

        // value extract krenge
        i += dash;
        
        int value = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            value = value * 10 + (s[i] - '0');
            i++;
        }

        // node create krenge
        TreeNode* root = new TreeNode(value);

        // left aur right mei daal denge -> DFS
        root->left = solve(s, i, depth + 1, n);
        root->right = solve(s, i, depth + 1, n);


        return root;
    }


    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.length();

        int i = 0;
        int depth = 0;

        return solve(traversal, i, depth, n);

        
    }
};
// @lc code=end

