class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> valid_triplets;

        // go from the start of the vector till the 2nd to last element
        for (int i = 0; i < nums.size() - 1; i++){
            
            // avoid duplicate's of the current 
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // start just after 'i' and at the end of nums
            int left = i + 1, right = nums.size() - 1;

            // two pointer approach
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
                    
                    // move both pointers with respect to left < right to avoid checking duplicate left
                    while (left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    // move both pointers with respect to left < right to avoid checking duplicate right
                    while (left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
            }
        }

        return valid_triplets;
    }
};
