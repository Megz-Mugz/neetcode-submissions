class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int middle{};
        // [5,6,1,2,3,4] & target = 6

        while (left <= right){
            middle = std::floor((static_cast<double>(left + right) / 2));

            // case where middle is equal to target
            if (nums[middle] == target) return middle;

            // left half is sorted
            if (nums[left] <= nums[middle]){
                // target exists within left -> middle
                if (target < nums[middle] && target >= nums[left]){
                    right = middle - 1;
                } else {
                    // target is not between left -> middle
                    left = middle + 1;
                }
            // left half is NOT sorted, but right side IS DEFINITELY sorted
            } else {
                if (target > nums[middle] && target <= nums[right]){
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }

        }
        return -1;
    }
};
