class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longest_string_len = 0;
        int left = 0;
        int max_letter_count = 0;
        std::unordered_map<char, int> letter_to_freq;

        for (int right{}; right < s.size(); right++){
            // increase the frequency of the letter we saw
            letter_to_freq[s[right]]++;
            // check if current letter is our new most seen letter
            max_letter_count = std::max(max_letter_count, letter_to_freq[s[right]]);

            // if we exceeded max character replacement, slide left ptr
            while ((right - left + 1) - max_letter_count > k){
                // reduce frequency of left most letter
                letter_to_freq[s[left]]--;
                
                // move left ptr
                left++;
            }

            // check if new valid substring's length is greater than previous valid substring len
            longest_string_len = std::max(longest_string_len, (right - left + 1));

        }

        return longest_string_len;
    }
};
