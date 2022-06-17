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
        /*
        // Create a seperate linked list with the reversed nodes, make the curr node of the original linked list the head of the reversed ll.
        
        ListNode *rhead = NULL;
        ListNode *temp = head;
        
        while(temp) {
            ListNode *t = new ListNode(temp -> val, rhead);
            rhead = t;
            temp = temp -> next;
        }
        return rhead;
        */
        
        
        ListNode *temp = head, *prev = NULL;
        while(temp) {
            ListNode *t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
};