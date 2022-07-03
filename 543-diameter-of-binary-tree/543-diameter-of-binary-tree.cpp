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
        
        return 1 + max(height(root -> left), height(root -> right));
    }
    void getDiameter(TreeNode* root, int &diameter) {
        if(root == NULL) return;
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        diameter = max(diameter, lh + rh);
        
        getDiameter(root -> left, diameter);
        getDiameter(root -> right, diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        getDiameter(root, diameter);
        return diameter;
    }
};