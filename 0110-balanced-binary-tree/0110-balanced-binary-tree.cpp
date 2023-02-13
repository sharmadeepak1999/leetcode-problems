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
    /*
    int height(TreeNode *node) {
        if(node == NULL) return 0;
        return 1 + max(height(node -> left), height(node -> right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int hl = height(root -> left);
        int hr = height(root -> right);
        
        if(abs(hl - hr) > 1) return false;
        
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
    */
    int check(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = check(root -> left);
        int rh = check(root -> right);
        
        if(lh == -1 || rh == -1) return -1;
        
        if(abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int res = check(root);
        if(res == -1) return false;
        return true;
    }
};