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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
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
        
        int i = 0, j = inorder.size() - 1;
        
        while(i < j) {
            int sum = inorder[i] + inorder[j];
            
            if(sum == k) return 1;
            else if(sum < k) i++;
            else j--;
        }
        return 0;
    }
};