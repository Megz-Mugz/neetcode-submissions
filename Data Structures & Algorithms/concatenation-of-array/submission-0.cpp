class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int N = nums.size();
        std::vector<int> result(N * 2, 0);

        for (int i{}; i < N; i++){
            result[i] = nums[i];
            result[i + N] = nums[i];
        }

        return result;
    }
};