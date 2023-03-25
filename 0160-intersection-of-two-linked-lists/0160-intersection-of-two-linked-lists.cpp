/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        
        while(t1 && t2) {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        
        int l = 0;
        
        if(!t1) {
            while(t2) {
                t2 = t2 -> next;
                l++;
            }
            t1 = headA, t2 = headB;
            
            for(int i = 1; i <= l; i++) {
                t2 = t2 -> next;
            }
        } else {
            while(t1) {
                t1 = t1 -> next;
                l++;
            }
            
            t1 = headA, t2 = headB;
            
            for(int i = 1; i <= l; i++) {
                t1 = t1 -> next;
            }
        }
        
        while(t1 && t2) {
            if(t1 == t2) return t1;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return NULL;
    }
};