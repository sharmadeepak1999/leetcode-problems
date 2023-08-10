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
    int helper(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, unordered_map<TreeNode*, int>> &dp) {
        if(root == NULL) return 0;
        if(dp[root][prev] != 0) return dp[root][prev];
        if(prev && (prev -> left == root || prev -> right == root)) return dp[root][prev] = helper(root -> left, prev, dp) + helper(root -> right, prev, dp);
        return dp[root][prev] = max(root -> val + helper(root -> left, root, dp) + helper(root -> right, root, dp), helper(root -> left, prev, dp) + helper(root -> right, prev, dp));
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<TreeNode*, int>> dp;
        return helper(root, NULL,dp);
    }
};