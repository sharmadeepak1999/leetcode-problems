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
        ListNode *dummy = new ListNode();
        dummy -> next = head;
        
        ListNode *temp = dummy;
        
        for(int i = 1; i <= n; i++) {
            temp = temp -> next;
        }
        
        ListNode *temp2 = temp;
        ListNode *temp3 = dummy;
        while(temp2 && temp2 -> next) {
            temp2 = temp2 -> next;
            temp3 = temp3 -> next;
        }
        if(temp3 -> next) {
            temp3 -> next = temp3 -> next -> next;
        }
        return dummy -> next;
    }
};