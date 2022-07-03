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
    void postorder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        postorder(root -> left, ans);
        postorder(root -> right, ans);
        ans.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    */
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        
        while(!s1.empty()) {
            TreeNode* top = s1.top();
            s1.pop();
            s2.push(top);
            if(top -> left) s1.push(top -> left);
            if(top -> right) s1.push(top -> right);
        }
        while(!s2.empty()) {
            ans.push_back(s2.top() -> val);
            s2.pop();
        }
        return ans;
    }
};