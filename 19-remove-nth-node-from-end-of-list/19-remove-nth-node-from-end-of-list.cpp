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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        // Find the length of the ll, and then get to the node just before the node to delete, and modify the links accordingly, to handle edge cases create a dummy node, and start traversal from it.
        int len = 0;
        
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp -> next;
        }
        int nb = len - n + 1;
        ListNode* newHead = new ListNode();
        newHead -> next = head;
        temp = newHead;
        
        int i = 1;
        while(i < nb) {
            temp = temp -> next;
            i++;
        }
        ListNode* t = temp -> next;
        temp -> next = temp -> next -> next;
        delete t;
        return newHead -> next;
        */
        
        ListNode* newHead = new ListNode();
        newHead -> next = head;

        ListNode* slow = newHead, *fast = newHead;
        
        int i = 0; 
        
        while(i <= n) {
            fast = fast -> next;
            i++;
        }
        
        while(fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        ListNode* t = slow -> next;
        slow -> next = slow -> next -> next;
        delete t;
        return newHead -> next;
        
    }
};