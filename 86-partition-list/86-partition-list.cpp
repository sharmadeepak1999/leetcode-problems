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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(), *right = new ListNode();
        
        ListNode *ltail = left, *rtail = right;
        
        ListNode *temp = head;
        
        while(temp) {
            if(temp -> val < x) {
                ltail -> next = temp;
                ltail = ltail -> next;
            } else {
                rtail -> next = temp;
                rtail = rtail -> next;
            }
            temp = temp -> next;
        }
        
        ltail -> next = right -> next;
        rtail -> next = NULL;
        return left -> next;
    }
};