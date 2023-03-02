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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        bool found = false;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast) {
                found = true;
                break;
            }
        }
        if(found) {
            slow = head;
            
            while(slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
        return NULL;
    }
};