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
        unordered_map<Node*, Node*> m;
        
        Node* newHead = new Node(-1);
        Node* temp = newHead;
        Node* temp2 = head;
        while(temp2) {
            temp -> next = new Node(temp2 -> val);
            temp = temp -> next;
            m[temp2] = temp;
            temp2 = temp2 -> next;
        }
        
        temp2 = head;
        temp = newHead -> next;
        while(temp2) {
            cout << temp -> val << ' ' << temp2 -> val << endl; 
            temp -> random = m[temp2 -> random];
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        return newHead -> next;
    }
};