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
        Node* newHead = NULL, *temp2 = NULL;
        while(temp) {
            if(newHead == NULL) {
                newHead = new Node(temp -> val);
                temp2 = newHead;
            } else {
                temp2 = temp2 -> next = new Node(temp -> val);
            }
            mp[temp] = temp2;
            temp = temp -> next;
        }
        temp = head, temp2 = newHead;
        while(temp) {
            temp2 -> random = mp[temp -> random];
            temp2 = temp2 -> next;
            temp = temp -> next;
        }
        return newHead;
    }
};