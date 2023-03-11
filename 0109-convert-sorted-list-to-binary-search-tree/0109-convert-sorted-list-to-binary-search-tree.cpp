/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> arr;
public:
    TreeNode* helper(int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        
        TreeNode* newNode = new TreeNode(arr[mid]);
        newNode -> left = helper(start, mid - 1);
        newNode -> right = helper(mid + 1, end);
        return newNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        
        return helper(0, arr.size() - 1);
    }
};