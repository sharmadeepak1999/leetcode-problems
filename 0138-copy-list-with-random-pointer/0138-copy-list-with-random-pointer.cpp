/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        Node* temp = head;
        
        while(temp) {
            mp[temp] = temp -> random;
            temp = temp -> next;
        }
        
        unordered_map<Node*, Node*> oldNewMap;
        
        temp = head;
        Node* dummy = new Node(0);
        Node* temp2 = dummy;
        while(temp) {
            temp2 = temp2 -> next = new Node(temp -> val);
            oldNewMap[temp] = temp2;
            temp = temp -> next;
        }
        
        temp2 = dummy -> next;
        temp = head;
        while(temp) {
            temp2 -> random = oldNewMap[mp[temp]];
            temp2 = temp2 -> next;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};