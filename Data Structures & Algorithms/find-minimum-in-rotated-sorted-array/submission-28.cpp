class Solution {
public:
    int findMin(vector<int> &nums) {
        // O(log n) -> instead of linear search, what about binary seaerch?

        /*
            [3,4,5,6,1,2]
            left = 0
            right = 5 

            middle = 2
        
            if nums[left] < nums[right] -> return nums[left]

            else
                check if middle is the min number

                if nums[middle] > nums[left] -> min number is not here, left = middle + 1
                else -> min number is between left and middle, inclusive, right = middle - 1
        */

        int left = 0, right = nums.size() - 1;
        int min_number = nums[0];

        while (left <= right){

            int middle = left + (right - left) / 2;
            
            if (nums[left] <= nums[right]){
                break;
            } else {
                // check if the middle number is the min number
                min_number = std::min(min_number, nums[middle]);

                // if true, you know there is atleast one number not in left -> middle that is LESS THAN any number in this range
                if (nums[middle] >= nums[left]){
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return std::min(min_number, nums[left]);
    }
};