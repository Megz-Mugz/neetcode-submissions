class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_and_index;

        for (int i{}; i < nums.size(); i++){
            size_t diff = target - nums[i];
            if (num_and_index.contains(diff)){
                return {num_and_index[diff], i};
            }
            num_and_index.insert({nums[i], i});
        }

        return {};
    }
};
