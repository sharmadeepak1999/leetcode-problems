/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &adj) {
        if(root == NULL) return;
        
        if(root -> left) {
            adj[root].push_back(root -> left);
            adj[root -> left].push_back(root);
            dfs(root -> left, adj);
        }
        if(root -> right) {
            adj[root].push_back(root -> right);
            adj[root -> right].push_back(root);
            dfs(root -> right, adj);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        dfs(root, adj);
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while(!q.empty()) {
            if(level > k) return ans;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(level == k) ans.push_back(node -> val);
                for(auto &adjNode:adj[node]) {
                    if(visited.find(adjNode) == visited.end()) {
                        visited.insert(adjNode);
                        q.push(adjNode);
                    }
                }
            }
            level++;
        }
        return ans;
    }
};