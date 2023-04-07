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
    TreeNode* helper(vector<int> &preorder, int ps, int pe) {
        if(ps > pe) return NULL;
        
        int rootData = preorder[ps];
        TreeNode* root = new TreeNode(rootData);
        
        int left = ps + 1;
        
        while(left <= pe && preorder[left] < rootData) left++;
        root -> left = helper(preorder, ps + 1, left - 1);
        root -> right = helper(preorder, left, pe);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};