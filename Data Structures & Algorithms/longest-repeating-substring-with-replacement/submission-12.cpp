class Solution {
public:
    int characterReplacement(string str, int k) {
        /*
        A -> 3
        B -> 2
        
        most freq occuring char - A
        while size of map (6) - size of most freq occur char (4) > k:
            move left ptr 
        */
        int longest_substr = 0;
        int left = 0;
        std::unordered_map<char, int> freq;

        for (int right = 0; right < str.size(); right++){
            freq[str[right]] += 1;

            while ((right - left + 1) - most_freq_char_occurence(freq) > k){
                freq[str[left++]] -= 1;
            }

            longest_substr = std::max(longest_substr, right - left + 1);
        }


        return longest_substr;
    }

private: 
    int most_freq_char_occurence(const std::unordered_map<char, int>& freq){
        int biggest_num = 0;

        for (auto& [_, val] : freq){
            biggest_num = std::max(biggest_num, val);
        }

        return biggest_num;
    }
};
