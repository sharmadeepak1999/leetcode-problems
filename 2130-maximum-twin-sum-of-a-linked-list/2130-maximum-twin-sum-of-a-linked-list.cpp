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
class Solution {
    void helper(ListNode*&front, ListNode* back, int &maxi) {
        if(back == NULL) return;
        
        helper(front, back -> next, maxi);
        maxi = max(maxi, front -> val + back -> val);
        front = front -> next;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* front = head;
        ListNode* back = head;
        int maxi = 0;
        helper(front, back, maxi);
        return maxi;
    }
};