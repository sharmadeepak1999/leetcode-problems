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
    /*
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        return 1 + max(height(root -> left), height(root -> right));
    } 
    bool isBalanced(TreeNode* root) {
        // this approach calculate the height for every node, so for n nodes it could take n * n time, so to optimize this we could modify the height function only to return -1, if at any point in computing the height we get the height of the left and right tree differ by more than 1.
        if(root == NULL) return true;
        int left = height(root -> left);
        int right = height(root -> right);
        return abs(left - right) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
    */
    int check(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = check(root -> left);
        if(left == -1) return -1;
        int right = check(root -> right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        // this is a modification of the height function to return -1, if we found any node to be unbalanced.
        if(root == NULL) return true;
        return check(root) != -1;        
    }
};