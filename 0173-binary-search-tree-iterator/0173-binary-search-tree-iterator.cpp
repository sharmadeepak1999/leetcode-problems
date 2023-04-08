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
class BSTIterator {
    stack<TreeNode*> st;
    void insertLeftNodes(stack<TreeNode*> &st, TreeNode* root) {
        while(root) {
            st.push(root);
            root = root -> left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        insertLeftNodes(st, root);
    }
    
    int next() {
        TreeNode* nxt = st.top();
        st.pop();
        
        if(nxt -> right) insertLeftNodes(st, nxt -> right);
        return nxt -> val;
    }
    
    bool hasNext() {
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */