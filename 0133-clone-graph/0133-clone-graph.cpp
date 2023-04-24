/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    unordered_map<Node*, Node*> mp;
        
    Node* dfs(Node* node) {
        if(!node) return NULL;
        Node* newNode = new Node(node -> val);
        mp[node] = newNode;
        
        for(auto &adjNode:node -> neighbors) {
            if(mp.find(adjNode) == mp.end()) {
                newNode -> neighbors.push_back(dfs(adjNode));
            } else newNode -> neighbors.push_back(mp[adjNode]);
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node); 
    }
};