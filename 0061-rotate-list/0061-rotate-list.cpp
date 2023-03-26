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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        ListNode *temp = head;
        
        int n = 0;
        
        while(temp) {
            temp = temp -> next;
            n++;
        }
        
        k %= n;
        temp = head;
        
        for(int i = 1; i < n - k; i++) {
            temp = temp -> next;
        }
        ListNode* t = reverseLL(temp -> next);
        temp -> next = NULL;
        temp = reverseLL(head);
        head -> next = t;
        return reverseLL(temp);
    }
};