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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        return 1 + max(left, right);
    }
    void helper(TreeNode* root, int &maxi) {
        if(root == NULL) return;
        
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        
        maxi = max(maxi, leftHeight + rightHeight);
        
        helper(root -> left, maxi);
        helper(root -> right, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root, maxi);
        return maxi;
    }
};