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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl = 1;
        while(!q.empty()) {
            int size = q.size();
            
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front -> right) q.push(front -> right);
                if(front -> left) q.push(front -> left); 

                level.push_back(front -> val);
            }
            if(lvl & 1) reverse(level.begin(), level.end());
            lvl++;
            ans.push_back(level);
        }
        return ans;
    }
};