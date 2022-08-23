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
    bool helper(ListNode *head, ListNode *&left) {
        if(head == NULL) return true;
        
        bool res = helper(head -> next, left);
        if(!res || head -> val != left -> val) return false;
        left = left -> next;
        return res;
    }
    bool isPalindrome(ListNode* head) {
        return helper(head, head);
    }
};