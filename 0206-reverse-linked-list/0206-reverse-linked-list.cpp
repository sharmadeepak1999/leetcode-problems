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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* it = head;
        while(it) {
            ListNode* temp = it -> next;
            it -> next = prev;
            prev = it;
            it = temp;
        }
        return prev;
    }
};