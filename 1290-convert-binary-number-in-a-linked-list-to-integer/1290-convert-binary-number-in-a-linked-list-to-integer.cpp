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
    
    // We will use recursion, we will traverse the linked list using recursion, we call the recursion for the next node, before processing the current node, this is to process the last node first, from the last node we will construct the number, using references of num, and the index or power of i or the position of each digits in the binary number.
    
    
    void helper(ListNode *head, int &num, int &i) {
        if(!head) return;
        
        helper(head -> next, num, i);
        
        num += (head -> val * pow(2, i));
        i++;
    }
    
    int getDecimalValue(ListNode* head) {
        int num = 0, i = 0;
        helper(head, num, i);
        return num;
    }
    */
    
    
    int getDecimalValue(ListNode* head) {
        // Another method could be find the length of the linked list, and then linearly traverse and compute the number by decrementing the found length, len - 1 for first node, len - 2 for the second node, so on. 
        
        // The efficient approach that would require only one pass, would be to assume that there is only one node in the ll, so we calculate the num, assuming single node, i.e, 2^0, now if we find another node then we have to multiply the num by 2, to increase the power of 2 for the previous position, so on we will calculate.
        
        int num = 0;
        
        while(head) {
            num = num * 2; // Increasing the power of two for all previous node
            num += (head -> val) * 1; // Assuming this is the last node so 2 ^ 0 = 1
            head = head -> next;
        }
        return num;
    }
};