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
    int helper(TreeNode* root, int curr) {
        if(root -> left == NULL && root -> right == NULL) return curr * 10 + root -> val;
        int res = 0;
        if(root -> left) res += helper(root -> left, curr * 10 + root -> val);
        if(root -> right) res += helper(root -> right, curr * 10 + root -> val);
        return res;
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};