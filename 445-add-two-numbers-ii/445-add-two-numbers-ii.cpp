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
        // We can reverse the linked list and then start adding them from the start and have a carry that would be added to the next node pair, same as what we did in the part 1 of this question.
        
        stack<int> s1, s2;
        
        ListNode* temp = l1;
        while(temp) {
            s1.push(temp -> val);
            temp = temp -> next;
        }
        
        temp = l2;
        while(temp) {
            s2.push(temp -> val);
            temp = temp -> next;
        }
        
        int carry = 0;
        ListNode* l = NULL;
        while(!s1.empty() || !s2.empty() || carry) {
            int n1 = 0, n2 = 0;
            
            if(!s1.empty()) {
                n1 = s1.top();
                s1.pop();
            }
            
            if(!s2.empty()) {
                n2 = s2.top();
                s2.pop();
            }
            
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            ListNode* t = new ListNode(sum % 10);
            t -> next = l;
            l = t;
        }
        return l;
    }
};