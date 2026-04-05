class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::priority_queue<std::pair<int, int>> queue;
        std::vector<int> result;

        for (auto& num : nums){
            freq[num]++;    
        }

        for (auto& [number, frequency] : freq){
            queue.push({frequency, number});
        }

        while (k > 0){
            auto freq_and_number_pair = queue.top();
            result.push_back(freq_and_number_pair.second);
            queue.pop(); 
            k--;
        }

        return result;
    }
};
