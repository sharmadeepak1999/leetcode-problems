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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newHead = new ListNode();
        ListNode *temp = newHead;
        while(list1 && list2) {
            temp -> next = new ListNode();
            temp = temp -> next;
            if(list1 -> val > list2 -> val) {
                temp -> val = list2 -> val;
                list2 = list2 -> next;
            } else {
                temp -> val = list1 -> val;
                list1 = list1 -> next;
            }
        }
        
        while(list1) {
            temp -> next = new ListNode();
            temp = temp -> next;
            temp -> val = list1 -> val;
            list1 = list1 -> next;
        }
        
        while(list2) {
            
            temp -> next = new ListNode();
            temp = temp -> next;
            temp -> val = list2 -> val;
            list2 = list2 -> next;
        }
        return newHead -> next;
    }
};