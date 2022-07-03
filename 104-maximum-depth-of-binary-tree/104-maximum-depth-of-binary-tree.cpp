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
    int maxDepth(TreeNode* root) {
        // recursive approach
        if(root == NULL) return 0;
        
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
    */
    
    
    int maxDepth(TreeNode* root) {
        // using level order traversal approach
        
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        int depth = 0;
        while(!q.empty()) {
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
        }
        return depth;
    }
};