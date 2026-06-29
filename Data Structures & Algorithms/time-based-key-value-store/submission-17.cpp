class TimeMap {
private:
    using key = string;
    using value = string;
    using timestamp = int;

    std::unordered_map<key, std::vector<std::pair<value, timestamp>>> storage;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // use emplace_back since it constructs a pair for you
        storage[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        // Guard rail - if key doesn't have any set values, return an empty string
        if (storage[key].size() == 0) return "";

        int left = 0;
        int right = storage[key].size() - 1;
        string most_recent_key = "";

        while (left <= right){
            int middle = left + (right - left) / 2;

            // ensure that timestamp at middle <= timestamp
            if (storage[key][middle].second > timestamp){
                right = middle - 1;
            } else {
                most_recent_key = storage[key][middle].first;
                left = middle + 1;
            }
        }

        return most_recent_key;
    }
};
