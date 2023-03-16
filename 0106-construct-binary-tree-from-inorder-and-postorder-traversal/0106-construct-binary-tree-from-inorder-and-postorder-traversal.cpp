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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s, int e, int ri) {
        if(s > e || ri == -1) return NULL;
        for(int j = ri; j >= 0; j--) {
            for(int i = s; i <= e; i++) {
                if(inorder[i] == postorder[j]) {
                    TreeNode* root = new TreeNode(inorder[i]);
                    root -> left = helper(inorder, postorder, s, i - 1, j - 1);
                    root -> right = helper(inorder, postorder, i + 1, e, j - 1);
                    return root;
                }
            }
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};