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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp -> next;
        }
        int nb = len - n + 1;
        ListNode* newHead = new ListNode();
        newHead -> next = head;
        temp = newHead;
        
        int i = 1;
        while(i < nb) {
            temp = temp -> next;
            i++;
        }
        ListNode* t = temp -> next;
        temp -> next = temp -> next -> next;
        delete t;
        return newHead -> next;
    }
};