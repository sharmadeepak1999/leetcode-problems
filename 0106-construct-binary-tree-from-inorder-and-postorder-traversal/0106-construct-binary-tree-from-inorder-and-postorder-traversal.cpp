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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ri, int re) {
        if(is > ie || ri > re) return NULL;
        int i = is;
        while(inorder[i] != postorder[re]) i++;
        
        TreeNode* root = new TreeNode(inorder[i]);
        
        root -> left = helper(inorder, postorder, is, i - 1, ri, ri + i - is - 1);
        root -> right = helper(inorder, postorder, i + 1, ie, ri + i - is, re - 1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};