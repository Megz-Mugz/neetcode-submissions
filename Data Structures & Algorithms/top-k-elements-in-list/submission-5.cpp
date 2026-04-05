class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToFreq; // num -> freq
        priority_queue<tuple<int, int>> freqOfNums;
        vector<int> res;
        
        // count elements
        for (auto& num : nums){
            numToFreq[num]++;
        }

        // invert map
        for (const auto& [num, freq] : numToFreq){
            freqOfNums.push(make_tuple(freq, num));
        }

        while (k > 0){
            auto topElement = freqOfNums.top();

            auto num = get<1>(topElement);

            res.push_back(num);

            freqOfNums.pop(); // actually remove element
            k--;
        }

        return res;
    }
};
