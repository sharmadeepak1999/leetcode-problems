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
    /*
    ListNode* deleteDuplicates(ListNode* head) {
        // We will keep a prev pointer, if the value of prev pointer equals to the current pointer, then we update the prev next to curr next, and delete the curr, if they are not equal then we put prev as curr, and curr as curr next.
        
        ListNode *curr = head, *prev = NULL;
        
        while(curr) {
            if(prev && curr -> val == prev -> val) {
                prev -> next = curr -> next;
                delete curr;
                curr = prev -> next;
            } else {
                prev = curr;
                curr = curr -> next;   
            }
        }
        return head;
    }
    */
    
    
    ListNode* helper(ListNode* head) {
        if(!head) return NULL;
        ListNode* res = helper(head -> next);
        
        if(res && res -> val == head -> val) return res;
        else {
            head -> next = res;
            return head;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {        
        return helper(head);
    }
};