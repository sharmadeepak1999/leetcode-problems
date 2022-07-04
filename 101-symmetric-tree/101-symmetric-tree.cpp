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
    bool helper(TreeNode* node1, TreeNode* node2) {
        if(!node1 || !node2) return node1 == node2;
        
        if(node1 -> val != node2 -> val) return false;
        return helper(node1 -> left, node2 -> right) && helper(node1 -> right, node2 -> left);
    }
    bool isSymmetric(TreeNode* root) {
        // the intitution is that if we draw a line from the center then left becomes right, and right becomes left for the image in the mirror, so we will traverse the left and the right half in any traversal order simultaneously for example, root left right and root right left, we will match at each node if they are same or not, else return false.
        
        return helper(root -> left, root -> right);
    }
};