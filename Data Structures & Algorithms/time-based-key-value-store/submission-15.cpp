class TimeMap {
public:
    // key -> vector [ (value, timestamp), (value, timestamp), (value, timestamp) ]
    using timestamp = int;
    using key_time_store = std::vector< std::pair<std::string, timestamp> >;
    std::unordered_map<std::string, key_time_store> storage;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        

        for (int i = storage[key].size() - 1; i > -1; i--){
            if (storage[key][i].second <= timestamp){
                return storage[key][i].first;
            }
        }

        return "";
    }
};
