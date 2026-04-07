class Solution {
public:
    int longestConsecutive(vector<int>& input_nums) {
        std::set<int> nums;
        size_t longest_consec_seq = 1;

        for (const auto& num : input_nums){
            nums.insert(num);
        }
        
        for (const auto& num : nums){
            auto curr_num = num;
            size_t curr_streak = 1;
            while (nums.contains(curr_num + 1)){
                curr_streak++;
                longest_consec_seq = std::max(longest_consec_seq, curr_streak);
                curr_num++;
            }
        }


        

        return (input_nums.empty() ? 0 : longest_consec_seq);
    }
};
