struct Node{
    Node *links[2];
    
    bool containsKey(int bit) {
        return links[bit];
    }
    void put(Node *node, int bit) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};
class Trie {
    Node *root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node *temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!temp -> containsKey(bit)) {
                Node *node = new Node();
                temp -> put(node, bit);
            }
            temp = temp -> get(bit);
        }
    }
    int findXor(int num) {
        int xori = 0;
        Node* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(temp -> containsKey(!bit)) {
                temp = temp -> get(!bit);
                xori = xori | (1 << i);
            } else temp = temp -> get(bit);
        }
        return xori;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &num:nums) {
            trie.insert(num);
        }
        int maxXor = 0;
        for(auto &num:nums) {
            int xori = trie.findXor(num);
            if(xori > maxXor) maxXor = xori;
        }
        return maxXor;
    }
};