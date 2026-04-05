class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> visited;

        for (auto num : nums){
            auto itr = visited.find(num);
            
            if (itr != visited.end()){
                return true;
            } else {
                visited.insert(num);
            }
        }
        return false;
    }
};