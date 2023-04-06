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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return helper(inorder, postorder, 0, n - 1, 0, n - 1, mp);
    }
    TreeNode* helper(vector<int>& inorder, vector<int> &postorder, int inStart, int inEnd, int posStart, int posEnd, unordered_map<int, int> &mp) {
        if(inStart > inEnd || posStart > posEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[posEnd]);
        
        int inRoot = mp[root -> val];
        int numsLeft = inRoot - inStart;
        
        root -> left = helper(inorder, postorder, inStart, inRoot - 1, posStart, posStart + numsLeft - 1, mp);
        root -> right = helper(inorder, postorder, inRoot + 1, inEnd, posStart + numsLeft, posEnd - 1, mp);
        
        return root;
    }
};