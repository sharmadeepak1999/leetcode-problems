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
    void reorderList(ListNode* head) {
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
            cout << v[i] -> val << ' ' << v[j] -> val << endl;
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
    }
};