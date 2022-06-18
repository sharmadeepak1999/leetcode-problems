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
        /*
        // We can create a hashmap to store the corresponding new node of old ones, we will first travel the ll, and create new ll with only next pointer, and then again travel the ll, this time handling the random pointer, using the hashmap.
        
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
        */
        
        
        Node* temp = head;
        
        while(temp) {
            Node* t = temp -> next;
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
        Node* temp2 = temp? temp -> next : NULL;
        Node* newHead = temp2;
        while(temp) {
            temp -> next = temp2 -> next;
            temp = temp -> next;
            if(temp) 
                temp2 -> next = temp -> next;
            temp2 = temp2 -> next;
        }
        return newHead;
    }
};