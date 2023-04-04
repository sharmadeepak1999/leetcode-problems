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
    bool helper(TreeNode* a, TreeNode *b) {
        if(a == NULL || b == NULL) return a == b;
        
        if(a -> val != b -> val) return false;
        
        return helper(a -> left, b -> right) && helper(a -> right, b -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root -> left, root -> right);
    }
};