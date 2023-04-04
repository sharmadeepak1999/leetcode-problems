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
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        
        return 1 + max(height(root -> left), height(root -> right));
    }
    bool helper(TreeNode *root) {
        if(root == NULL) return true;
        
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        
        if(abs(leftHeight - rightHeight) > 1) return false;
        
        return helper(root -> left) && helper(root -> right);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};