class TimeMap {
public:
    using time = int;
    using value = std::string;
    using value_time_pair = std::pair<value, time>;
    std::unordered_map<std::string, std::vector<value_time_pair>> storage;
    
    TimeMap() {}
    
    // place value & timestamp at the end
    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }
    
    // instead of linear search do this with binary search
    // reduce time complexity from O(n) -> O(log n)
    string get(string key, int timestamp) {
        if (!storage.count(key)) return "";
        if (storage[key].empty()) return "";

        int left = 0, right = storage[key].size() - 1;
        std::size_t middle{};
        std::size_t max_time_seen{};
        std::size_t time_seen {0};
        std::string res{};

        while (left <= right){
            middle = (left + right) / 2;
            time_seen = storage[key][middle].second;

            if (time_seen <= timestamp && time_seen > max_time_seen){
                max_time_seen = time_seen;
                res = storage[key][middle].first;
            } 
            
            if (time_seen > timestamp){
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return res;
    }
};
