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
        /*
        // We can use a hashmap to store the nodes of the first ll, and then traverse the second ll, and check if any of its node is present in the hashmap, if yes then return that node.
        
        unordered_set<ListNode*> s;
        
        ListNode* temp = headA;
        
        while(temp) {
            s.insert(temp);
            temp = temp -> next;
        }
        
        temp = headB;
        
        while(temp && s.find(temp) == s.end()) temp = temp -> next;
        
        return temp;
        */
        
        

        /*
        // Since the length of the linked list after the intersection point are same for both, so we can find the lenght of both linked list, and move the pointer of the larger linked list such that it is at the same distance from the intersection point as the smaller ll, this can be done by moving the larger linked list pointer by the difference betweeen the length of both linked list, after that we will starting traversing both the ll simultaneously, and when both the pointer becomes equal, that is the interection point.
        
        int l1 = 0, l2 = 0;
        
        ListNode *tempA = headA, *tempB = headB;
        while(tempA || tempB) {
            if(tempA) {
                l1++;
                tempA = tempA -> next;
            }
            if(tempB) {
                l2++;
                tempB = tempB -> next;
            }
        }
        
        tempA = headA;
        tempB = headB;
        if(l1 > l2) {
            for(int i = 1; i <= l1 - l2; i++) tempA = tempA -> next;
        } else if(l2 > l1) {
            for(int i = 1; i <= l2 - l1; i++) tempB = tempB -> next;
        }
        
        while(tempA && tempB && tempA != tempB) {
            tempA = tempA -> next;
            tempB = tempB -> next;
        }
        return tempA;
        */
        
        
        ListNode* tempA = headA, *tempB = headB;
        
        while(tempA != tempB) {
            tempA = tempA == NULL ? headB : tempA -> next;
            tempB = tempB == NULL ? headA : tempB -> next;
        }
        return tempA;
    }
};