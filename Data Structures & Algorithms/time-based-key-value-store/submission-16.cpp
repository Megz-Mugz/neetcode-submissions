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
    
    // brute force linear search O(n)
    // optimal, O(log n)
    string get(string key, int timestamp) {
        
        auto key_storage = storage[key]; // (value, timestamp) 
        int left = 0, right = key_storage.size() - 1;
        int middle{};
        std::string res{};
        int max_time{0};

        while (left <= right){
            middle = (left + right) / 2;
            auto current_pair = key_storage[middle];

            if (current_pair.second <= timestamp && current_pair.second > max_time){
                res = current_pair.first;
                max_time = current_pair.second;
            }

            if (current_pair.second <= timestamp){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return res;
    }
};
