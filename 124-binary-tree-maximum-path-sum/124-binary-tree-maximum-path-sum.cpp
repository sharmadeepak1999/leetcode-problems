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
    int getMaxPathSum(TreeNode* root, int &pathSum) {
        if(root == NULL) return 0;
        
        int left = max(0, getMaxPathSum(root -> left, pathSum));
        int right = max(0, getMaxPathSum(root -> right, pathSum));
        
        pathSum = max(pathSum, left + right + root -> val);
        
        return root -> val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        getMaxPathSum(root, pathSum);
        return pathSum;
    }
};