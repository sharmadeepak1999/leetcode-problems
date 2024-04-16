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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        
        int level = 1;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                cout << node -> val << "-> ";
                if(level == depth - 1) {
                        TreeNode* newLeft = new TreeNode(val);
                        TreeNode* temp1 = node -> left;
                        node -> left = newLeft;
                        newLeft -> left = temp1;

                        TreeNode* newRight = new TreeNode(val);
                        TreeNode* temp2 = node -> right;
                        node -> right = newRight;
                        newRight -> right = temp2;
                } else {
                    if(node -> left) q.push(node -> left);
                    if(node -> right) q.push(node -> right);
                }
            }
            
            level++;
        }
        return root;
    }
};