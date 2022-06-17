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
        /*
        // We can use similar logic to merge sort function, but here we need to create a dummy node, to have a generic function. this will use a new external linked list.
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
        */
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        while(list1 && list2) {
            if(list1 -> val > list2 -> val) {
                ListNode *t1 = temp -> next;
                temp -> next = list2;
                ListNode *t2 = list2;
                list2 = list2 -> next;
                t2 -> next = t1;
            } else {
                temp -> next = list1;
                list1 = list1 -> next;
            }
            temp = temp -> next;
        }
        if(list1) {
            temp -> next = list1;
        } 
        if(list2) {
            temp -> next = list2;
        }
        return newHead -> next;
    }
};