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
    void getDiameter(TreeNode* root, int &diameter) {
        if(root == NULL) return;
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        diameter = max(diameter, lh + rh);
        
        getDiameter(root -> left, diameter);
        getDiameter(root -> right, diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // in this approach we get to each node, and calculate the diameter at that node using the left and right height, lh + rh, if it is max till now then update the diameter, and call the diameter function for the left and right child. this will take time complexity n^2, as we will compute the height of the tree for every node. 
        int diameter = INT_MIN;
        getDiameter(root, diameter);
        return diameter;
    }
    */
    
    int getDiameter(TreeNode* root, int &diameter) {
        if(root == NULL) return 0;
        
        int lh = getDiameter(root -> left, diameter);
        int rh = getDiameter(root -> right, diameter);
        
        diameter = max(diameter, lh + rh);
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // this approach is modification of the height function, instead of calculating height at every node, we can just call the height function once, and whenever it calculates the value of lh and rh we can check if there sum is the maximum so far, if yes then we can update diameter to it.
        if(root == NULL) return 0;
        int diameter = 0;
        
        getDiameter(root, diameter);
        return diameter;
    }
};