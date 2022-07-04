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
    void helper(TreeNode* root, vector<string> &ans, string path) {
        if(root == NULL) return;
        
        if(!root -> left && !root -> right) {
            path.append(to_string(root -> val));
            ans.push_back(path);
            return;
        }
        path.append(to_string(root -> val) + "->");
        helper(root -> left, ans, path);
        helper(root -> right, ans, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        helper(root, ans, "");
        
        return ans;
    }
};