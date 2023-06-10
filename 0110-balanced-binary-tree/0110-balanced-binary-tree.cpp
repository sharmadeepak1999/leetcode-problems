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
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        int left = helper(root -> left);
        if(left == -1) return -1;
        int right = helper(root -> right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        if(helper(root) == -1) return false;
        return true;
    }
};