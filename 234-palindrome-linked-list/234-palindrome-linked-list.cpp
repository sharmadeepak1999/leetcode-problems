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
    bool isPalindrome(ListNode* head) {
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
    }
};