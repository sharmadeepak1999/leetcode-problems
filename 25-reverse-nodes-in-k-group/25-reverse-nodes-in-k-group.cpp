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
    ListNode* reverse(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* prev = NULL, *temp = head;
        
        while(temp) {
            ListNode* t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0, c = 0;
        
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* temp = dummy, *ptail = dummy;
        while(temp) {
            if(c == k) {
                ListNode* t1 = temp -> next;
                temp -> next = NULL;
                ListNode* t = ptail -> next;
                ptail -> next = reverse(ptail -> next);
                t -> next = t1;
                ptail = t;
                temp = ptail;
                c = 0;
            } else {
                c++;
                temp = temp -> next;   
            }
        }
        return dummy -> next;
    }
};