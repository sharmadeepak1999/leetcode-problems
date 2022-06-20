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
    ListNode* deleteDuplicates(ListNode* head) {
        // We will check if the next node and the next to next node has value same, then we will run a loop and skip all those elements, and once the loop is complete we will make the current next pointer to point to the next of the next node that would contain the node that is not equal to the next node. we will only move the temp node when the we don't find a duplicate for that we will keep a variable, also we will take use of dummy node to avoid checking for edge cases like deleting node from the beginning of the ll.
        // We can also do this with a previous node method.
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* temp = dummy;
        while(temp && temp -> next && temp -> next -> next) {
            ListNode* t = temp -> next;
            bool duplicate = false;
            while(t && t -> next && t -> val == t -> next -> val) {
                duplicate = true;
                t -> next = t -> next -> next;
            }
            if(duplicate) temp -> next = t -> next;
            else temp = temp -> next;
        }
        
        return dummy -> next;
    }
};