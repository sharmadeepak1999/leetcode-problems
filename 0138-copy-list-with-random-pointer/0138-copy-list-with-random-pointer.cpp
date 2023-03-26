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
        Node *temp = head;
        
        while(temp) {
            Node *t = temp -> next;
            temp -> next = new Node(temp -> val);
            temp -> next -> next = t;
            temp = temp -> next -> next;
        }
        temp = head;
        
        while(temp) {
            if(temp -> random) {
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        temp = head;
        Node *newHead = temp ? temp -> next : NULL;
        Node *temp2 = newHead;
        
        while(temp) {
            temp -> next = temp2 -> next;
            temp = temp -> next;
            if(temp) {
                temp2 -> next = temp -> next;
            }
            temp2 = temp2 -> next;
        }
        
        return newHead;
    }
};