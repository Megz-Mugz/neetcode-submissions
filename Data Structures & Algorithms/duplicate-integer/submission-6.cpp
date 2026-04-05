class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen;

        for (auto& num : nums){
            auto it = seen.find(num);

            if (it != seen.end()){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};