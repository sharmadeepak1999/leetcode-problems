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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front().first;
                int vertical = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                mp[vertical][level].insert(front -> val);
                
                if(front -> left) q.push({ front -> left, { vertical - 1, level + 1 }});
                if(front -> right) q.push({ front -> right, {vertical + 1, level + 1 }});
            }
        }
        vector<vector<int>> ans;
        
        for(auto &p : mp) {
            vector<int> col;
            for(auto &q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};