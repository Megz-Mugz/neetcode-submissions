class Solution {
public:
    int longestConsecutive(vector<int>& input_nums) const {
        std::set<int> nums;
        size_t longest_consec_seq = 1;

        // add all the nums to a set
        for (const auto& num : input_nums){
            nums.insert(num);
        }
        
        // iterate through the set of numbers
        for (const auto& num : nums){
            
            auto curr_num = num;
            size_t curr_streak = 1;
            // check to see if the next number is in the set
            // if it is, add to the current streak, & check for a new longest consec. seq
            // on each iteration
            while (nums.contains(curr_num + 1)){
                curr_streak++;
                longest_consec_seq = std::max(longest_consec_seq, curr_streak);
                curr_num++;
            }
        }
        
        // if nums is empty, return 0
        return (input_nums.empty() ? 0 : longest_consec_seq);
    }
};
