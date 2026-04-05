class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        int streak = 0;
        int curr_num = 0;
        int longest_sequence = 0;

        for (auto& num : nums){
            nums_set.insert(num);
        }

        for (auto& num : nums_set){

            streak = 1;
            curr_num = num + 1;

            while (nums_set.find(curr_num) != nums_set.end()){
                streak += 1;
                curr_num += 1;
            }

            longest_sequence = std::max(streak, longest_sequence);
        }
        


        return longest_sequence;
    }
};
