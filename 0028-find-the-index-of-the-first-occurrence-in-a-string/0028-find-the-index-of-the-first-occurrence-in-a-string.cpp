class Solution {
public:
    int strStr(string haystack, string needle) {
        int haysize = haystack.size();
        int needlesize = needle.size();
        for(int i = 0; i < haysize; i++) {
            int j = 0;
            
            while(haysize - i >= needlesize && j < needlesize && haystack[i + j] == needle[j]) j++;
            
            if(j == needlesize) return i;
        }
        return -1;
    }
};