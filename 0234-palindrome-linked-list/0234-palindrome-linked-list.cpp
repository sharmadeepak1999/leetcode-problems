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
    bool helper(ListNode* head, ListNode *&left) {
        if(head == NULL) return true;
        bool res = helper(head -> next, left);
        if(!res) return false;
        if(head -> val == left -> val) {
            left = left -> next;
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(ListNode* head) {
        return helper(head, head);
    }
};