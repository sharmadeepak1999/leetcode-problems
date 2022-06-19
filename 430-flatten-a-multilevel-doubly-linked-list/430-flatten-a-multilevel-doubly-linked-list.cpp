/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head ==  NULL) return NULL;
        
        Node* temp = head;
        
        while(temp) {
            Node *child = flatten(temp -> child);
            Node *t1 = temp -> next;
            if(child) {
                temp -> next = child;
                child -> prev = temp;
                Node *t2 = child;
                while(t2 -> next) {
                    t2 = t2 -> next;
                }
                t2 -> next = t1;
                if(t1) t1 -> prev = t2;
                
                temp -> child = NULL;
            }
            temp = t1;
        }
        return head;
    }
};