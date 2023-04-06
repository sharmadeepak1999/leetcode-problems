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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        int n = inorder.size();
        
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return helper(preorder, inorder, 0, n - 1, 0, n - 1, mp);
    }
    TreeNode* helper(vector<int> &preorder, vector<int>&inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &mp) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root -> val];
        
        int numsLeft = inRoot - inStart;
        root -> left = helper(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1, mp);
        root -> right = helper(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, mp);
        
        return root;
    }
};