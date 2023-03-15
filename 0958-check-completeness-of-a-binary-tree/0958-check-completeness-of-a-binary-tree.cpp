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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        bool warn = false;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(warn && (node -> left || node -> right)) return false;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                
                if(node -> left == NULL && node -> right) return false;
                if((node -> left && node -> right == NULL) || (node -> left == NULL && node -> right == NULL)) warn = true;
            }
            
        }
        return true;
    }
};