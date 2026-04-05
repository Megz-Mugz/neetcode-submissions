class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle{};

        int minNumber = nums[left];

        while (left < right){

            middle = std::floor((left + right) / 2);

            minNumber = std::min(minNumber, nums[middle]);

            if (nums[middle] > nums[right]){
                left = middle + 1;
            } else {
                right = middle;
            }

        }

        minNumber = std::min(minNumber, nums[left]);
        
        return minNumber;
    }
};
