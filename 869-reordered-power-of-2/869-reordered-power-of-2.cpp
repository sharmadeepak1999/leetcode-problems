class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> mp(10, 0);
        while(n > 0) {
            int d = n % 10;
            mp[d]++;
            n /= 10;
        }
        
        string twoPowerStrings[] = {
            "1",
            "2",
            "4",
            "8",
            "16",
            "32",
            "64",
            "128",
            "256",
            "512",
            "1024",
            "2048",
            "4096",
            "8192",
            "16384",
            "32768",
            "65536",
            "131072",
            "262144",
            "524288",
            "1048576",
            "2097152",
            "4194304",
            "8388608",
            "16777216",
            "33554432",
            "67108864",
            "134217728",
            "268435456",
            "536870912",
            "1073741824",
            "2147483648" 
        };
        
        for(auto &s:twoPowerStrings) {
            vector<int> t = mp;
            for(auto &c:s) {
                t[c - '0']--;
            }
            
            bool f = true;
            for(auto &c:t) {
                if(c != 0) f = false;
            }
            
            if(f) return true;
        }
        return false;

    }
};