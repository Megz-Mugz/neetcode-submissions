class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_consec_seq = 0;
        std::set<int> uniq_nums;

        // put nums in a set, so we can have O(1) lookup
        for (const auto& num : nums){
            uniq_nums.insert(num);
        }

        // for each num in uniq_nums, check how many
        // consec nums are in the set
        for (const auto& num : uniq_nums){
            auto curr_num = num;
            int curr_seq_len = 0;
            
            while (uniq_nums.contains(curr_num)){
                // update streak & place on next consec num
                curr_seq_len++;
                curr_num++;
            }
            
            // update longest_consec_seq accordingly, once streak has ended
            longest_consec_seq = std::max(longest_consec_seq, curr_seq_len);
        }

        return longest_consec_seq;
    }
};
