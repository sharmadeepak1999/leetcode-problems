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
    /*
    void preorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        ans.push_back(root -> val);
        preorder(root -> left, ans);
        preorder(root -> right, ans);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // recursive
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    */
    
    vector<int> preorderTraversal(TreeNode* root) {
        //iterative
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            
            //
            if(top -> right) s.push(top -> right);
            if(top -> left) s.push(top -> left);

            ans.push_back(top -> val);
        }
        return ans;
    }
};