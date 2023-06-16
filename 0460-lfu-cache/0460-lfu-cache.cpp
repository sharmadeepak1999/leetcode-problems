struct Node {
    Node *prev, *next;
    int key, value, freq;
    Node(int key, int value, int freq) {
        prev = next = NULL;
        this -> key = key;
        this -> value = value;
        this -> freq = freq;
    }
};

class LRU {
    Node *head, *tail;
    public: 
    LRU() {
        head = new Node(0, 0, 0);
        tail = new Node(0, 0, 0);
        head -> next = tail;
        tail -> prev = head;
    }
    int deleteLRU() {
        Node *temp = tail -> prev;
        tail -> prev = temp -> prev;
        temp -> prev -> next = tail;
        int key = temp -> key;
        delete temp;
        return key;
    }
    Node* put(int key, int value, int freq) {
        Node *temp = head -> next;
        Node *newNode = new Node(key, value, freq);
        head -> next = newNode;
        newNode -> prev = head;
        newNode -> next = temp;
        temp -> prev = newNode;
        return newNode;
    }
    bool isEmpty() {
        return head -> next == tail;
    }
};

class LFUCache {
    unordered_map<int, LRU*> freqMp;
    unordered_map<int, Node*> nodeMp;
    int capacity;
    int leastFreq;
    void deleteLFU() {
        int key = freqMp[leastFreq] -> deleteLRU();
        nodeMp.erase(key);
        if(freqMp[leastFreq] -> isEmpty()) {
            leastFreq++;
        }
    }
    void insert(int key, int value, int freq) {
        if(freqMp.find(freq) == freqMp.end()) {
            freqMp[freq] = new LRU();
        }
        leastFreq = min(leastFreq, freq);
        Node* newNode = freqMp[freq] -> put(key, value, freq);
        nodeMp[key] = newNode;
    }
    void deleteKey(int key) {
        Node* oldNode = nodeMp[key];
        Node* temp = oldNode -> prev;
        temp -> next = oldNode -> next;
        oldNode -> next -> prev = temp;
        int oldFreq = oldNode -> freq;
        nodeMp.erase(key);
        delete oldNode;
        if(freqMp[leastFreq] -> isEmpty()) {
            leastFreq++;
        }
    }
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        leastFreq = 1;
    }
    
    int get(int key) {
        if(nodeMp.find(key) == nodeMp.end()) return -1;
        int value = nodeMp[key] -> value;
        
        cout << "HERE 2" << endl;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(nodeMp.find(key) == nodeMp.end()) {
            if(nodeMp.size() == capacity) {
                deleteLFU();
            }
            insert(key, value, 1);
        } else {
            int freq = nodeMp[key] -> freq;
            deleteKey(key);
            insert(key, value, freq + 1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */