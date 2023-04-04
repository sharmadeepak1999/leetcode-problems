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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> pre;
        if(root == NULL) return pre;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            pre.push_back(curr -> val);
            
            if(curr -> right) st.push(curr -> right);
            if(curr -> left) st.push(curr -> left);
        }
        return pre;
    }
};