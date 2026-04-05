class Solution {
public:
    int characterReplacement(string str, int k) {

        int longest_substr = 0;
        int left = 0;
        int most_freq_occur_char = 0;
        std::unordered_map<char, int> freq;

        for (int right = 0; right < str.size(); right++){
            // add to the map
            freq[str[right]] += 1; 
            
            // check if the thing we added is now the most freq occuring char
            // leverage the fact that the most freq occuring char only changes upon adding
            most_freq_occur_char = std::max(most_freq_occur_char, freq[str[right]]); 

            while ((right - left + 1) - most_freq_occur_char > k){
                freq[str[left++]] -= 1;
            }

            longest_substr = std::max(longest_substr, right - left + 1);
        }


        return longest_substr;
    }
};
