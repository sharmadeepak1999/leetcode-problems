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
    int getMaxPathSum(TreeNode* root, int &pathSum) {
        // the intiution is similar to height/ diameter of the tree functions, we at any index, ask recursion to get us the left and righ path sum, then we check if the sum of left + right + current node is greater than the max path sum, if yes then update. we return the max path value we can get for a path passing through the current node, as current node + max(left, right). this is to tell which path should be taken to get max path sum if a path passes through the current node, we also have a check if the path sum returned by left or right is negative then we will not consider them and change them to 0, as adding negative value to our path will not give us maximum path sum.
        if(root == NULL) return 0;
        
        int left = max(0, getMaxPathSum(root -> left, pathSum));
        int right = max(0, getMaxPathSum(root -> right, pathSum));
        
        pathSum = max(pathSum, left + right + root -> val);
        
        return root -> val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        getMaxPathSum(root, pathSum);
        return pathSum;
    }
};