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
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 1 });
        long long maxWidth = 0;
        while(!q.empty()) {
            int size = q.size();
            long long base, first, last;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();
                if(i == 0) base = index * 2, first = index;
                if(i == size - 1) last = index;
                if(node -> left) {
                    q.push({ node -> left, (2 * index) - base + 1});
                }
                if(node -> right) {
                    q.push({ node -> right, (2 * index + 1) - base + 1});
                }
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};