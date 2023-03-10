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
    ListNode *temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    int getRandom() {
        ListNode *curr = temp;
        
        int res = 0; int n = 1;
        
        while(curr) {
            if(rand() % n == 0) res = curr -> val;
            n++;
            curr = curr -> next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */