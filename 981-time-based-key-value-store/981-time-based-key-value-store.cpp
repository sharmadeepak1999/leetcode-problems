class TimeMap { 
public:
    unordered_map<string, pair<unordered_map<int, string>, vector<int>>> timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].first.insert({timestamp, value});
        timemap[key].second.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(timemap[key].first.find(timestamp) == timemap[key].first.end()) {
            vector<int> &arr = timemap[key].second;
            int lo = 0, hi = arr.size() - 1, mid, prevLargeIndex = -1;
            while(lo <= hi) {
                mid = (lo + hi) / 2;
                if(arr[mid] == timestamp) return timemap[key].first[timestamp];
                else if(arr[mid] < timestamp) {
                  lo = mid + 1;  
                  prevLargeIndex = mid;
                } else hi = mid - 1;
            }
            return prevLargeIndex == -1 ? "" : timemap[key].first[arr[prevLargeIndex]];
        }
        return timemap[key].first[timestamp];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */