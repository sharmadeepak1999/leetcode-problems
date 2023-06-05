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
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev = NULL, *temp = head;
        while(temp) {
            ListNode* t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *temp1 = head, *temp2 = reverseLL(slow -> next);
        slow -> next = NULL;
        while(temp1 && temp2) {
            if(temp1 -> val != temp2 -> val) return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
};