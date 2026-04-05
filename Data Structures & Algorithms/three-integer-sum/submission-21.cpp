class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        int i = 0;
        int left;
        int right;
        int total_sum;
        int N = nums.size();
        // nums=[-1,0,1,2,-1,-4]
        // [-4, -1, -1, 0, 1, 2]

        vector<vector<int>> result;

        while (i < N){

            while (i > 0 && nums[i - 1] == nums[i]){
                i++;
            }
            std::cout << "i is now: " << nums[i] << std::endl;

            left = i + 1;
            right = N - 1;

            while (left < right){
                total_sum = nums[left] + nums[i] + nums[right];

                if (total_sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    while (nums[left - 1] == nums[left]) left++;
                    while (nums[right + 1] == nums[right]) right--;
                
                } else if (total_sum > 0){
                    right--;
                } else {
                    left++;
                }

                
            }
            i++;
        }

        return result;
    }
};
