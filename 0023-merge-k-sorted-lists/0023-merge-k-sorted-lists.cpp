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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *newHead = new ListNode();
        ListNode *temp = newHead;
        while(1) {
            bool f = false;
            int k = lists.size();
            int i = 0;
            int mini = INT_MAX;
            int idx = -1;
            while(i < k) {
                if(lists[i] && lists[i] -> val < mini) {
                    f = true;
                    mini = lists[i] -> val;
                    idx = i;
                }
                i++;
            }
            if(f) {
                i = 0;
                temp = temp -> next = new ListNode(mini);
                lists[idx] = lists[idx] -> next;
            }
            else break;
        }
        return newHead -> next;
    }
};