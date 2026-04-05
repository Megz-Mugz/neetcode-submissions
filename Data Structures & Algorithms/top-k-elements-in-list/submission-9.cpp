class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> occurrences; // num -> freq
        std::priority_queue<std::pair<int, int>> pq; // num -> freq
        std::vector<int> res;

        for (const auto& num : nums){
            occurrences[num]++;
        }

        for (const auto& [num, freq] : occurrences){
            pq.push({freq, num});
        }

        while (k){
            res.push_back(pq.top().second); 
            pq.pop();
            k--;
        }

        return res;
    }
};
