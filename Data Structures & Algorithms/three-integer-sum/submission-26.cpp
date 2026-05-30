class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;

        for (int i = 0; i < nums.size(); i++){

            // skip duplicates from i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right){
                
                auto three_sum = nums[i] + nums[left] + nums[right];

                if (three_sum == 0){
                    results.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // avoid duplicates for left ptr
                    while (left < right && nums[left - 1] == nums[left]){
                        left++;
                    }

                    // avoid duplicates for right ptr
                    while (left < right && nums[right + 1] == nums[right]){
                        right--;
                    }

                } else if (three_sum > 0){
                    right--;
                } else {
                    left++;
                }
            }

        }
        return results;
    }
};
