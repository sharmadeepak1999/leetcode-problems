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
    ListNode* middleLL(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head, *prev = NULL;
        
        while(temp) {
            ListNode* t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
    /*
        // Store the ll nodes in a vector, and then using left and right pointer create the links also maintain the whole list using another head variable that has a dummy node in the beginning. and at last replace the dummy node with with the original head.
        
        vector<ListNode*> v;
        
        ListNode* temp = head;
        while(temp) {
            v.push_back(temp);
            temp = temp -> next;
        }
        
        int i = 0, j = v.size() - 1;
        
        ListNode* newHead = new ListNode();
        ListNode* temp2 = newHead;
        while(i < j) {
            v[i] -> next = v[j];
            temp2 -> next = v[i];
            temp2 = v[j];
            i++;
            j--;
        }
        if(v.size() & 1) {
            temp2 -> next = v[i];
            temp2 = temp2 -> next;
        }
        temp2 -> next = NULL;
        head = newHead -> next;
    */
    
        
        ListNode* mid = middleLL(head);
        
        ListNode* temp = head, *temp2 = reverseLL(mid -> next);
        mid -> next = NULL;
        while(temp2){
            ListNode* t1 = temp -> next;
            ListNode* t2 = temp2 -> next;
            temp -> next = temp2;
            temp2 -> next = t1;
            temp = t1;
            temp2 = t2;
        }
    }
};