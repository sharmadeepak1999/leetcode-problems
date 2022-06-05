class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        
        while(i < path.length()) {
            if(path[i] == '/') {
                while(i < path.length() && path[i] == '/') {
                    i++;
                }
                v.push_back("/");
            } else {
                string op = "";
                
                while(i < path.length() && path[i] != '/') {
                    op += path[i];
                    i++;
                }
                if(op == "..") {
                    v.pop_back();
                    if(v.size() >= 2) {
                        v.pop_back();
                        v.pop_back();   
                    }
                } else if(op == ".") v.pop_back();
                else v.push_back(op);
            }
        }
        
        string cp = "";
        if(v.size() > 2 && v.back() == "/") v.pop_back();
        if(v.size() == 0) cp = "/";
        for(auto s : v) cp += s;
        return cp;
    }
};