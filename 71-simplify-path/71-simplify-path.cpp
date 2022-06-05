class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        
        while(i < path.length()) {
            if(path[i] != '/') {
                string op = "";
                
                while(i < path.length() && path[i] != '/') {
                    op += path[i];
                    i++;
                }
                if(op == ".." && !v.empty()) {
                    v.pop_back();
                } else if(op != "." && op != ".." && op != "") v.push_back(op);
            }
            i++;
        }
        
        string cp = "";
        if(v.size() == 0) return "/";
        
        for(auto s : v) cp += "/" + s;
        return cp;
    }
};