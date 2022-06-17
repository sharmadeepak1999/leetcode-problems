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
        ListNode *slow = head, *fast = head;
        
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    
    ListNode* reverseLL(ListNode* head) {
        ListNode *temp = head, *prev = NULL;
        
        while(temp) {
            ListNode *t = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        /*
        // Use a vector or array to store all the elements of the linked list, then use the two pointer approach to check if the left element and right element is equal then continue, or return false.
        
        vector<int> arr;
        
        ListNode *temp = head;
        
        while(temp) {
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        
        int l = 0, r = arr.size() - 1;
        
        while(l < r) {
            if(arr[l++] != arr[r--]) return false;
        }
        return true;
        */
        
        
        ListNode *mid = middleLL(head);
        mid -> next = reverseLL(mid -> next);
        
        ListNode *temp = head, *temp2 = mid -> next;
        
        while(temp2) {
            if(temp2 -> val != temp -> val) return false;
            temp2 = temp2 -> next;
            temp = temp -> next;
        }
        return true;
    }
};