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
    ListNode* middleLL(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode *mid = middleLL(head);
        ListNode *l = head;
        ListNode *r = mid -> next;
        mid -> next = NULL;
        l = sortList(l);
        r = sortList(r);
        
        ListNode *temp = new ListNode();
        ListNode *ans = temp;
        while(l && r) {
            temp = temp -> next = new ListNode();
            
            if(l -> val < r -> val) {
                temp -> val = l -> val;
                l = l -> next;
            } else {
                temp -> val = r -> val;
                r = r -> next;
            }
        }
        
        if(l) temp -> next = l;
        if(r) temp -> next = r;
        
        return ans -> next;
    }
};