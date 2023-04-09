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
    vector<int> morrisInorder(TreeNode* root, vector<int>& inorder, bool compare) {
        TreeNode* curr = root;
        vector<int> res;
        int i = 0;
        while(curr) {
            if(!curr -> left) {
                if(compare) {
                    if(inorder[i] != curr -> val) curr -> val = inorder[i];
                    i++;
                } else res.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                
                while(temp -> right && temp -> right != curr) temp = temp -> right;
                
                if(temp -> right) {
                    temp -> right = NULL;
                    if(compare) {
                        if(inorder[i] != curr -> val) curr -> val = inorder[i];
                        i++;
                    } else res.push_back(curr -> val);
                    curr = curr -> right;
                } else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        return res;
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder = morrisInorder(root, inorder, false);
        
        sort(inorder.begin(), inorder.end());
        
        morrisInorder(root, inorder, true);
    }
};