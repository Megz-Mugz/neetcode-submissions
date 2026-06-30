class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longest_sub_str = 0;
        int left_ptr = 0;
        std::unordered_set<int> letters;

        for (int right_ptr{}; right_ptr < s.size(); right_ptr++){
            
            while (letters.contains(s[right_ptr])){
                if (left_ptr < right_ptr){
                    letters.erase(s[left_ptr]);
                    left_ptr++;
                }
            } 
            // once letter is found to not be a duplicate, add it to the set
            letters.insert(s[right_ptr]);
            longest_sub_str = std::max(longest_sub_str, 
                                        static_cast<int>(letters.size()));
        }

        return longest_sub_str;
    }
};