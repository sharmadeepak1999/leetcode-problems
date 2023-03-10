/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> mp;
public:
    Solution(ListNode* head) {
        ListNode *temp = head;
        while(temp) {
            mp.push_back(temp -> val);
            temp = temp -> next;
        }
    }
    
    int getRandom() {
        const int range_from  = 0;
        const int range_to = mp.size() - 1;
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int> distr(range_from, range_to);
        return mp[distr(generator)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */