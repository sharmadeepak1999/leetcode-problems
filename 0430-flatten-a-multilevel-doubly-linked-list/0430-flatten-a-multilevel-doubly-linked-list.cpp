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
        if(head == NULL) return head;
        
        Node *temp = head;
        
        while(temp) {
            if(temp -> child) {
                Node *t1 = flatten(temp -> child);
                Node *t2 = temp -> next;
                temp -> next = t1;
                t1 -> prev = temp;
                
                Node *t3 = t1;
                
                while(t3 -> next) t3 = t3 -> next;
                t3 -> next = t2;
                if(t2)
                    t2 -> prev = t3;
                temp -> child = NULL;
                temp = t2;
            } else temp = temp -> next;
        }
        return head;
    }
};