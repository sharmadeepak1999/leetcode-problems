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
    int helper(TreeNode* root, int &dia) {
        if(root == NULL) return 0;
        
        int lh = helper(root -> left, dia);
        int rh = helper(root -> right, dia);
        
        dia = max(dia, lh + rh);
        
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root, dia);
        return dia;
    }
};