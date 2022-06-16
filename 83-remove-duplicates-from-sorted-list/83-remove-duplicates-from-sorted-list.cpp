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
};