class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<uint16_t, uint16_t> seen; // num -> index
        uint16_t difference{0};
        for (int i{}; i < nums.size(); i++){
            
            difference = target - nums[i];

            if (seen.contains(difference)){
                return {seen[difference], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
