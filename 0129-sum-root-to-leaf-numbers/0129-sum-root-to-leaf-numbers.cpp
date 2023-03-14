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
    void sum(TreeNode* root, int curr, int &s) {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) {
            curr = curr * 10 + root -> val;
            s += curr;
            return;
        }
        curr = curr * 10 + root -> val;
        sum(root -> left, curr, s);
        sum(root -> right, curr, s);
    }
    int sumNumbers(TreeNode* root) {
        int s = 0;
        sum(root, 0, s);
        return s;
    }
};