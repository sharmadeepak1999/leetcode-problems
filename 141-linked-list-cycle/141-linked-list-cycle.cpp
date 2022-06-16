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
        unordered_map<ListNode*, bool> m;
        
        ListNode* temp = head;
        
        
        while(temp) {
            if(m.find(temp) != m.end()) return true;
            m[temp] = true;
            temp = temp -> next;
        }
        return false;
    }
};