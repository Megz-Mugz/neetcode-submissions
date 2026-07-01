class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            how to keep track of most frequent character?

            most_freq_char = 'X' -> 1
            'X' -> 1
            1. insert 'Y' into unordered map
            2. when inserting 'Y', ask yourself is the frequency of 'Y' greater 
            than the frequency of the most_freq_char
            if it is, make the most_freq_char whatever you just inserted

            length of window - frequency of most frequent character <= k
                longest_substring = std::max(longest_substring - ^^ math above)

            if the above is false, remove the character at left pointer from unordered map
            & increase left pointer until true
        */
        int left = 0; 
        int max_frequency = 0;
        std::unordered_map<char, int> frequency_of_chars;
        int longest_substring = 0;

        for (int right = 0; right < s.size(); right++){
            // insert current char into map
            frequency_of_chars[s[right]]++;

            max_frequency = std::max(max_frequency, frequency_of_chars[s[right]]);

            // if more than k letters need to be replaced, alter the left pointer
            while ((right - left + 1) - max_frequency > k){
                frequency_of_chars[s[left]]--;
                left++;
            }

            longest_substring = std::max(longest_substring, (right - left + 1));
        }

        return longest_substring;
    }
};
