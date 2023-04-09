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
    void recoverTree(TreeNode* root) {
        TreeNode* prev, *middle, *last;
        prev = middle = last = NULL;
        
        TreeNode* curr = root, *before = NULL;
        
        while(curr) {
            if(!curr -> left) {
                if(before && before -> val > curr -> val) {
                    if(prev) {
                        last = curr;
                    } else {
                        prev = before;
                        middle = curr;
                    }
                } else before = curr;
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                while(temp -> right && temp -> right != curr) temp = temp -> right;
                
                if(temp -> right) {
                    temp -> right = NULL;
                    if(before && before -> val > curr -> val) {
                        if(prev) {
                            last = curr;
                        } else {
                            prev = before;
                            middle = curr;
                        }
                    } else before = curr;
                    curr = curr -> right;
                } else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        
        if(last == NULL) {
            int temp = prev -> val;
            prev -> val = middle -> val;
            middle -> val = temp;
        } else {
            int temp = prev -> val;
            prev -> val = last -> val;
            last -> val = temp;
        }
    }
};