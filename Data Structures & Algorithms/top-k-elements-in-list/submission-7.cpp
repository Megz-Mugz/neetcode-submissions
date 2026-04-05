using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count up the elements and put them into a hashmap
        unordered_map<int, int> freqOfNums;
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        
        for (const auto& num : nums){
            freqOfNums[num]++;
        }
        // take elements from map & put them into a priority queue of tuples (freq, num)
        // note: use priority queue since it leverages a heap internally
        for (auto& [num, freq] : freqOfNums){
            pq.push({freq, num});
        }

        // pop from the priority queue k times
        while (k > 0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
