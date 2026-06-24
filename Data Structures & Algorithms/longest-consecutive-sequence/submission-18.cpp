class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // add numbers from 'nums' to a set

        std::set<int> all_nums;
        int longest_streak = 0;

        for (const auto& num : nums){
            all_nums.insert(num);
        }

        for (const auto& num : all_nums){
            int streak = 0;
            auto curr_num = num;
            while (all_nums.contains(curr_num)){
                streak++;
                curr_num++;
            }

            longest_streak = std::max(longest_streak, streak);
        }

        return longest_streak;
    }
};
