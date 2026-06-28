class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // left and right pointers for binary search
        int left = 0;
        int right = nums.size() - 1;
        constexpr size_t NUMBER_NOT_FOUND = -1;

        while (left <= right){
            // middle calculation to handle integer overflow
            int middle = left + (right - left) / 2;
            
            // check if middle index equals target, return that index accordingly
            if (nums[middle] == target) return middle;

            // handle situation that left to middle index is sorted
            if (nums[middle] >= nums[left]){
                // check if the target number is between left & middle index
                if (target < nums[middle] && target >= nums[left]){
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            // in the case of left to middle is unsorted, handle it accordingly
            } else {
                // check if the target number is between middle & right index
                if (target > nums[middle] && target <= nums[right]){
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return NUMBER_NOT_FOUND;
    }
};
