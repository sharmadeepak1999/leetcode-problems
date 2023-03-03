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
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = head;
        while(next) {
            curr = next;
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
        }
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int l = 0;
        ListNode *temp = head;
        
        while(temp) {
            temp = temp -> next;
            l++;
        }
        k = k % l;
        ListNode* first = head;
        temp = head;
        // cout << l << ' ' << k;
        for(int i = 1; i < l - k; i++) {
            temp = temp -> next;
        }
        ListNode* second = temp -> next;
        temp -> next = NULL;
        first = reverseLL(first);
        second = reverseLL(second);
        
        temp = first;
        
        while(temp -> next) {
            temp = temp -> next;
        }
        
        temp -> next = second;
        first = reverseLL(first);
        return first;
    }
};