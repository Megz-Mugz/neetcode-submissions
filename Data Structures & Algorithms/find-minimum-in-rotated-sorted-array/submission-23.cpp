class Solution {
public:
    int findMin(vector<int> &nums) {
        // check if middle is min first
        // if left < right, return left
        // [1, 2, 3, 4, 5, 6]
        // [4, 5, 6, 1, 2, 3]
            // either left < middle or middle < right

        int left{0}, right{nums.size() - 1};
        int middle{};
        int min_val = nums[0];

        while (left <= right){

            if (nums[left] < nums[right]){
                min_val = std::min(min_val, nums[left]);
                break;
            } 

            middle = std::floor(static_cast<double>((left + right)) / 2);
            // check if the middle value is the min
            min_val = std::min(min_val, nums[middle]);

            if (nums[left] <= nums[middle]){ // smaller numbers are on the other half 
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return min_val;
    }
};
