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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* temp = dummy;
        
        while(temp && temp -> next && temp -> next -> next) {
            ListNode* u = temp -> next;
            ListNode* v = temp -> next -> next;
            
            temp -> next = v;
            u -> next = v -> next;
            v -> next = u;
            temp = u;
        }
        return dummy -> next;
    }
};