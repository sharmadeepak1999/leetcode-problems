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
    /*
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        
        while(l1 && l2) {
            temp -> next = new ListNode();
            temp = temp -> next;
            
            if(l1 -> val < l2 -> val) {
                temp -> val = l1 -> val;
                l1 = l1 -> next;
            } else {
                temp -> val = l2 -> val;
                l2 = l2 -> next;
            }
        }
        
        if(l1) {
            temp -> next = l1;
        }
        
        if(l2) {
            temp -> next = l2;
        }
        
        return newHead -> next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // We can merge two lists at a time, and insert the result list back to the vector, we will do this as long as we don't have only 1 list left. this will give TLE.
        
        if(lists.empty()) return NULL; 
        while(lists.size() > 1) {
            ListNode *l1 = lists.back();
            lists.pop_back();
            ListNode *l2 = lists.back();
            lists.pop_back();
            ListNode *l = mergeTwoList(l1, l2);
            lists.push_back(l);
        }
        return lists.back();
    }
    
    */
    
    
    
    
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        
        while(l1 && l2) {
            temp -> next = new ListNode();
            temp = temp -> next;
            
            if(l1 -> val < l2 -> val) {
                temp -> val = l1 -> val;
                l1 = l1 -> next;
            } else {
                temp -> val = l2 -> val;
                l2 = l2 -> next;
            }
        }
        
        if(l1) {
            temp -> next = l1;
        }
        
        if(l2) {
            temp -> next = l2;
        }
        
        return newHead -> next;
    }
    
    ListNode* merge(vector<ListNode*>& lists, int s, int e) {
        if(lists.empty() || s > e) return NULL;
        if(s == e) return lists[s];
        int mid = (s + e) / 2;
        
        ListNode* l1 = merge(lists, s, mid);
        ListNode* l2 = merge(lists, mid + 1, e);
        return mergeTwoList(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};