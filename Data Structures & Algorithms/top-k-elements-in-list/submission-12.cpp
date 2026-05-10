class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map w/ num -> freq
        std::unordered_map<int, int> num_count;
        std::priority_queue<std::pair<int, int>> pq;
        std::vector<int> k_most_freq;
        
        // count frequency of the numbers
        for (const auto& num : nums){
            num_count[num]++;
        }

        // push the freq & num into priority queue (max-heap) with focus on frequency
        for (const auto& [num, freq] : num_count){
            pq.push({freq, num});
        }

        // add k many elements to vector, .second indicates the number, not the frequency
        while (k != 0){
            k_most_freq.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return k_most_freq;
    }
};
