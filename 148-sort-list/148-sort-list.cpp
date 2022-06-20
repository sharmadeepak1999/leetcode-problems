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
    ListNode* middleLL(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        // A naive approach would be to use an array and store the ll nodes values in it and sort the array and traverse the ll and replace each node value with sequential value from the sorted array.
        
        // A better approach would be to use merge sort, by splitting the ll into two halves using the middle of the ll, and calling the merge sort on two halves, and then merging the returned sorted halves into single list.
        if(head == NULL || head -> next == NULL) return head;
        ListNode* mid = middleLL(head);
        ListNode* t = mid -> next;
        mid -> next = NULL;
        ListNode* l = sortList(head);
        ListNode* r = sortList(t);
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        
        while(l && r) {
            temp -> next = new ListNode();
            temp = temp -> next;
            if(l -> val < r -> val) {
                temp -> val = l -> val;
                l = l -> next;
            } else {
                temp -> val = r -> val;
                r = r -> next;
            }
        }
        if(l) {
            temp -> next = l;
        }
        
        if(r) {
            temp -> next = r;
        }
        
        return newHead -> next;
    }
};