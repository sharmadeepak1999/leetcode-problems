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
    int helper(TreeNode* root, int &mpsum) {
        if(root == NULL) return 0;
        
        int ls = max(0, helper(root -> left, mpsum));
        int rs = max(0, helper(root -> right, mpsum));
        mpsum = max(mpsum, ls + rs + root -> val);
        return root -> val + max(ls, rs);
        
    }
    int maxPathSum(TreeNode* root) {
        int mpsum = INT_MIN;
        helper(root, mpsum);
        return mpsum;
    }
};