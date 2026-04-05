class TimeMap {
public:
    
    std::unordered_map<std::string, std::vector<std::pair<std::string, int> >> storage;
    
    TimeMap() {}
    
    // place value & timestamp at the end
    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }
    

    string get(string key, int timestamp) {
        
        std::string res{};
        for (auto [value, time] : storage[key]){
            if (time <= timestamp) res = value;
        }
        return res;
    }
};
