class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // [-4, -1, -1, 0, 1, 2]

        int left;
        int right;
        int threeSum;
        vector<vector<int>> result;

        for (int i{}; i < nums.size(); i++){

            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // set left to be 1 ahead of i
            left = i + 1; 
            right = nums.size() - 1;
            
            // basic 2 ptr approach
            while (left < right){
                threeSum = nums[i] + nums[left] + nums[right];

                if (threeSum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    // move pointers accordingly
                    left += 1;
                    right -= 1;

                    // skip duplicate left or right ptr if applicable
                    while (left < right && nums[right] == nums[right + 1]) right -= 1;
                    while (left < right && nums[left] == nums[left - 1]) left += 1;

                } else if (threeSum > 0){
                    right -= 1;
                } else {
                    left += 1;
                }
                
            }
        }

        return result;
    }
};
