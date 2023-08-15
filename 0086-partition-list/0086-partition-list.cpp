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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode();
        ListNode* p2 = new ListNode();
        ListNode* temp = head, *t1 = p1, *t2 = p2;
        
        while(temp) {
            if(temp -> val < x) {
                t1 = t1 -> next = new ListNode(temp -> val);
            } else t2 = t2 -> next = new ListNode(temp -> val);
            temp = temp -> next;
        }
        t1 -> next = p2 -> next;
        return p1 -> next;
    }
};