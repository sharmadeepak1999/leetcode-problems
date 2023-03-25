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
public:
    ListNode* reverseLL(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *temp = head;
        
        while(temp) {
            ListNode *t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    
    ListNode* helper(ListNode* start, ListNode *curr, int k, int i) {
        if(curr == NULL) return start;
        if(i == k) {
            ListNode *back = helper(curr -> next, curr -> next, k, 1);
            curr -> next = NULL;
            ListNode *res = reverseLL(start);
            start -> next = back;
            return res;
        }
        return helper(start, curr -> next, k, i + 1);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(head, head, k, 1);
    }
};