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
        ListNode *temp1 = l1, *temp2 = l2, *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while(temp1 || temp2) {
            temp = temp -> next = new ListNode();
            int a = 0, b = 0;
            
            if(temp1) {
                a = temp1 -> val;
                temp1 = temp1 -> next;
            }
            if(temp2) {
                b = temp2 -> val;
                temp2 = temp2 -> next;
            }
            
            int sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp -> val = sum;
        }
        if(carry) temp -> next = new ListNode(1);
        return dummy -> next;
    }
};