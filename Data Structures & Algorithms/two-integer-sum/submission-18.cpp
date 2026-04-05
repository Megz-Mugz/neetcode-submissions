class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> output;
        unordered_map<int, int> num_and_index; // number -> index
        int difference;

        for(int i{}; i < nums.size(); i++){
            difference = target - nums[i];
            auto itr = num_and_index.find(difference);
            if (itr != num_and_index.end()){
                output = {num_and_index[difference], i};
                break;
            } else {
                num_and_index.insert({nums[i], i});
            }
        }

        return output;
    }
};
