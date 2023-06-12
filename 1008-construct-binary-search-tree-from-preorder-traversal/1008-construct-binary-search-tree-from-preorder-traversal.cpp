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
    TreeNode* build(vector<int> &preorder, int s, int e) {
        if(s > e) return NULL;
        
        TreeNode* node = new TreeNode(preorder[s]);
        
        int i = s + 1;
        while(i <= e && preorder[i] < preorder[s]) i++;
        node -> left = build(preorder, s + 1, i - 1);
        node -> right = build(preorder, i, e);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};