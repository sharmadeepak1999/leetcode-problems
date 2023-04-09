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
    vector<int> helper(TreeNode* root, int& maxi) {
        if(root == NULL) return { 0, INT_MAX, INT_MIN};
        
        vector<int> left = helper(root -> left, maxi);
        vector<int> right = helper(root -> right, maxi);
        
        if(root -> val <= left[2] || root -> val >= right[1]) {
            return { max(left[0], right[0]), INT_MIN, INT_MAX };
        }
        maxi = max(maxi, root -> val + left[0] + right[0]);
        return { root -> val + left[0] + right[0], min(root -> val, left[1]), max(root -> val, right[2]) };
    }
    int maxSumBST(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi >= 0 ? maxi : 0;
    }
};