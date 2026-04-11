class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> valid_triplets;

        for (int i = 0; i < nums.size(); i++){
            
            // avoid duplicate's of the current 
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1, right = nums.size() - 1;

            while (left < right){

                auto sum = nums[left] + nums[i] + nums[right];

                if (sum > 0){
                    right--;
                
                } else if (sum < 0){
                    left++;
                
                } else if (sum == 0) {
                    
                    valid_triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // move both pointers with respect to left < right
                    while (left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    // move both pointers with respect to left < right
                    while (left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
            }
        }

        return valid_triplets;
    }
};
