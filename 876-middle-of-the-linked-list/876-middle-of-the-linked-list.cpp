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
    ListNode* middleNode(ListNode* head) {
        /*
        // Naive method is to traverse through the linked list and determine it size, then find the middle of linked list, and then again travel the ll this time counting the node visited, as it beccomes equal to the middle, break, and return
        int size = 0;
        
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp -> next;
        }
        
        int mid = size / 2;
        
        temp = head;
        
        while(mid) {
            temp = temp -> next;
            mid--;
        };
        return temp;
        */
        
        ListNode *slow = head, *fast = head;
        
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }
        return slow;
    }
};