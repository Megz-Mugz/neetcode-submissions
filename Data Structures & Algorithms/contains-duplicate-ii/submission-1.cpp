class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        std::unordered_map<int, int> seen; // num in nums -> index

        for (int right = 0; right < nums.size(); right++){

            auto it = seen.find(nums[right]);

            if (it != seen.end() && right - it->second <= k) {
                // some other logic
                return true;
            }
            seen[nums[right]] = right;
        }

        return false;
    }
};