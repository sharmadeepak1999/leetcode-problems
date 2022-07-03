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
        // either reverse the level array before adding to answer if the level is even, 0 based indexing, or we can maintain vector of size of queue, and decide with the help of flag if to insert from the beginning or the end.
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            
            vector<int> level(size);
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front -> right) q.push(front -> right);
                if(front -> left) q.push(front -> left); 
                
                int index = lvl & 1 ? i : size - i - 1;
                level[index] = front -> val;
            }
            lvl++;
            ans.push_back(level);
        }
        return ans;
    }
};