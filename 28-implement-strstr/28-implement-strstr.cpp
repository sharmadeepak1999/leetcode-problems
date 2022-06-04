class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
       for(int i = 0; i < haystack.length(); i++){
           if(haystack[i] == needle[0]){
               int j = i + 1;
               int k = 1;
               while(haystack[j] == needle[k] && j < haystack.length() && k < needle.length()) {
                   j++;
                   k++;
               }
               
               if(k < needle.length()) continue;
               
               return i;
           }
       } 
        return -1;
    }
};