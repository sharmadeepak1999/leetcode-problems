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
    void helper(ListNode *head, int &num, int &i) {
        if(!head) return;
        
        helper(head -> next, num, i);
        
        num += (head -> val * pow(2, i));
        i++;
    }
    
    int getDecimalValue(ListNode* head) {
        int num = 0, i = 0;
        helper(head, num, i);
        return num;
    }
};