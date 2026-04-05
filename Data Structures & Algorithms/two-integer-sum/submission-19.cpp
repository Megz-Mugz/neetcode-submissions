class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_and_index; 
        int difference;

        for (int i{}; i < nums.size(); i++){
            difference = target - nums[i];

            auto it = seen_and_index.find(difference);
            
            if (it != seen_and_index.end()){
                return {it->second, i};
            }
        
            seen_and_index[nums[i]] = i;
        }

        return {};
    }
};
