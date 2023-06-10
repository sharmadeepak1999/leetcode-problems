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
        int right = helper(root -> right);
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int leftHeight = helper(root -> left);
        int rightHeight = helper(root -> right);
        
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};