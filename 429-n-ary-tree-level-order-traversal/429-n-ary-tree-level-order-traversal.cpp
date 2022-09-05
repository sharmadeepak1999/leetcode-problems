/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(q.size()) {
            int size = q.size();
            vector<int> temp;
            
            for(int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                for(auto &c:front -> children) {
                    q.push(c);
                }
                temp.push_back(front->val);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};