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

        // invert map & push to priority queue
        for (const auto& [num, freq] : numToFreq){
            freqOfNums.push(make_tuple(freq, num));
        }

        // push 'k' elements into the results vector
        while (k > 0){
            auto topElement = freqOfNums.top(); // get the root of the heap
            res.push_back(get<1>(topElement));
            freqOfNums.pop(); // actually remove element
            k--;
        }

        return res;
    }
};
