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
    ListNode* reverseLL(ListNode* root) {
        ListNode* prev = NULL;
        ListNode* temp = root;
        
        while(temp) {
            ListNode* t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        int maxi = 0;
        while(fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseLL(slow -> next);
        
        ListNode* first = head;
        ListNode* second = slow -> next;
        
        while(second) {
            maxi = max(maxi, first -> val + second -> val);
            first = first -> next;
            second = second -> next;
        }
        return maxi;
    }
};