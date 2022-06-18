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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        
        ListNode *l = NULL, *r = NULL, *ul = NULL, *ur = NULL, *prev = NULL;
        int i = 1;
        while(!l || !r) {
            if(i == left) {
                l = temp;
                ul = prev;
            }
            if(i == right) {
                r = temp;
                ur = temp -> next;
            }
            i++;
            prev = temp;
            temp = temp -> next;
        }
        
        temp = l;
        prev = NULL;
        while(temp) {
            ListNode *t = temp -> next;
            temp -> next = prev;
            prev = temp;
            if(temp == r) break;
            temp = t;
        }
        
        if(ul) ul -> next = r;
        else head = r;
        l -> next = ur;
        return head;
    }
};