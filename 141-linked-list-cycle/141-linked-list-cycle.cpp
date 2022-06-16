/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        // Naive method, We will use a hashmap to store all visited nodes, if we find any node address, already stored in the hashmap, this means that we already have traversed this node, so there is a cycle so we return true, else at last we return false.
        unordered_map<ListNode*, bool> m;
        
        ListNode* temp = head;
        
        
        while(temp) {
            if(m.find(temp) != m.end()) return true;
            m[temp] = true;
            temp = temp -> next;
        }
        return false;
        */
        
        
        // A cool approach, would be to use a slow and fast pointer, the intiution is that if there exists a cycle then, the slow and fast pointer is bound to meet, we move slow by 1 step, and fast by two step. 
        
        ListNode *slow = head, *fast = head;
        
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        
        return false;
    }
};