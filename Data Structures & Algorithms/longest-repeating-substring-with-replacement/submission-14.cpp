class Solution {
public:
    int characterReplacement(string str, int k) {

        int left = 0, most_freq_occur_char = 0, longest_substr = 0;
        std::unordered_map<char, int> freq;

        for (int right = 0; right < str.size(); right++){
            // add to the map
            freq[str[right]] += 1; 
            
            // check if the thing we added is now the most freq occuring char
            // leverage the fact that the most freq occuring char only changes upon adding
            most_freq_occur_char = std::max(most_freq_occur_char, freq[str[right]]); 

            // window of letters - most freq occur char > k, if this is true, adjust till <= k
            while ((right - left + 1) - most_freq_occur_char > k){
                freq[str[left++]] -= 1;
            }
            
            // check if newly altered window is the longest substr
            longest_substr = std::max(longest_substr, right - left + 1);
        }


        return longest_substr;
    }
};
