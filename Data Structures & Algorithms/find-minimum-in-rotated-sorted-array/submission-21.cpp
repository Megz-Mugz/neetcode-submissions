class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle{};

        int minNumber = nums[left];
        // [5, 1, 2, 3, 4]

        while (left < right){

            middle = std::floor((left + right) / 2);

            minNumber = std::min(minNumber, nums[middle]);

            // take first iteration of this: [3,4,5,6,1,2]
            // if nums[middle] > nums[right], then you know you have a lesser value closer to the right index
            if (nums[middle] > nums[right]){
                left = middle + 1;
            } else {
                // take first iteration of this: [5, 1, 2, 3, 4]
                // if middle is less than right, ur min value is closer to middle index
                right = middle - 1;
            }

        }

        minNumber = std::min(minNumber, nums[left]);
        
        return minNumber;
    }
};
