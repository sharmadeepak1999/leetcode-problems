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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root -> val == key) return helper(root);
        
        TreeNode* dummy = root;
        
        while(root) {
            if(root -> val < key) {
                if(root -> right && root -> right -> val == key) {
                    root -> right = helper(root -> right);
                    break;
                } else root = root -> right;
            } else {
                if(root -> left && root -> left -> val == key) {
                    root -> left = helper(root -> left);
                    break;
                } else root = root -> left;
            }
        }
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root) {
        if(!root -> left) return root -> right;
        if(!root -> right) return root -> left;
        
        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRightChild(root -> left);
        lastRight -> right = rightChild;
        return root -> left;
    }
    
    TreeNode* findLastRightChild(TreeNode* root) {
        while(root -> right) root = root -> right;
        return root;
    }
};