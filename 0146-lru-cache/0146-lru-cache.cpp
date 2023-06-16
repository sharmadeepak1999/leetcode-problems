struct Node {
    Node *next, *prev;
    int key, value;
    
    Node(int key, int value) {
        this -> key = key;
        this -> value = value;
        next = prev = NULL;
    }
};
class LRUCache {
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int capacity;
    
    void deleteLRU() {
        if(tail -> prev == head) return;
        Node *temp = tail -> prev;
        tail -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        mp.erase(temp -> key);
        delete temp;
    }
    void deleteKey(int key) {
        Node *temp = mp[key];
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        delete temp;
    }
    void insertAtHead(int key, int value) {
        Node *temp = head -> next;
        Node* newNode = new Node(key, value);
        head -> next = newNode;
        newNode -> prev = head;
        newNode -> next = temp;
        temp -> prev = newNode;
        mp[key] = newNode;
    }
    int getValue(int key) {
        if(mp.find(key) == mp.end()) return -1;
        return mp[key] -> value;
    }
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        int value = getValue(key);
        if(value == -1) return -1;
        deleteKey(key);
        insertAtHead(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(mp.size() == capacity) {
                deleteLRU();
            }
        } else {
            deleteKey(key);
        }
        
        insertAtHead(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */