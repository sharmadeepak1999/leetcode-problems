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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        
        ListNode* temp = head;
        
        while(temp) {
            ListNode* t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* temp = head, *prev = dummy;
        int c = 0;
        while(temp) {
            if(c == k - 1) {
                ListNode *t1 = temp -> next;
                ListNode *t2 = prev -> next;
                temp -> next = NULL;
                prev -> next = reverseLL(prev -> next);
                prev = t2;
                t2 -> next = t1;
                temp = t1;
                c = 0;
            } else {
                c++;
                temp = temp -> next;
            }
        }
        return dummy -> next;
    }
};