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
        Node* itr = head;
        
        while(itr) {
            Node *copy = new Node(itr -> val);
            Node *temp = itr -> next;
            itr -> next = copy;
            copy -> next = temp;
            itr = temp;
        }
        
        itr = head;
        
        while(itr) {
            if(itr -> random != NULL) {
                itr -> next -> random = itr -> random -> next;
            }
            itr = itr -> next -> next;
        }
        
        Node *dummy = new Node(0);
        Node *temp = dummy;
        itr = head;
        while(itr) {
            temp -> next = itr -> next;
            temp = temp -> next;
            itr -> next = itr -> next -> next;
            itr = itr -> next;
        }
        return dummy -> next;
    }
};