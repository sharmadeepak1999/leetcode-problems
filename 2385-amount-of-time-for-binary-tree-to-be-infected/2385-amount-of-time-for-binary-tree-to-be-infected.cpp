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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node -> left) {
                    q.push(node -> left);
                    adj[node -> val].push_back(node -> left -> val);
                    adj[node -> left -> val].push_back(node -> val);
                }
                if(node -> right) {
                    q.push(node -> right);
                    adj[node -> val].push_back(node -> right -> val);
                    adj[node -> right -> val].push_back(node -> val);
                }
            }
        }
        
        queue<int> list;
        list.push(start);
        int minutes = -1;
        
        unordered_map<int, bool> visited;
        visited[start] = true;
        while(!list.empty()) {
            minutes++;
            int size = list.size();
            for(int i = 0; i < size; i++) {
                int node = list.front();
                list.pop();
                
                for(auto &adjNode:adj[node]) {
                    if(visited.find(adjNode) == visited.end()) {
                        list.push(adjNode);
                        visited[adjNode] = true;
                    }
                }
                
            }
        }
        return minutes;
    }
};