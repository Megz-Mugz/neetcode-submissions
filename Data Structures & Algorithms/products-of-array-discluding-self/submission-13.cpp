class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int NUM_SIZE = nums.size();
        std::vector<int> left_to_right, right_to_left(NUM_SIZE), result;

        // cummulative product left to right
        for (int i{}; i < NUM_SIZE; i++){
            if (i == 0) {
                left_to_right.push_back(nums[i]);
                continue;
            }
            left_to_right.push_back(left_to_right[i - 1] * nums[i]);
        }

        // cummulative product going right to left
        for (int i = NUM_SIZE - 1; i >= 0; i--){
            if (i == NUM_SIZE - 1) {
                right_to_left[i] = nums[i];
                continue;
            }
            right_to_left[i] = right_to_left[i + 1] * nums[i];
        }

        // ignore the ith position, unless at beginning or end, and multiy the i-1 & i + 1 & push back into result vector
        for (int i = 0; i < NUM_SIZE; i++){
            if (i == 0){
                result.push_back(right_to_left[i + 1]);
            } else if (i == NUM_SIZE - 1){
                result.push_back(left_to_right[i - 1]);
            } else {
                result.push_back(left_to_right[i - 1] * right_to_left[i + 1]);
            }
        }


        return result;
    }
};
