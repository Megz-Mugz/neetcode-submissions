class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        std::vector<int> left_products;
        std::vector<int> right_products(N, nums[N - 1]);
        std::vector<int> results;

        // // create left to right vector
        for (int i = 0; i < N; i++){
            if (i == 0){
                left_products.push_back(nums[i]);
            } else {
                left_products.push_back(left_products[i - 1] * nums[i]);
            }
        }

        // create right to left vector
        for (int i = N - 1; i >= 0; i--){
            if (i != N - 1){
                right_products[i] = right_products[i + 1] * nums[i];
            } 
        }

        // create results
        // i == 0, just left[i + 1]
        // i == nums.size() - 1, just left[i - 1]
        for (int i = 0; i < N; i++){
            if (i == 0){
                results.push_back(right_products[i + 1]);
            } else if (i == N - 1){
                results.push_back(left_products[i - 1]);
            } else {
                results.push_back(left_products[i - 1] * right_products[i + 1]);
            }
        }

        return results;
    }
};
