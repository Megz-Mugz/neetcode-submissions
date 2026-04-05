class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, longest_substr = 0, most_freq_letter = 0;
        std::unordered_map<char, int> seen_and_freq;
        
        for (int right = 0; right < s.size(); right++){

            // add s[right] into seen_and_freq
            seen_and_freq[s[right]]++;

            // get the most freq occuring letter in map (keep track of it upon insertion)
            most_freq_letter = std::max(most_freq_letter, seen_and_freq[s[right]]);


            // (right - left + 1) - most_freq_letter > k -> make adjustments
            while ((right - left + 1) - most_freq_letter > k){
                seen_and_freq[s[left]]--;
                left++;
            }

            std::cout << "right: " << right << " left: " << left << " most freq char: " << most_freq_letter << std::endl;
            longest_substr = std::max(longest_substr, right - left + 1);
        }

        return longest_substr;
    }
};
