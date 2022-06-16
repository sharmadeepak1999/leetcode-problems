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
    ListNode* removeElements(ListNode* head, int val) {
        /*
        
        // We can use recursion, we can recursion for the rest ll, and check if the head val is equal to the val to remove, if yes then only return the new head from the recursion, and delete the head, if not equal the link the new head from the curr head next, and return curr head.
        
        if(head == NULL) return NULL;
        
        ListNode* newHead = removeElements(head -> next, val);
        
        if(head -> val == val) {
            delete head;
            return newHead;
        }
        else {
            head -> next = newHead;
            return head;
        }
        */
        
        ListNode *temp = head; 
        
        while(temp && temp -> next) {
            if(temp -> next -> val == val) {
                ListNode *t = temp -> next;
                temp -> next = temp -> next -> next;
                delete t;
            } else {
                temp = temp -> next;
            }
        }
        
        if(head && head -> val == val) {
            ListNode *t = head;
            head = head -> next;
            delete t;
        }
        return head;
    }
};