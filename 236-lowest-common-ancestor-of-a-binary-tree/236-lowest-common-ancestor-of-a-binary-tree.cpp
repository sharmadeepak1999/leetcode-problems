/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // a brute force approach would be to get the path to both the nodes, and store it in an array now traverse both the path when a node is not matching then the previous node will be the lca.
        
        // a better approach would be traverse the array in preorder fashion, if the current node is equal to one of the node, then return this node, if not then traverse for the left and the right tree, if they both return NULL then return NULL, if they both return not null, then we can say that the current node must be the LCA, and return the current node.
        
        if(root == NULL) return NULL;

        if(root == p) return p;
        if(root == q) return q;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left != NULL && right != NULL) return root;
        
        return left ? left : right;
    }
};