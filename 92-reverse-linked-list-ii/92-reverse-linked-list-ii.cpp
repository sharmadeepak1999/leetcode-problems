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
    /*
        // We can traverse the linked list and store the left and right pointers in seperate variables, also we will store the reference to the left of left pointer, and right of right pointer, now we will reverse the list from left to right pointer as standard algo, after that we will link the reversed list to the main list with the help of the pointers stored of extremes stored.
        
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
    */
    
        ListNode *temp = head, *ul = NULL, *prev = NULL, *l = NULL;
        int i = 1;
        while(temp && i <= right) {
            while(i < left) {
                ul = temp;
                temp = temp -> next;
                i++;
            }
            if(i == left) l = temp;
            while(i >= left && i <= right) {
                ListNode *t = temp -> next;
                temp -> next = prev;
                prev = temp;
                temp = t;
                i++;
            }
        }
        
        if(ul) ul -> next = prev;
        else head = prev;
        
        l -> next = temp;
        return head;
    }
};