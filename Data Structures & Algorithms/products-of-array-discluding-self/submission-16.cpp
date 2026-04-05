class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> left_to_right;
        std::vector<int> right_to_left = nums;
        std::vector<int> resulting_vector;
        
        // compute all the cummulative products going left to right
        for (int i = 0; i < nums.size(); i++){
            if (left_to_right.empty()) {
                left_to_right.push_back(nums[i]);
            } else {
                left_to_right.push_back(left_to_right[i-1] * nums[i]);
            }
        }
        
        // compute all the cummulative products going right to left
        for (int i = nums.size() - 2; i >= 0; i--){
            right_to_left[i] = right_to_left[i] * right_to_left[i+1];
        }
        

        // iterate through nums, & multiply the indices on the left & right of the index 
        for (int i = 0; i < nums.size(); i++){
            if (i == 0){
                resulting_vector.push_back(right_to_left[i+1]);
            } else if (i == nums.size() - 1){
                resulting_vector.push_back(left_to_right[i-1]);
            } else {
                resulting_vector.push_back(left_to_right[i - 1] * right_to_left[i + 1]);
            }
        }

        return resulting_vector;
    }
};
