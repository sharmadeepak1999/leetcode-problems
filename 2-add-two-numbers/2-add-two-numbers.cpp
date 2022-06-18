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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = NULL, *temp = NULL;
        
        int carry = 0; 
        while(l1 || l2 || carry) {
            if(!newHead) {
                newHead = new ListNode();
                temp = newHead;
            } else {
                temp -> next = new ListNode();
                temp = temp -> next;
            }
            int n1 = 0, n2 = 0;
            if(l1) {
                n1 = l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                n2 = l2 -> val;
                l2 = l2 -> next;
            }
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            temp -> val = sum % 10;
        }
        return newHead;
    }
};