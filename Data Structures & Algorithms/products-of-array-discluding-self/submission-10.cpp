class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftToRight;
        vector<int> rightToLeft(nums.size());
        vector<int> output;

        // print contents from left to right
        for(int i{}; i < nums.size(); i++){
            if (i == 0){
                leftToRight.push_back(nums[i]);
            } else {
                leftToRight.push_back(leftToRight[i - 1] * nums[i]);
            }
        }

        // print contents from right to left
        for(int i = nums.size() - 1; i >= 0; i--){
            if (i == nums.size() - 1){
                rightToLeft[i] = nums[i];
            } else {
                rightToLeft[i] = (nums[i] * rightToLeft[i + 1]);
            }
        }

        // create output array
        for (int i{}; i < nums.size(); i++){
            if (i == 0){
                // pull from i+1 of rightToLeft
                output.push_back(rightToLeft[i + 1]);
            } else if (i == nums.size() - 1){
                // pull from i-1 of leftToRight
                output.push_back(leftToRight[i - 1]);
            } else {
                // normal case, pull from i - 1 of leftToRight and i + 1 of rightToLeft
                output.push_back(leftToRight[i - 1] * rightToLeft[i + 1]);
            }
        }

        return output;
    }
};