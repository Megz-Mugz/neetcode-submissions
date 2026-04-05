class Solution {
public:
    int findMin(vector<int> &nums) {
        /* since the given array is not sorted, but it's "rotated sorted"
        leverage that fact to try and find the sorted part, once you find the part 
        where nums[left] < nums[right], you know you are in the sorted part, and you can 
        make nums[left] your min value and break out of BST like algo
        */

        int left{}, right{nums.size() - 1};
        int middle{};
        int min_value{nums[left]};

        while (left <= right){
            // in sorted portion, left is most likely the min_value
            // once found u can get out of BST algo
            if (nums[left] < nums[right]) {
                min_value = std::min(min_value, nums[left]);
                break;
            }

            middle = std::floor(static_cast<double>((left + right)) / 2);
            min_value = std::min(nums[middle], min_value);

            // if the "left half" is sorted, you know the min value lies on the right side
            // so you can move left = middle + 1
            if (nums[left] <= nums[middle]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }

        }

        return min_value;
    }
};
