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
        // give every node an index similar to segment tree concept, and then do level order traversal, and find the max difference between the first and last node of each level. to avoid overflow, we instead of at every node finding the indexes for child nodes, we will subtract the min index value from each node at each level
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            
            int firstIndex, lastIndex;
            int minIndex = q.front().second;
            for(int i = 0; i < size; i++) {
                auto ele = q.front();
                ele.second = ele.second - minIndex;
                q.pop();
                TreeNode* node = ele.first;
                if(i == 0) firstIndex = ele.second;
                if(i == size - 1) lastIndex = ele.second;
                
                if(node -> left) q.push({node -> left, ele.second * 2 + 1});
                if(node -> right) q.push({node -> right, ele.second * 2 + 2});
            }
            
            ans = max(ans, lastIndex - firstIndex + 1);
        }
        return ans;
    }
};