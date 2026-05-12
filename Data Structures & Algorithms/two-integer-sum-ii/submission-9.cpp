class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right){
            auto curr_sum = numbers[left] + numbers[right];

            if (curr_sum > target){
                right--;
            } else if (curr_sum < target){
                left++;
            } else {
                // 1 indexed indicies
                return {left + 1, right + 1};
            }
        }

        return {};
    }
};
