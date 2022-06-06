class Solution {
public:
    string reverseWords(string s) {
    /*
        // We can get each word in the string, and store it in a seperate reverser string variable, we will append a space before inserting every word in reverse string, we will also check for leading spaces by checking if word is empty and curr char is a space, then continue, else check if it is a space then add word to the reverse string, else add char to word, at last check if the reverse string contains a leading space, added maybe due to the word addition opperation and remove it.
        string rs = "";
        
        int i = 0;
        string w = "";
        while(i < s.length()) {
            if(w == "" && s[i] == ' ') {
              i++;
              continue;  
            } 
            if(s[i] == ' '){
             rs = ' ' + w + rs;   
             w = "";
            } else w += s[i];
            i++;
        }
        if(w != "") rs = w + rs;
        else rs = rs.substr(1);
        return rs;
    */
        
    // We can also take use of a stack to store all words and then pop them and add to a reverse string variable
        
    // Also, we can first reverse altogether the whole string and then one by one re-reverse each word
        
        reverse(s.begin(), s.end());

        int currAvailIndex = 0;
        int i = 0;
        while(i < s.length()) {
            if(s[i] != ' ') {
                if(currAvailIndex != 0) s[currAvailIndex++] = ' ';
                int j = i;
                while(j < s.length() && s[j] != ' ') s[currAvailIndex++] = s[j++];
                reverse(s.begin() + currAvailIndex - (j - i), s.begin() + currAvailIndex);
                i = j;
            }
            i++;
        }
        s.erase(s.begin() + currAvailIndex, s.end());
        return s;
    }
};