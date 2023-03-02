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
    ListNode* helper(ListNode* head, int n, int& i) {
        if(head == NULL) return NULL;
        ListNode *node = helper(head -> next, n, i);
        if(i == n) {
            head -> next = node -> next;
        }
        i++;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        int i = 0;
        helper(dummy, n, i);
        return dummy -> next;
    }
};