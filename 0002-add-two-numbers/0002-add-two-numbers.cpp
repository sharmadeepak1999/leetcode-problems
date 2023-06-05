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
        int carry = 0;
        
        ListNode* dummy = new ListNode();
        ListNode *temp1 = l1, *temp2 = l2, *temp = dummy;
        
        while(temp1 || temp2) {
            int sum = carry;
            if(temp1) {
                sum += temp1 -> val;
                temp1 = temp1 -> next;
            }
            if(temp2) {
                sum += temp2 -> val;
                temp2 = temp2 -> next;
            }
            temp = temp -> next = new ListNode();
            temp -> val = sum % 10;
            carry = sum / 10;
        }
        
        if(carry) temp -> next = new ListNode(carry);
        return dummy -> next;
    }
};