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
        ListNode *temp = new ListNode();
        ListNode *newHead = temp;
        int carry = 0;
        
        while(l1 && l2) {
            temp = temp -> next = new ListNode();
            int sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            temp -> val = sum;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1) {
            temp = temp -> next = new ListNode();
            int sum = l1 -> val + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            temp -> val = sum;
            l1 = l1 -> next;
        }
        
        while(l2) {
            temp = temp -> next = new ListNode();
            int sum = l2 -> val + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            temp -> val = sum;
            l2 = l2 -> next;
        }
        
        if(carry) {
            temp = temp -> next = new ListNode(carry);
        }
        
        return newHead -> next;
    }
};