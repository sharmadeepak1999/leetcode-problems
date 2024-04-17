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
    void helper(TreeNode* root, string curr, string &ans) {
        if(root == NULL) return;
        char ch = 'a' + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            curr = ch + curr;
            if(curr < ans) ans = curr;
            return;
        }
        helper(root -> left, ch + curr, ans);
        helper(root -> right, ch + curr, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "|";
        helper(root, "", ans);
        return ans;
    }
};