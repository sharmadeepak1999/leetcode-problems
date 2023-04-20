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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        
        q.push({ root, 0 });
        int maxi = 0;
        while(!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first = -1, last = -1;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int j = q.front().second - mini;
                q.pop();
                if(i == 0) first = j;
                if(i == size - 1) last = j;
                if(node -> left) q.push({ node -> left, (long long) 2 * j });
                if(node -> right) q.push({ node -> right, (long long) 2 * j + 1 });
            }
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};