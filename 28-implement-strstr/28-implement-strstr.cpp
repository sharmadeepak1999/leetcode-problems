class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // We could use the brute force approach to check all poisbility, we start from the first char in the array, if it is equal to the first char in the needle, then we keep continuing, if ever it becomes unequal we break the loop, after that we check if the counter of the inner loop has become equal to the lenght of needle string that shows that all its char were found in the haystack, so return the outer loop index, which shows the starting postion.
        
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;

    }
};