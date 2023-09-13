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
    ListNode* getMiddleLL(ListNode* head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* slow = head, *fast = head;
        
        while(fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode* mid = getMiddleLL(head);
        cout << mid -> val << endl;
        ListNode* temp = mid -> next;
        mid -> next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        
        ListNode *dummy = new ListNode();
        ListNode *t = dummy;
        while(left && right) {
            if(left -> val < right -> val) {
                t -> next = left;
                left = left -> next;
            } else {
                t -> next = right;
                right = right -> next;
            }
            t = t -> next;
        }
        
        if(left) {
            t -> next = left;
        }
        if(right) {
            t -> next = right;
        }
        return dummy -> next;
    }
};