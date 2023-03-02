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
    ListNode* reverseLL(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        
        while(curr) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    // 1 0 1
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        int c = 0;
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            c++;
        }
        slow -> next = reverseLL(slow -> next);
        ListNode *one = head, *two = slow -> next;

        while(two) {
            if(one -> val != two -> val) return false;
            one = one -> next;
            two = two -> next;
        }
        
        return true;
    }
};