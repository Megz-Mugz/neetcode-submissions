class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;

        for (const auto num : nums){
            if (seen.find(num) == seen.end()){
                seen.insert(num);
            } else {
                return num;
            }
        }

        return -1;
    }
};
