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