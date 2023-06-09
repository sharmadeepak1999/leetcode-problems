class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, h = letters.size() - 1;
        char res = letters[0];
        while(l <= h) {
            int mid = (l + h) / 2;
            
            if(letters[mid] <= target) l = mid + 1;
            else if(letters[mid] > target) {
                res = letters[mid];
                h = mid - 1;
            }
        }
        return res;
    }
};