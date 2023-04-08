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
    stack<TreeNode*> nxtStack, bfrStack;
    void pushLeftNodes(TreeNode* root) {
        for(; root != NULL; root = root -> left) nxtStack.push(root);
    }
    
    void pushRightNodes(TreeNode* root) {
        for(; root != NULL; root = root -> right) bfrStack.push(root);
    }
public:
    int next() {
        TreeNode* nxt = nxtStack.top();
        nxtStack.pop();
        
        if(nxt -> right) pushLeftNodes(nxt -> right);
        return nxt -> val;
    }
    int before() {
        TreeNode* bfr = bfrStack.top();
        bfrStack.pop();
        
        if(bfr -> left) pushRightNodes(bfr -> left);
        return bfr -> val;
    }
    bool findTarget(TreeNode* root, int k) {
        pushLeftNodes(root);
        pushRightNodes(root);
        int nxt = next();
        int bfr = before();
        while(nxt < bfr) {
            int sum = nxt + bfr;
            
            if(sum == k) return true;
            
            if(sum < k) nxt = next();
            else bfr = before();
        }
        return false;
    }
};