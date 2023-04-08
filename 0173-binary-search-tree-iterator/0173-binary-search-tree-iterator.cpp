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
    vector<int> inorder;
    int i = 0;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr) {
            if(!curr -> left) {
                inorder.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                
                while(temp -> right && temp -> right != curr) temp = temp -> right;
                
                if(temp -> right) {
                    temp -> right = NULL;
                    inorder.push_back(curr -> val);
                    curr = curr -> right;
                } else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
        }
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        return i < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */