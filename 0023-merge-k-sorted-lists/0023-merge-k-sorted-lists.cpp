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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(!left) return right;
        if(!right) return left;
        
        ListNode* temp1 = left;
        ListNode* temp2 = right;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(temp1 && temp2) {
            temp = temp -> next = new ListNode();
            if(temp1 -> val <= temp2 -> val) {
                temp -> val = temp1 -> val;
                temp1 = temp1 -> next;
            } else {
                temp -> val = temp2 -> val;
                temp2 = temp2 -> next;
            }
        }
        if(temp1) temp -> next = temp1;
        if(temp2) temp -> next = temp2;

        return dummy -> next;
    }
    ListNode* merge(vector<ListNode*> &lists, int s, int e) {
        if(lists.empty() || s > e) return NULL;
        if(e == s) return lists[s];
        int mid = (s + e) / 2;
        
        ListNode* left = merge(lists, s, mid);
        ListNode* right = merge(lists, mid + 1, e);
        
        return mergeTwoLists(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};