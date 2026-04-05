class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> occurrences; // num -> freq
        std::priority_queue<std::pair<int, int>> pq; // freq, num
        std::vector<int> res;

        // count number of times the number occurs
        for (const auto& num : nums){
            occurrences[num]++;
        }

        // push nums & freq into priority queue, sorts nums in descending order by freq
        for (const auto& [num, freq] : occurrences){
            pq.push({freq, num});
        }
        
        // keep decrementing k until 0 & add numbers into res vector
        while (k != 0){
            res.push_back(pq.top().second); 
            pq.pop();
            k--;
        }

        return res;
    }
};
