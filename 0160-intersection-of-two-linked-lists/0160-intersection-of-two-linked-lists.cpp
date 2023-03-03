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
        // Make use of the difference of the length of the lls before intersection
        ListNode *tempA = headA, *tempB = headB;
        
        while(tempA != tempB) {
            tempA = tempA == NULL ? headB : tempA -> next;
            tempB = tempB == NULL ? headA : tempB -> next;
        }
        return tempA;
    }
};